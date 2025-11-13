

# File ActorPlacementManager.h

[**File List**](files.md) **>** [**DONToUnreal**](dir_7e70b7b4a1df651b2af4c8dca0b54b92.md) **>** [**Public**](dir_c336ec6675be099178e02bcdcfb186ce.md) **>** [**Level**](dir_f752106aec1708221047f68d9fed8822.md) **>** [**Placement**](dir_f8149d1e01a7524d424599d29091c4b7.md) **>** [**ActorPlacementManager.h**](_actor_placement_manager_8h.md)

[Go to the documentation of this file](_actor_placement_manager_8h.md)


```C++
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Data/ObjectInfoStore.h"
#include "UObject/Interface.h"
#include "ActorPlacementManager.generated.h"

// This class does not need to be modified.
UINTERFACE()
class UActorPlacementManager : public UInterface
{
    GENERATED_BODY()
};

class DONTOUNREAL_API IActorPlacementManager
{
    GENERATED_BODY()
public:
    using SpawnerFunc = TFunction<AActor*(UWorld& world)>;

    // Add interface functions to this class. This is the class that will be inherited to implement this interface.

    virtual void Init(const TMap<ObjID, SpawnerFunc>& HighResSpawners, const TMap<ObjID, SpawnerFunc>& LowResSpawners) {}

    virtual void Update(const FObjectInfoStore& NewPositions) {}

    virtual void UpdateCameraPosition(const FRelativePosition& NewPosition) {}
};

```


