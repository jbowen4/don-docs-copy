// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Level/Placement/ActorPlacementManager.h"
#include "UObject/Object.h"
#include "OuterSpaceActorPlacementManager.generated.h"

/**
 * 
 */
UCLASS()
class DONTOUNREAL_API UOuterSpaceActorPlacementManager : public UWorldSubsystem, public IActorPlacementManager
{
	GENERATED_BODY()
	
public:
	virtual void Init(const TMap<ObjID, SpawnerFunc>& HighResSpawners, const TMap<ObjID, SpawnerFunc>& LowResSpawners) override;
	virtual void Update(const FObjectInfoStore& NewPositions) override;
	/**
	 * Called every game-tick to update the camera's position.
	 *
	 * For OuterSpace, this will recalculate the billboards for the camera's new position every tick.
	 * 
	 * @param NewPosition The new "Real-World" position of the camera for the given tick.
	 */
	virtual void UpdateCameraPosition(const FRelativePosition& NewPosition) override;

	/**
	 * Set the currently-targeted object, which will be used as the basis for the Outer Space coordinate system.
	 *
	 * If empty, the camera will be set as the origin.
	 */
	void SetTargetedObject(TOptRef<const ObjID> TargetName);

private:
	/**
	 * Low-poly representations of each sim object for when they're outside of placement distance.
	 */
	UPROPERTY()
	TMap<FName, AActor*> lowResActors;

	/**
	 * High-poly representations of each sim object that can be inside of placement range.
	 */
	UPROPERTY()
	TMap<FName, AActor*> highResActors;

	UPROPERTY()
	AActor* camera;
};
