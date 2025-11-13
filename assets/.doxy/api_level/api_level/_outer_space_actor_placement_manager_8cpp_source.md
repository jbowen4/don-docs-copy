

# File OuterSpaceActorPlacementManager.cpp

[**File List**](files.md) **>** [**DONToUnreal**](dir_7e70b7b4a1df651b2af4c8dca0b54b92.md) **>** [**Private**](dir_2c3ab2caebe6f83b4fac8c870e601c85.md) **>** [**Level**](dir_38c4a65e2b9fd2d33f118b3f37c6e487.md) **>** [**Placement**](dir_1293add6e7967204dc63b52cb2a8529c.md) **>** [**OuterSpace**](dir_1324367273f8b464363f32e1ae17f7ba.md) **>** [**OuterSpaceActorPlacementManager.cpp**](_outer_space_actor_placement_manager_8cpp.md)

[Go to the documentation of this file](_outer_space_actor_placement_manager_8cpp.md)


```C++
// Fill out your copyright notice in the Description page of Project Settings.


#include "Level/Placement/OuterSpace/OuterSpaceActorPlacementManager.h"

void UOuterSpaceActorPlacementManager::Init(const TMap<ObjID, SpawnerFunc>& HighResSpawners,
    const TMap<ObjID, SpawnerFunc>& LowResSpawners)
{
    for (const TPair<ObjID, SpawnerFunc>& high_res_spawner : HighResSpawners)
    {
        // this->highResActors[high_res_spawner.Key] = high_res_spawner.Value()
    }
}

void UOuterSpaceActorPlacementManager::Update(const FObjectInfoStore& NewPositions)
{
    
}

void UOuterSpaceActorPlacementManager::UpdateCameraPosition(const FRelativePosition& NewPosition)
{
    
}


```


