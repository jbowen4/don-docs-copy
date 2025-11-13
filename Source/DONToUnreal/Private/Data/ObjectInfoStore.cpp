// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/ObjectInfoStore.h"

#include "Util/Types/TOptRef.h"

FObjectInfoStoreBuilder FObjectInfoStore::Builder()
{
	return FObjectInfoStoreBuilder();
}

FObjectInfoStoreCopyBuilder FObjectInfoStore::CopyBuilder(const FObjectInfoStore& CopyFrom)
{
	return FObjectInfoStoreCopyBuilder(CopyFrom);
}

TOptRef<const FObjectInfo> FObjectInfoStore::Get(const FName& Name) const
{
	auto gotten = getUnchecked(Name);
	if (gotten == nullptr)
		return TOptRef<const FObjectInfo>();

	return TOptRef<const FObjectInfo>(*gotten);
}

void FObjectInfoStore::Keys(TArray<FName>& Out) const
{
	this->objects.GetKeys(Out);
}


FObjectInfoStore::FObjectInfoStore()
	: Origin(FObjectInfo::ORIGIN)
{
}

FObjectInfoStore::FObjectInfoStore(const FObjectInfo& Origin)
	: Origin(Origin)
{
}

FObjectInfoStore::FObjectInfoStore(const FObjectInfoStore& copyFrom)
	: Origin(copyFrom.Origin), objects(copyFrom.objects)
{
	// Fix parent pointers to point to locations in the new map. Shouldn't need to modify nest indices.
	for (const TPair<FName, FObjectInfo>& name_object : copyFrom.objects)
	{
		const FObjectInfo& object = name_object.Value;
		object.parent.IfPresent([&object, &copyFrom](const FObjectInfo& parent)
		{
			TOptRef<const FObjectInfo> parentInNewMap = copyFrom.Get(parent.GetName());
			if (parentInNewMap.IsAbsent()) // if parent doesn't exist in old map
				UE_LOG(LogCore, Fatal, TEXT("Illegal state: object '%ls' references parent '%ls' that does not exist in FObjectInfoStore."), *FName::SafeString(object.GetName().GetDisplayIndex()), *FName::SafeString(parent.GetName().GetDisplayIndex()));

			// I get why the PAIR can't be modified, but the value still needs to be modifiable
			const_cast<FObjectInfo&>(object).parent = parentInNewMap;
		});
	}
}

FObjectInfo* FObjectInfoStore::getUnchecked(const FName& Name) const
{
	return const_cast<FObjectInfo*>(this->objects.Find(Name));
}


FString FObjectInfoStore::ToString() const
{
	FString outString;
	/// TODO use FStringBuilder
	for (auto& element : objects)
	{
		outString += element.Value.ToString();
		outString += "\n";
	}

	return outString;
}
