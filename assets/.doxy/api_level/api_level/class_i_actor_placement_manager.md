

# Class IActorPlacementManager



[**ClassList**](annotated.md) **>** [**IActorPlacementManager**](class_i_actor_placement_manager.md)



[More...](#detailed-description)

* `#include <ActorPlacementManager.h>`





Inherited by the following classes: [UOuterSpaceActorPlacementManager](class_u_outer_space_actor_placement_manager.md)












## Public Types

| Type | Name |
| ---: | :--- |
| typedef TFunction&lt; AActor \*(UWorld &world)&gt; | [**SpawnerFunc**](#typedef-spawnerfunc)  <br> |




















## Public Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**Init**](#function-init) (const TMap&lt; ObjID, [**SpawnerFunc**](class_i_actor_placement_manager.md#typedef-spawnerfunc) &gt; & HighResSpawners, const TMap&lt; ObjID, [**SpawnerFunc**](class_i_actor_placement_manager.md#typedef-spawnerfunc) &gt; & LowResSpawners) <br> |
| virtual void | [**Update**](#function-update) (const FObjectInfoStore & NewPositions) <br> |
| virtual void | [**UpdateCameraPosition**](#function-updatecameraposition) (const FRelativePosition & NewPosition) <br> |




























## Detailed Description


Places objects in the current level.


Will also compute _where_ an object should be placed in the level, i.e.:
* whether it should be billboarded or placed normally
* whether it would even be visible at that distance
* for outer space, simulating movement by scaling the billboarded planets 




    
## Public Types Documentation




### typedef SpawnerFunc 

```C++
using IActorPlacementManager::SpawnerFunc =  TFunction<AActor*(UWorld& world)>;
```



A function that configures and spawns an actor, including model, texture, etc.


Example: 
```C++
[](UWorld& world) { // TODO make this real UE code
    ACelestialWithRadius* actor = world.SpawnActor<ACelestialWithRadius>(0.1);
    actor.SetName("Earth");
    actor.SetTexture("earth.png");
    return actor;
}
```
 


        

<hr>
## Public Functions Documentation




### function Init 

```C++
inline virtual void IActorPlacementManager::Init (
    const TMap< ObjID, SpawnerFunc > & HighResSpawners,
    const TMap< ObjID, SpawnerFunc > & LowResSpawners
) 
```



Called at the beginning of the sim to tell the level to spawn high-poly and low-poly actors for every object. E.g. a high-poly Earth for when it's within render distance, and a low-poly Earth when it should be billboarded.


Any objects that don't need a low-res object or don't need a high-res object should be left out of the corresponding maps. For example, if we're only billboarding planets and will never render them locally, the caller should put every planet in the LowResSpawners map only and everything else in the HighResSpawners map only.


TODO figure out if there's even any cases where we'd have something visible in distant rendering that doesn't have its own level when it would be close, or even like a buggy that would be distantly-rendered or something... Oh ok we could always have a jupiter-sized duck that's both "able to be distantly rendered" and "doesn't have its own map" So, it would be better to just have the loader say whether or not a high-res or low-res object is needed. Also it would probably be better to just use LOD but honestly idk how to do that 

**Parameters:**


* `HighResSpawners` 
* `LowResSpawners` 




        

<hr>



### function Update 

```C++
inline virtual void IActorPlacementManager::Update (
    const FObjectInfoStore & NewPositions
) 
```



Moves the actors representing each object to the new positions on this simulation tick.


It should be safe to cache this reference between calls of this method.




**Parameters:**


* `NewPositions` The object information for the current simulation tick. 




        

<hr>



### function UpdateCameraPosition 

```C++
inline virtual void IActorPlacementManager::UpdateCameraPosition (
    const FRelativePosition & NewPosition
) 
```



Called every game-tick to update the camera's position.


TODO we also need to handle when the camera is orbiting an object, right? or would this work for that automatically?? I think it might!




**Parameters:**


* `NewPosition` The new "Real-World" position of the camera for the given tick. 




        

<hr>

------------------------------
The documentation for this class was generated from the following file `Source/DONToUnreal/Public/Level/Placement/ActorPlacementManager.h`

