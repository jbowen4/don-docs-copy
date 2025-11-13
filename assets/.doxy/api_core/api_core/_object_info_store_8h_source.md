

# File ObjectInfoStore.h

[**File List**](files.md) **>** [**Data**](dir_436819c72972a51f013170f2c377a0ea.md) **>** [**ObjectInfoStore.h**](_object_info_store_8h.md)

[Go to the documentation of this file](_object_info_store_8h.md)


```C++
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ObjectInfo.h"
#include "UObject/Object.h"
#include "ObjectInfoStore.generated.h"

USTRUCT()
struct DONTOUNREAL_API FObjectInfoStore
{
    GENERATED_BODY()

    friend struct FObjectInfoStoreBuilder;
    friend struct FObjectInfoStoreCopyBuilder;

    static FObjectInfoStoreBuilder Builder();
    static FObjectInfoStoreCopyBuilder CopyBuilder(const FObjectInfoStore& CopyFrom);

private:
    UPROPERTY()
    FObjectInfo Origin; // can't make it const due to the move constructor

    UPROPERTY()
    TMap<FName, FObjectInfo> objects;

public:
    GETTER(FObjectInfo, Origin);

    TOptRef<const FObjectInfo> Get(const FName& Name) const;

    void Keys(TArray<FName>& Out) const;

    FORCEINLINE TArray<FName> Keys() const
    {
        TArray<FName> ret;
        Keys(ret);
        return ret;
    }

    int32 Size() const;

    FString ToString() const;


    FObjectInfoStore();

    explicit FObjectInfoStore(const FObjectInfo& Origin);

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

USTRUCT()
struct FObjectInfoStoreBuilder
{
    GENERATED_BODY()

private:
    FObjectInfo origin = FObjectInfo::ORIGIN;

public:
    friend struct FObjectInfoStore;
    void AddObject(const FName& Name, const TOptional<FName>& ParentName, const FVector& Position, const FQuat& Orientation, const bool Visibility);

    void AddObject(const FObjectInfo& ToCopy);

    USE_RET bool SetOrigin(const FObjectInfo& Origin);

    bool Contains(const FName& Name) const;

    void Build(FObjectInfoStore& out);

    FORCEINLINE FObjectInfoStore Build()
    {
        FObjectInfoStore ret;
        Build(ret);
        return ret;
    }

    int32 Size() const;

    FObjectInfoStoreBuilder();

protected:
    UPROPERTY()
    TMap<FName, FObjectInfoTmp> toAdd;
};

USTRUCT()
struct FObjectInfoStoreCopyBuilder : public FObjectInfoStoreBuilder
{
    GENERATED_BODY()

    
    bool UpdateInfo(const FName& Name, TOptRef<TOptional<FName>> ParentName, TOptRef<const FVector> Position,
                    TOptRef<const FQuat> Orientation, TOptional<bool> Visibility);

    // DON'T CALL THIS. NEVER CALL THIS. This is only here for Unreal's reflection system.
    FObjectInfoStoreCopyBuilder()
    {
    }

    explicit FObjectInfoStoreCopyBuilder(const FObjectInfoStore& CopyFrom);
};
```


