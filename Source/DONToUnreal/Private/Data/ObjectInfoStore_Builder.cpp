#include "Data/ObjectInfoStore.h"


int32 FObjectInfoStore::Size() const
{
	return objects.Num();
}

void FObjectInfoStoreBuilder::AddObject(const FObjectInfo& ToCopy)
{
	AddObject(
		ToCopy.GetName(),
		ToCopy.GetParent().MapOwned<FName>([](auto& it) { return it.GetName(); }),
		ToCopy.GetRelativePos(),
		ToCopy.GetOrientation(),
		ToCopy.IsVisible()
	);
}

int32 FObjectInfoStoreBuilder::Size() const
{
	return toAdd.Num();
}


//region Base Builder
FObjectInfoStoreBuilder::FObjectInfoStoreBuilder()
	: origin(FObjectInfo::ORIGIN)
{
}


void FObjectInfoStoreBuilder::AddObject(const FName& Name, const TOptional<FName>& ParentName,
                                        const FVector& Position, const FQuat& Orientation, const bool Visibility)
{
	FObjectInfoTmp& slot = toAdd.FindOrAdd(Name);
	slot = FObjectInfoTmp(Name, ParentName, Position, Orientation, Visibility);
}

USE_RET bool FObjectInfoStoreBuilder::SetOrigin(const FObjectInfo& Origin)
{
	if (Origin.GetParent().IsPresent())
		return false;
	this->origin = Origin;
	return true;
}


bool FObjectInfoStoreBuilder::Contains(const FName& Name) const
{
	return Name.IsEqual(origin.GetName(), ENameCase::CaseSensitive)
		|| this->toAdd.Contains(Name);
}

/**
 * What we do is we first just associate all of the FNames with completely empty FObjectInfos, 
 *  so we get all of the hashing and reorganizing out of the way.
 * Now that we have a map that will never change, we can save pointers within the map. 
 * However, even though we can get the pointers,
 *	we still need to add parents before children so the children can get the right NestIndex.
 */
void FObjectInfoStoreBuilder::Build(FObjectInfoStore& out)
{
	if (toAdd.IsEmpty())
	{
		throw std::runtime_error("Attempted to call Build with no object information, or attempted to call it twice.");
	}

	UE_LOG(LogCore, Log, TEXT("Building an instance of ObjectInfoStore"));
	out = FObjectInfoStore();
	out.Origin = origin;

	auto& outMap = out.objects;
	outMap.Reserve(toAdd.Num());

	// add blanks for the entire list to preallocate the map
	for (TPair<FName, FObjectInfoTmp>& add : toAdd)
	{
		if (add.Key.IsEqual(origin.GetName())) // we handle the origin through SetOrigin
			continue;

		outMap.Add(add.Key);
	}

	// Force the map to have exactly this size. the map should never change size from here, so we should never invalidate ptrs from here.
	outMap.Compact();

	TArray<FObjectInfoTmp> needsParentsAdded;
	needsParentsAdded.Reserve(toAdd.Num());

	// Now go back through and add all elements
	while (!toAdd.IsEmpty() || !needsParentsAdded.IsEmpty())
	{
		if (needsParentsAdded.IsEmpty())
		{
			FObjectInfoTmp found;
			toAdd.RemoveAndCopyValue(toAdd.begin().Key(), found);

			needsParentsAdded.Push(MoveTempIfPossible(found));
			continue;
		}

		auto& itemToAdd = needsParentsAdded.Top();
		if (origin.GetName().IsEqual(itemToAdd.Name, ENameCase::CaseSensitive))
		{
			UE_LOG(LogCore, Warning, L"[FObjectInfoStoreBuilder#Build] Origin provided as a member.");
			continue; // we handle the origin through SetOrigin
		}

		if (!itemToAdd.ParentName.IsSet() || origin.GetName().IsEqual(itemToAdd.ParentName.GetValue(), ENameCase::CaseSensitive)) // add plain if it'll be a child of the origin
		{
			outMap[itemToAdd.Name] = FObjectInfo(itemToAdd.Name, itemToAdd.Visibility, TOptRef<const FObjectInfo>(out.Origin), itemToAdd.Position, itemToAdd.Orientation);
			needsParentsAdded.Pop();
			continue;
		}

		// make sure its parent is registered first
		FName& parentName = itemToAdd.ParentName.GetValue();
		FObjectInfo* parentRegistered = outMap.Find(parentName);
		if (parentRegistered == nullptr) // parent doesn't exist
		{
			UE_LOG(LogCore, Fatal, TEXT("Could not find parent '%ls' for ObjectInfo '%ls'"), *FName::SafeString(parentName.GetDisplayIndex()), *FName::SafeString(itemToAdd.Name.GetDisplayIndex())); // TODO use non-destructive error handling
			return;
		}

		if (parentRegistered->IsOrigin()) // parent hasn't been initialized, so initialize it first
		{
			FObjectInfoTmp parentFromAdd;
			if (!toAdd.RemoveAndCopyValue(parentName, parentFromAdd))
				throw std::bad_exception(); // we allocated the parent already but it wasn't in the toAdd list?

			needsParentsAdded.Push(parentFromAdd);
			continue;
		}

		outMap[itemToAdd.Name] = FObjectInfo(itemToAdd.Name, itemToAdd.Visibility, TOptRef<const FObjectInfo>(parentRegistered), itemToAdd.Position, itemToAdd.Orientation);
		needsParentsAdded.Pop();
	}
}

//endregion Base Builder

//region Copy Builder
/**
 * Add everything from the original store to this builder, to potentially be overwritten by calls to @link UpdateInfo@endlink later.
 */
FObjectInfoStoreCopyBuilder::FObjectInfoStoreCopyBuilder(const FObjectInfoStore& CopyFrom)
{
	toAdd.Reserve(CopyFrom.objects.Num());
	for (const TPair<FName, FObjectInfo>& name_info : CopyFrom.objects)
	{
		auto& info = name_info.Value;

		AddObject(info);
	}
	bool wasValidOrigin = SetOrigin(CopyFrom.GetOrigin());
	if (!wasValidOrigin)
		throw std::bad_exception(); // this shouldn't happen
}

bool FObjectInfoStoreCopyBuilder::UpdateInfo(
	const FName& Name, const TOptRef<TOptional<FName>> ParentName,
	const TOptRef<const FVector> Position, const TOptRef<const FQuat> Orientation,
	TOptional<bool> Visibility
)
{
	auto _infoToAdd = toAdd.Find(Name);
	if (_infoToAdd == nullptr)
	{
		return false;
	}
	FObjectInfoTmp& infoToAdd = *_infoToAdd;

	ParentName.IfPresent([&infoToAdd](auto& nameOpt) { infoToAdd.ParentName = nameOpt; });
	Position.IfPresent([&infoToAdd](auto& pos) { infoToAdd.Position = pos; });
	Orientation.IfPresent([&infoToAdd](auto& or) { infoToAdd.Orientation = or; });
	if (Visibility.IsSet())
	{
		infoToAdd.Visibility = Visibility.GetValue();
	}
	return true;
}


// endregion Copy Builder
