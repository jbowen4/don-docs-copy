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


