// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ObjectInfo.h"
#include "UObject/Object.h"
#include "ObjectInfoStore.generated.h"

/**
 * Stores the data (position, orientation, visibility, and parent) for every object in the simulation at a time step.
 */
USTRUCT()
struct DONTOUNREAL_API FObjectInfoStore
{
	GENERATED_BODY()

	friend struct FObjectInfoStoreBuilder;
	friend struct FObjectInfoStoreCopyBuilder;

	/**
	 * Get a builder to create an FObjectInfoStore from scratch.
	 */
	static FObjectInfoStoreBuilder Builder();
	/**
	 * Get a builder for a new FObjectInfoStore populated with the values from another FObjectInfoStore. 
	 */
	static FObjectInfoStoreCopyBuilder CopyBuilder(const FObjectInfoStore& CopyFrom);

private:
	UPROPERTY()
	FObjectInfo Origin; // can't make it const due to the move constructor

	UPROPERTY()
	TMap<FName, FObjectInfo> objects;

public:
	/**
	 * Get the origin for this coordinate system that objects' positions are based on.
	 *
	 * Current implementation is always @link FObjectInfo::ORIGIN@endlink.
	 */
	GETTER(FObjectInfo, Origin);

	/**
	 * Get the object info for the given name, or empty if that object does not exist in this store.
	 */
	TOptRef<const FObjectInfo> Get(const FName& Name) const;

	/**
	 * Get a list of all object names in this store.
	 *
	 * @param Out Upon return, contains the set of unique keys in this store.
	 */
	void Keys(TArray<FName>& Out) const;

	/**
	 * Returns a list of all object names in this store.
	 */
	FORCEINLINE TArray<FName> Keys() const
	{
		TArray<FName> ret;
		Keys(ret);
		return ret;
	}

	/**
	 * How many objects are in this store.
	 */
	int32 Size() const;

	/**
	 * Returns a string representation of this object.
	 */
	FString ToString() const;


	/// Default/empty constructor
	FObjectInfoStore();

	/**
	 * Creates an ObjectInfoStore with the provided origin.
	 * @param Origin The basis for this coordinate system, which all objects' positions will be relative to.
	 */
	explicit FObjectInfoStore(const FObjectInfo& Origin);

	/// Copy constructor
	FObjectInfoStore(const FObjectInfoStore& copyFrom);


	FObjectInfoStore(FObjectInfoStore&& other) noexcept
		: Origin(std::move(other.Origin)),
		  objects(std::move(other.objects))
	{
	}

	FObjectInfoStore& operator=(const FObjectInfoStore& other)
	{
		if (this == &other)
			return *this;
		Origin = other.Origin;
		objects = other.objects;
		return *this;
	}

	FObjectInfoStore& operator=(FObjectInfoStore&& other) noexcept
	{
		if (this == &other)
			return *this;
		Origin = std::move(other.Origin);
		objects = std::move(other.objects);
		return *this;
	}

private:
	FObjectInfo* getUnchecked(const FName& Name) const;
};

// Ignore this. Internal stuff that's only outside the class because of Unreal's freaking reflection system
USTRUCT()
struct FObjectInfoTmp
{
	GENERATED_BODY()

	FName Name;
	TOptional<FName> ParentName;
	FVector Position;
	FQuat Orientation;
	bool Visibility;

	FObjectInfoTmp(const FName& name, const TOptional<FName>& parent_name, const FVector& position,
	               const FQuat& orientation, const bool visibility)
		: Name(name),
		  ParentName(parent_name),
		  Position(position),
		  Orientation(orientation),
		  Visibility(visibility)
	{
	}

	FObjectInfoTmp()
		: Name(), ParentName(NullOpt), Position(FVector(0)), Orientation(FQuat(0)), Visibility(true)
	{
	}

	~FObjectInfoTmp()
	{
	}

	FString ToString() const;
};

/**
 * Used on the first sim-tick to establish all objects' initial states.
 * Use @link FObjectInfoStoreCopyBuilder@endlink to update the positions for later ticks.
 */
USTRUCT()
struct FObjectInfoStoreBuilder
{
	GENERATED_BODY()

private:
	FObjectInfo origin = FObjectInfo::ORIGIN;

public:
	friend struct FObjectInfoStore;
	/**
	 * Add an object's information to this builder, to be added to the resulting store.
	 * 
	 * @param Name The unique identifier of this object. Each object's name must be unique, and any successive calls with an already-given name will overwrite the previous.
	 * @param ParentName The unique identifier of the parent to this object. If empty, will default to @link FObjectInfo::ORIGIN@endlink.
	 * @param Position The position of this object relative to the parent.
	 * @param Orientation The orientation of this object relative to the parent.
	 * @param Visibility Whether or not this object should be visible.
	 */
	void AddObject(const FName& Name, const TOptional<FName>& ParentName, const FVector& Position, const FQuat& Orientation, const bool Visibility);

	/**
	 * Add this existing object's information, to be copied to the resulting store.
	 */
	void AddObject(const FObjectInfo& ToCopy);

	/**
	 * Set the position for the new coordinate system that all positions will be based on.
	 * Must not have a parent.
	 *
	 * Defaults to @link FObjectInfo::ORIGIN@endlink.
	 *
	 * @returns False if Origin is not a valid origin.
	 */
	USE_RET bool SetOrigin(const FObjectInfo& Origin);

	/**
	 * Returns true if Name is already defined in this builder, false otherwise.
	 */
	bool Contains(const FName& Name) const;

	/**
	 * Create the ObjectInfoStore with the provided data.
	 *
	 * Generated @link ObjectInfo@endlink instances will be owned by the provided struct, with pointers to their parents within this ObjectInfoStore.
	 *
	 * This method may only be called once per builder.
	 */
	void Build(FObjectInfoStore& out);

	/**
	 * Create the ObjectInfoStore with the provided data.
	 *
	 * Generated @link ObjectInfo@endlink instances will be owned by the returned struct, each with pointers to their parents that are also stored within this ObjectInfoStore.
	 *
	 * This method may only be called once per builder.
	 */
	FORCEINLINE FObjectInfoStore Build()
	{
		FObjectInfoStore ret;
		Build(ret);
		return ret;
	}

	/**
	 * Get how many items are in this builder.
	 */
	int32 Size() const;

	/**
	 * Create a new builder to construct a new ObjectInfoStore from scratch.
	 *
	 * To only update pre-existing data, see @link FObjectInfoStoreCopyBuilder@endlink
	 */
	FObjectInfoStoreBuilder();

protected:
	UPROPERTY()
	TMap<FName, FObjectInfoTmp> toAdd;
};

/**
 * Creates an ObjectInfoStore based on the values from a previously-defined ObjectInfoStore.
 */
USTRUCT()
struct FObjectInfoStoreCopyBuilder : public FObjectInfoStoreBuilder
{
	GENERATED_BODY()

	/**
	 * Add information to an object by name.  The object may or may not already have data from the copy constructor, hence why every parameter is optional.  This is why C++ needs optional arguments...
	 *
	 * If the object has not already been added to this builder, a new object will be queued.
	 * Else the information provided will be overlaid over the EXISTING entry with this name.
	 * 
	 * For example, `Builder(storeWithEarth).AddObject(Earth, TOptRef(), FVector(0,1,2), TOptRef(), TOptional())`
	 * will keep all information from "storeWithEarth > Earth", but replace its position with FVector(0,1,2).
	 *
	 * @param Name 
	 * @param ParentName If the Reference is empty, that means you don't wish to overwrite the existing data. If the internal Optional is empty, that means the parent is the ORIGIN.
	 * @param Position 
	 * @param Orientation 
	 * @param Visibility
	 * @return True if data was set successfully. False when Name does not exist in this builder (and by extension the copied-from ObjectInfoStore).
	 */
	bool UpdateInfo(const FName& Name, TOptRef<TOptional<FName>> ParentName, TOptRef<const FVector> Position,
	                TOptRef<const FQuat> Orientation, TOptional<bool> Visibility);

	// DON'T CALL THIS. NEVER CALL THIS. This is only here for Unreal's reflection system.
	FObjectInfoStoreCopyBuilder()
	{
	}

	/**
	 * Create a new ObjectInfoStore builder with the initial values from the provided store.
	 */
	explicit FObjectInfoStoreCopyBuilder(const FObjectInfoStore& CopyFrom);
};
