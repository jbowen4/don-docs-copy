

# File OuterSpaceActorPlacementManager.h

[**File List**](files.md) **>** [**DONToUnreal**](dir_7e70b7b4a1df651b2af4c8dca0b54b92.md) **>** [**Public**](dir_c336ec6675be099178e02bcdcfb186ce.md) **>** [**Level**](dir_f752106aec1708221047f68d9fed8822.md) **>** [**Placement**](dir_f8149d1e01a7524d424599d29091c4b7.md) **>** [**OuterSpace**](dir_f1c1f71ebe1f4e07b55e7acb7697c7cd.md) **>** [**OuterSpaceActorPlacementManager.h**](_outer_space_actor_placement_manager_8h.md)

[Go to the documentation of this file](_outer_space_actor_placement_manager_8h.md)


```C++
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Level/Placement/ActorPlacementManager.h"
#include "UObject/Object.h"
#include "OuterSpaceActorPlacementManager.generated.h"

UCLASS()
class DONTOUNREAL_API UOuterSpaceActorPlacementManager : public UWorldSubsystem, public IActorPlacementManager
{
    GENERATED_BODY()
    
public:
    virtual void Init(const TMap<ObjID, SpawnerFunc>& HighResSpawners, const TMap<ObjID, SpawnerFunc>& LowResSpawners) override;
    virtual void Update(const FObjectInfoStore& NewPositions) override;
    virtual void UpdateCameraPosition(const FRelativePosition& NewPosition) override;

    void SetTargetedObject(TOptRef<const ObjID> TargetName);

private:
    UPROPERTY()
    TMap<FName, AActor*> lowResActors;

    UPROPERTY()
    TMap<FName, AActor*> highResActors;

    UPROPERTY()
    AActor* camera;
};
```


