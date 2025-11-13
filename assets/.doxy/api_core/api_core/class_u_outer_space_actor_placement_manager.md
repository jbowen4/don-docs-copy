

# Class UOuterSpaceActorPlacementManager



[**ClassList**](annotated.md) **>** [**UOuterSpaceActorPlacementManager**](class_u_outer_space_actor_placement_manager.md)








Inherits the following classes: UWorldSubsystem,  [IActorPlacementManager](class_i_actor_placement_manager.md)
















## Public Types inherited from IActorPlacementManager

See [IActorPlacementManager](class_i_actor_placement_manager.md)

| Type | Name |
| ---: | :--- |
| typedef TFunction&lt; AActor \*(UWorld &world)&gt; | [**SpawnerFunc**](class_i_actor_placement_manager.md#typedef-spawnerfunc)  <br> |






































## Public Functions

| Type | Name |
| ---: | :--- |
| virtual void | [**Init**](#function-init) (const TMap&lt; ObjID, [**SpawnerFunc**](class_i_actor_placement_manager.md#typedef-spawnerfunc) &gt; & HighResSpawners, const TMap&lt; ObjID, [**SpawnerFunc**](class_i_actor_placement_manager.md#typedef-spawnerfunc) &gt; & LowResSpawners) override<br> |
|  void | [**SetTargetedObject**](#function-settargetedobject) ([**TOptRef**](class_t_opt_ref.md)&lt; const ObjID &gt; TargetName) <br> |
| virtual void | [**Update**](#function-update) (const [**FObjectInfoStore**](struct_f_object_info_store.md) & NewPositions) override<br> |
| virtual void | [**UpdateCameraPosition**](#function-updatecameraposition) (const FRelativePosition & NewPosition) override<br> |


## Public Functions inherited from IActorPlacementManager

See [IActorPlacementManager](class_i_actor_placement_manager.md)

| Type | Name |
| ---: | :--- |
| virtual void | [**Init**](class_i_actor_placement_manager.md#function-init) (const TMap&lt; ObjID, [**SpawnerFunc**](class_i_actor_placement_manager.md#typedef-spawnerfunc) &gt; & HighResSpawners, const TMap&lt; ObjID, [**SpawnerFunc**](class_i_actor_placement_manager.md#typedef-spawnerfunc) &gt; & LowResSpawners) <br> |
| virtual void | [**Update**](class_i_actor_placement_manager.md#function-update) (const [**FObjectInfoStore**](struct_f_object_info_store.md) & NewPositions) <br> |
| virtual void | [**UpdateCameraPosition**](class_i_actor_placement_manager.md#function-updatecameraposition) (const FRelativePosition & NewPosition) <br> |






















































## Public Functions Documentation




### function Init 

```C++
virtual void UOuterSpaceActorPlacementManager::Init (
    const TMap< ObjID, SpawnerFunc > & HighResSpawners,
    const TMap< ObjID, SpawnerFunc > & LowResSpawners
) override
```



Called at the beginning of the sim to tell the level to spawn high-poly and low-poly actors for every object. E.g. a high-poly Earth for when it's within render distance, and a low-poly Earth when it should be billboarded.


Any objects that don't need a low-res object or don't need a high-res object should be left out of the corresponding maps. For example, if we're only billboarding planets and will never render them locally, the caller should put every planet in the LowResSpawners map only and everything else in the HighResSpawners map only.


TODO figure out if there's even any cases where we'd have something visible in distant rendering that doesn't have its own level when it would be close, or even like a buggy that would be distantly-rendered or something... Oh ok we could always have a jupiter-sized duck that's both "able to be distantly rendered" and "doesn't have its own map" So, it would be better to just have the loader say whether or not a high-res or low-res object is needed. Also it would probably be better to just use LOD but honestly idk how to do that 

**Parameters:**


* `HighResSpawners` 
* `LowResSpawners` 




        
Implements [*IActorPlacementManager::Init*](class_i_actor_placement_manager.md#function-init)


<hr>



### function SetTargetedObject 

```C++
void UOuterSpaceActorPlacementManager::SetTargetedObject (
    TOptRef < const ObjID > TargetName
) 
```



Set the currently-targeted object, which will be used as the basis for the Outer Space coordinate system.


If empty, the camera will be set as the origin. 


        

<hr>



### function Update 

```C++
virtual void UOuterSpaceActorPlacementManager::Update (
    const FObjectInfoStore & NewPositions
) override
```



Moves the actors representing each object to the new positions on this simulation tick.


It should be safe to cache this reference between calls of this method.




**Parameters:**


* `NewPositions` The object information for the current simulation tick. 




        
Implements [*IActorPlacementManager::Update*](class_i_actor_placement_manager.md#function-update)


<hr>



### function UpdateCameraPosition 

```C++
virtual void UOuterSpaceActorPlacementManager::UpdateCameraPosition (
    const FRelativePosition & NewPosition
) override
```



Called every game-tick to update the camera's position.


For OuterSpace, this will recalculate the billboards for the camera's new position every tick.




**Parameters:**


* `NewPosition` The new "Real-World" position of the camera for the given tick. 




        
Implements [*IActorPlacementManager::UpdateCameraPosition*](class_i_actor_placement_manager.md#function-updatecameraposition)


<hr>

------------------------------
The documentation for this class was generated from the following file `Source/DONToUnreal/Public/Level/Placement/OuterSpace/OuterSpaceActorPlacementManager.h`

