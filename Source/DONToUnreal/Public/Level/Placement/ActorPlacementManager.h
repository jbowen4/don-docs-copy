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

/**
 * Places objects in the current level.
 *
 * Will also compute _where_ an object should be placed in the level, i.e.:
 * - whether it should be billboarded or placed normally
 * - whether it would even be visible at that distance
 * - for outer space, simulating movement by scaling the billboarded planets
 */
class DONTOUNREAL_API IActorPlacementManager
{
	GENERATED_BODY()
public:
	/**
     * A function that configures and spawns an actor, including model, texture, etc.
     *
     * Example:
     * @code
     * [](UWorld& world) { // TODO make this real UE code
     *		ACelestialWithRadius* actor = world.SpawnActor<ACelestialWithRadius>(0.1);
     *		actor.SetName("Earth");
     *		actor.SetTexture("earth.png");
     *		return actor;
     * }
     * @endcode
     */
    using SpawnerFunc = TFunction<AActor*(UWorld& world)>;

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.

	/**
	 * Called at the beginning of the sim to tell the level to spawn high-poly and low-poly actors for every object.
	 * E.g. a high-poly Earth for when it's within render distance, and a low-poly Earth when it should be billboarded.
	 * 
	 * Any objects that don't need a low-res object or don't need a high-res object should be left out of the corresponding maps.
	 * For example, if we're only billboarding planets and will never render them locally, the caller should put every planet in the LowResSpawners map only and everything else in the HighResSpawners map only.
	 * 
	 *
	 * TODO figure out if there's even any cases where we'd have something visible in distant rendering that doesn't have its own level when it would be close, or even like a buggy that would be distantly-rendered or something...
	 *		Oh ok we could always have a jupiter-sized duck that's both "able to be distantly rendered" and "doesn't have its own map"
	 *		So, it would be better to just have the loader say whether or not a high-res or low-res object is needed.
	 *		Also it would probably be better to just use LOD but honestly idk how to do that
	 * @param HighResSpawners 
	 * @param LowResSpawners 
	 */
	virtual void Init(const TMap<ObjID, SpawnerFunc>& HighResSpawners, const TMap<ObjID, SpawnerFunc>& LowResSpawners) {}

	/**
	 * Moves the actors representing each object to the new positions on this simulation tick.
	 *
	 * It should be safe to cache this reference between calls of this method.
	 * 
	 * @param NewPositions The object information for the current simulation tick.
	 */
	virtual void Update(const FObjectInfoStore& NewPositions) {}

	/**
	 * Called every game-tick to update the camera's position.
	 *
	 * TODO we also need to handle when the camera is orbiting an object, right? or would this work for that automatically?? I think it might!
	 * 
	 * @param NewPosition The new "Real-World" position of the camera for the given tick.
	 */
	virtual void UpdateCameraPosition(const FRelativePosition& NewPosition) {}
};

