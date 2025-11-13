

# Class ASimulationLoader



[**ClassList**](annotated.md) **>** [**ASimulationLoader**](class_a_simulation_loader.md)








Inherits the following classes: AActor


































## Public Functions

| Type | Name |
| ---: | :--- |
|  TArray&lt; FString &gt; | [**GetAllModelIds**](#function-getallmodelids) () const<br> |
|  TMap&lt; FString, [**AObjectActor**](class_a_object_actor.md) \* &gt; | [**GetAllSpawnedActors**](#function-getallspawnedactors) () const<br> |
|  [**AObjectActor**](class_a_object_actor.md) \* | [**GetSpawnedActorById**](#function-getspawnedactorbyid) (const FString & ActorId) <br> |
|  int32 | [**GetSpawnedActorCount**](#function-getspawnedactorcount) () const<br> |
|  void | [**SpawnObjects**](#function-spawnobjects) () <br> |


## Public Static Functions

| Type | Name |
| ---: | :--- |
|  void | [**InitializeSimulation**](#function-initializesimulation) (bool bImportObjects, const FString & InSimulationPath, const FString & InTelemetryName, const FString & MPCProtocol, const FString & TimeUnit, [**USimulationGameInstance**](class_u_simulation_game_instance.md) \* MyGameInstance) <br> |
|  void | [**TeleportToObject**](#function-teleporttoobject) ([**AObjectActor**](class_a_object_actor.md) \* TargetObject, APawn \* PlayerPawn) <br> |


























## Public Functions Documentation




### function GetAllModelIds 

```C++
TArray< FString > ASimulationLoader::GetAllModelIds () const
```




<hr>



### function GetAllSpawnedActors 

```C++
TMap< FString, AObjectActor * > ASimulationLoader::GetAllSpawnedActors () const
```




<hr>



### function GetSpawnedActorById 

```C++
AObjectActor * ASimulationLoader::GetSpawnedActorById (
    const FString & ActorId
) 
```




<hr>



### function GetSpawnedActorCount 

```C++
inline int32 ASimulationLoader::GetSpawnedActorCount () const
```




<hr>



### function SpawnObjects 

```C++
void ASimulationLoader::SpawnObjects () 
```




<hr>
## Public Static Functions Documentation




### function InitializeSimulation 

```C++
static void ASimulationLoader::InitializeSimulation (
    bool bImportObjects,
    const FString & InSimulationPath,
    const FString & InTelemetryName,
    const FString & MPCProtocol,
    const FString & TimeUnit,
    USimulationGameInstance * MyGameInstance
) 
```




<hr>



### function TeleportToObject 

```C++
static void ASimulationLoader::TeleportToObject (
    AObjectActor * TargetObject,
    APawn * PlayerPawn
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `Source/DONToUnreal/Public/SimulationLoader.h`

