#if WITH_DEV_AUTOMATION_TESTS

#include "MyBlueprintItemDragDropAction.h"
#include "Data/ObjectInfoStore.h"
#include "Misc/AutomationTest.h"
#include "Tests/TestUtils/TestUtils.h"


BEGIN_DEFINE_SPEC(FObjectInfoStoreSpec, "Data.State.ObjectInfoStore", EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter);
	using Bldr = FObjectInfoStoreBuilder;
	using CpBldr = FObjectInfoStoreCopyBuilder;
	using InfoStore = FObjectInfoStore;
	using Info = FObjectInfo;


	const FObjectInfo Sun = FObjectInfo(FName(TEXT("Sun")), true, TOptRef<const FObjectInfo>(), FVector(0, 0, 0), FQuat(0));
	const FObjectInfo Earth = FObjectInfo(FName(TEXT("Earth")), true, Sun, FVector(30, 0, 12), FQuat(0));
	const FObjectInfo Moon = FObjectInfo(FName(TEXT("Moon")), true, Earth, FVector(20, 0, 0), FQuat(0));
	const FObjectInfo Mars = FObjectInfo(FName(TEXT("Mars")), true, Sun, FVector(10, 40, 40), FQuat(0));

	/**
	 * @return number of test objects added
	 */
	int addBaselineObjects(Bldr& bldr) const
	{
		bldr.AddObject(Sun.GetName(), TOptional<FName>(), Sun.GetRelativePos(), Sun.GetOrientation(), Sun.IsVisible());
		bldr.AddObject(Earth.GetName(), Earth.GetParent().GetPtrOrNull()->GetName(), Earth.GetRelativePos(), Earth.GetOrientation(), Earth.IsVisible());
		bldr.AddObject(Moon.GetName(), Moon.GetParent().GetPtrOrNull()->GetName(), Moon.GetRelativePos(), Moon.GetOrientation(), Moon.IsVisible());
		bldr.AddObject(Mars.GetName(), Mars.GetParent().GetPtrOrNull()->GetName(), Mars.GetRelativePos(), Mars.GetOrientation(), Mars.IsVisible());

		return 4;
	}

	InfoStore makeDefaultStore() const
	{
		Bldr bl = FObjectInfoStore::Builder();
		addBaselineObjects(bl);
		return bl.Build();
	}

	bool DeepTestEqual(const FString& msg, const FObjectInfo& actual, const FObjectInfo& expected)
	{
		bool wereEqual = TestEqual("Names", actual.GetName(), expected.GetName())
			&& TestEqual("Parent Names", actual.GetParent().MapOwned<const FName>([](auto& it) { return it.GetName(); }), expected.GetParent().MapOwned<const FName>([](auto& it) { return it.GetName(); }))
			&& TestEqual("IsVisible", actual.IsVisible(), expected.IsVisible())
			&& TestEqual("Positions", actual.GetRelativePos(), expected.GetRelativePos())
			&& TestEqual("Nest Index", actual.GetNestIndex(), expected.GetNestIndex())
			&& TestEqual("Orientation", actual.GetOrientation(), expected.GetOrientation());

		AddErrorIfFalse(wereEqual, msg);
		return wereEqual;
	}


	DECLARE_TEST_UTILS

END_DEFINE_SPEC(FObjectInfoStoreSpec);


#define safeGetBlock(variableName, reference) \
	auto ___##variableName = reference; \
	RequireTrue(###reference ## " is present", ___##variableName.IsPresent()); \
	auto& variableName = ___##variableName.GetUnchecked();

#define checkObjectsEqual(_objName) { \
	safeGetBlock(_objName##_var, store.Get(_objName.GetName()))\
	DeepTestEqual(###_objName ## "s equal", _objName##_var, _objName);\
}

void FObjectInfoStoreSpec::Define()
{
	Describe("AAAAA Testing Functions", [this] // just make sure the testing functions work as intended
	{
		It("addBaselineObjects", [this]
		{
			Bldr bldr = FObjectInfoStore::Builder();
			int numAdded = addBaselineObjects(bldr);
			auto store = bldr.Build();

			TestEqual("Returns number of items added", numAdded, store.Size());
			TArray<ObjID> keys = store.Keys();
			auto expectedKeys = TArray{Sun.GetName(), Earth.GetName(), Moon.GetName(), Mars.GetName()};
			TestContentsEqual_Unordered(keys, expectedKeys);

			checkObjectsEqual(Sun)
			checkObjectsEqual(Earth)
			checkObjectsEqual(Moon)
			checkObjectsEqual(Mars)
		});
	});
	Describe("BBBBB Main Struct", [this]
	{
		Describe("Get", [this]
		{
			It("Returns correct object when key is present", [this]
			{
				InfoStore ois = makeDefaultStore();
				TOptRef<const FObjectInfo> _info = ois.Get(Earth.GetName());

				RequireTrue("Is present", _info.IsPresent());

				safeGetBlock(info, _info)

				TestEqual("Returns expected object", info, Earth);
				safeGetBlock(parent, info.GetParent());
				safeGetBlock(otherParent, ois.Get(Sun.GetName()))
				TestEqual("Parent is IN THIS OIS INSTANCE", &parent, &otherParent);
			});
			It("Returns empty when key is absent", [this]
			{
				InfoStore ois = makeDefaultStore();
				TOptRef<const FObjectInfo> _info = ois.Get(FName(TEXT("something else")));
				RequireTrue("Return value is empty", _info.IsAbsent());
			});
			It("Can get based on new FName and not just exact reference", [this]
			{
				auto store = makeDefaultStore();
				auto _earth = store.Get(FName(TEXT("Earth")));
				RequireTrue("Return value exists", _earth.IsPresent());
				TestEqual("Returns correct value", _earth.GetUnchecked(), Earth);
			});
		});
		Describe("Keys", [this]
		{
			It("Returns names of added objects", [this]
			{
				FObjectInfoStore store = makeDefaultStore();
				TArray<ObjID> actual = store.Keys();
				TArray<FName> expected{Sun.GetName(), Earth.GetName(), Moon.GetName(), Mars.GetName()};
				TestContentsEqual_Unordered(actual, expected);
			});
		});
		Describe("Size", [this]
		{
			It("Returns number of objects in store", [this]
			{
				Bldr bldr = FObjectInfoStore::Builder();
				int numAdded = addBaselineObjects(bldr);
				FObjectInfoStore store = bldr.Build();
				TestEqual("Returns correct number", store.Size(), numAdded);
			});
		});
		xDescribe("Copy Constructor", [this]
		{
			It("Copies all values and updates positions to new map", [this]
			{
				// each item is identical to the one from the previous map save for the pointer
				// has all keys of the original
				// has the same values as the original

				const InfoStore original = makeDefaultStore();
				InfoStore newStore(original);
				TestEqual("Same size as original", newStore.Size(), original.Size());
				auto originalKeys = original.Keys();
				TArray<ObjID> expected = newStore.Keys();
				TestContentsEqual_Unordered(originalKeys, expected);
				for (FName name : originalKeys)
				{
					TOptRef<const FObjectInfo> _fromCopied = newStore.Get(name);
					RequireTrue("New store has " + name.ToString(), _fromCopied.IsPresent());

					const FObjectInfo& fromCopied = _fromCopied.GetUnchecked();
					TestEqual(name.ToString() + " objects have equal data", fromCopied, original.Get(name).GetOrThrow());
					fromCopied.GetParent().IfPresent([this, &newStore, &original](const FObjectInfo& parent)
					{
						TestNotEqual("Parent doesn't point to old map", &parent, original.Get(parent.GetName()).GetPtrOrNull());
						TestEqual("Parent points to new map", &parent, newStore.Get(parent.GetName()).GetPtrOrNull());
					});
				}
			});
		});
	});
	Describe("CCC Build from scratch (Builder)", [this]
	{
		It("Default Constructor does not add values", [this]
		{
			Bldr builder = FObjectInfoStore::Builder();
			builder.AddObject(Sun);
			TestEqual("Only one object in builder", builder.Size(), 1);
			FObjectInfoStore out = builder.Build();
			TestEqual("Only one object in store", out.Size(), 1);
		});
		Describe("AddObject", [this]
		{
			It("Adds objects to output info store", [this]
			{
				Bldr builder = FObjectInfoStore::Builder();
				int numAdded = addBaselineObjects(builder);
				FObjectInfoStore out = builder.Build();
				TestEqual("Has expected number of objects", out.Size(), numAdded);
			});
			It("Adding a name twice overwrites the previous entry for that name.", [this]
			{
				Bldr builder = FObjectInfoStore::Builder();

				FObjectInfo newSun = FObjectInfo(Sun.GetName(), false, TOptRef<const FObjectInfo>(), FVector(4, 5, 6), FQuat(4, 5, 6, 7));
				builder.AddObject(Sun);
				builder.AddObject(newSun);
				TestEqual("Only one object in builder", builder.Size(), 1);
				FObjectInfoStore out = builder.Build();
				TestEqual("Only one object in store", out.Size(), 1);
				safeGetBlock(outSun, out.Get(Sun.GetName()))
				TestEqual("Object is the second-added", outSun, newSun);
			});
			It("Adding FObjectInfo is equivalent to adding raw data", [this]
			{
				Bldr bldr = FObjectInfoStore::Builder();
				bldr.AddObject(FName(TEXT("Foo")), TOptional<FName>(), FVector(0, 1, 2), FQuat(3, 4, 5, 6), true);
				auto store = bldr.Build();
				safeGetBlock(indivSunObj, store.Get(FName(TEXT("Foo"))));

				Bldr bldr2 = FObjectInfoStore::Builder();
				bldr2.AddObject(FObjectInfo(FName(TEXT("Foo")), true, TOptRef<const FObjectInfo>(), FVector(0, 1, 2), FQuat(3, 4, 5, 6)));
				auto store2 = bldr2.Build();
				auto objSunObj = store2.Get(FName(TEXT("Foo")));

				RequireTrue("Sun object exists", objSunObj.IsPresent());
				TestEqual("Objects have same data", objSunObj.GetUnchecked(), indivSunObj);
			});
		});
		Describe("Build", [this]
		{
			// TODO
		});
	});
	Describe("DDD Build from other (CopyBuilder)", [this]
	{
		Describe("UpdateInfo", [this]
		{
			It("Overlays data for existing objects", [this]
			{
				auto defstore = makeDefaultStore();
				CpBldr copyBuilder = FObjectInfoStore::CopyBuilder(defstore);
				RequireTrue("Object already exists in store", copyBuilder.UpdateInfo(Earth.GetName(), TOptRef<TOptional<FName>>(), TOptRef<const FVector>(FVector(777,888,999)), TOptRef<const FQuat>(), TOptional<bool>(false)));
				auto newStore = copyBuilder.Build();
				auto _fromNewStore = newStore.Get(Earth.GetName());
				RequireTrue("Modified value exists in new store", _fromNewStore.IsPresent());
				auto& fromNewStore = _fromNewStore.GetUnchecked();

				TestEqual("Updated object has same name", fromNewStore.GetName(), Earth.GetName());
				TestEqual("Updated object has old parent", fromNewStore.GetParent().ToOwned(), Earth.GetParent().ToOwned());
				TestEqual("Updated object has new position", fromNewStore.GetRelativePos(), FVector(777, 888, 999));
				TestEqual("Updated object has old orientation", fromNewStore.GetOrientation(), Earth.GetOrientation());
				TestEqual("Updated object has new visibility", fromNewStore.IsVisible(), false);
			});
			It("Overlays data for existing objects 2", [this]
			{
				auto defstore = makeDefaultStore();
				CpBldr copyBuilder = FObjectInfoStore::CopyBuilder(defstore);
				RequireTrue("Object already exists in store", copyBuilder.UpdateInfo(Earth.GetName(), TOptRef<TOptional<FName>>(TOptional<FName>()), TOptRef<const FVector>(), TOptRef<const FQuat>(FQuat(9,8,7,6)), TOptional<bool>()));
				auto newStore = copyBuilder.Build();
				auto _fromNewStore = newStore.Get(Earth.GetName());
				RequireTrue("Modified value exists in new store", _fromNewStore.IsPresent());
				auto& fromNewStore = _fromNewStore.GetUnchecked();

				TestEqual("Updated object has same name", fromNewStore.GetName(), Earth.GetName());
				TestEqual("Updated object has new parent", fromNewStore.GetParent(), TOptRef(newStore.GetOrigin()));
				TestEqual("Updated object has old position", fromNewStore.GetRelativePos(), Earth.GetRelativePos());
				TestEqual("Updated object has new orientation", fromNewStore.GetOrientation(), FQuat(9, 8, 7, 6));
				TestEqual("Updated object has old visibility", fromNewStore.IsVisible(), Earth.IsVisible());
			});
			It("Change nothing when nothing is set", [this]
			{
				auto defstore = makeDefaultStore();
				CpBldr copyBuilder = FObjectInfoStore::CopyBuilder(defstore);
				RequireTrue("Object already exists in store", copyBuilder.UpdateInfo(Earth.GetName(), TOptRef<TOptional<FName>>(), TOptRef<const FVector>(), TOptRef<const FQuat>(), TOptional<bool>()));
				auto store = copyBuilder.Build();
				safeGetBlock(newEarth, store.Get(Earth.GetName()));
				safeGetBlock(oldEarth, defstore.Get(Earth.GetName()));

				TestEqual("New earth is unchanged from old earth", newEarth, oldEarth);
			});
			It("Errors when name doesnt already exist", [this]
			{
				auto defStore = makeDefaultStore();
				CpBldr copyBuilder = FObjectInfoStore::CopyBuilder(defStore);
				TestFalse("Expected did not commit data", copyBuilder.UpdateInfo(FName(TEXT("Phobos")), TOptRef<TOptional<ObjID>>(Mars.GetName()), FVector(555, 111, 222), FQuat(2), true));
			});
		});
	});
}


#endif
