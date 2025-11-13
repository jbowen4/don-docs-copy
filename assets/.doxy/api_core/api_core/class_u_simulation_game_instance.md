

# Class USimulationGameInstance



[**ClassList**](annotated.md) **>** [**USimulationGameInstance**](class_u_simulation_game_instance.md)



[More...](#detailed-description)

* `#include <SimulationGameInstance.h>`



Inherits the following classes: UGameInstance


















## Public Attributes

| Type | Name |
| ---: | :--- |
|  float | [**EndTime**](#variable-endtime)  <br> |
|  float | [**GI\_BookmarkTime**](#variable-gi_bookmarktime)  <br> |
|  TArray&lt; FString &gt; | [**GI\_BookmarksName**](#variable-gi_bookmarksname)  <br> |
|  TArray&lt; FString &gt; | [**GI\_BookmarksNotes**](#variable-gi_bookmarksnotes)  <br> |
|  TArray&lt; FString &gt; | [**GI\_BookmarksTime**](#variable-gi_bookmarkstime)  <br> |
|  float | [**GI\_CurrentTime**](#variable-gi_currenttime)  <br> |
|  float | [**GI\_EndTime**](#variable-gi_endtime)  <br> |
|  FString | [**GI\_ModelID**](#variable-gi_modelid)  <br> |
|  FString | [**GI\_SimFilePath**](#variable-gi_simfilepath)  <br> |
|  float | [**GI\_StartTime**](#variable-gi_starttime)  <br> |
|  TMap&lt; float, [**FTelemetryDataValues**](struct_f_telemetry_data_values.md) &gt; | [**GI\_TelemetryData**](#variable-gi_telemetrydata)  <br> |
|  TArray&lt; float &gt; | [**GI\_TelemetryTimeIndexes**](#variable-gi_telemetrytimeindexes)  <br> |
|  FString | [**MPCProtocol**](#variable-mpcprotocol)  <br> |
|  TArray&lt; [**FObjectsOfInterest**](struct_f_objects_of_interest.md) &gt; | [**ObjectsOfInterest**](#variable-objectsofinterest)  <br> |
|  FOnTelemetryUpdated | [**OnTelemetryUpdated**](#variable-ontelemetryupdated)  <br> |
|  [**FSimulationMetadata**](struct_f_simulation_metadata.md) | [**SimulationData**](#variable-simulationdata)  <br> |
|  FString | [**SimulationDirectory**](#variable-simulationdirectory)  <br> |
|  FString | [**SimulationFilePath**](#variable-simulationfilepath)  <br> |
|  TMap&lt; FString, [**AObjectActor**](class_a_object_actor.md) \* &gt; | [**SpawnedActors**](#variable-spawnedactors)  <br> |
|  float | [**StartTime**](#variable-starttime)  <br> |
|  TMap&lt; double, [**FTimeSnapshot**](struct_f_time_snapshot.md) &gt; | [**TelemetryData**](#variable-telemetrydata)  <br> |
|  TArray&lt; float &gt; | [**TelemetryTimeIndexes**](#variable-telemetrytimeindexes)  <br> |
|  float | [**TimeUnit**](#variable-timeunit)  <br> |
|  [**UTelemetryTimeline**](class_u_telemetry_timeline.md) \* | [**Timeline**](#variable-timeline)   = `new [**UTelemetryTimeline**](class_u_telemetry_timeline.md)()`<br> |
















## Public Functions

| Type | Name |
| ---: | :--- |
|  void | [**AddSpawnedActor**](#function-addspawnedactor) (const FString & ActorID, [**AObjectActor**](class_a_object_actor.md) \* Actor) <br> |
|  void | [**AddTelemetryIndex**](#function-addtelemetryindex) (float time) <br> |
|  void | [**ClearAllSpawnedActors**](#function-clearallspawnedactors) () <br> |
|  TMap&lt; FString, [**AObjectActor**](class_a_object_actor.md) \* &gt; | [**GetAllSpawnedActors**](#function-getallspawnedactors) () const<br> |
|  TArray&lt; [**AObjectActor**](class_a_object_actor.md) \* &gt; | [**GetAllSpawnedActorsAsArray**](#function-getallspawnedactorsasarray) () const<br> |
|  TArray&lt; [**FLightData**](struct_f_light_data.md) &gt; | [**GetLightData**](#function-getlightdata) () const<br> |
|  TArray&lt; [**FModelMetadata**](struct_f_model_metadata.md) &gt; | [**GetModelData**](#function-getmodeldata) () const<br> |
|  TArray&lt; [**FObjectsOfInterest**](struct_f_objects_of_interest.md) &gt; | [**GetObjectsOfInterest**](#function-getobjectsofinterest) () const<br> |
|  [**FSimulationMetadata**](struct_f_simulation_metadata.md) | [**GetSimulationData**](#function-getsimulationdata) () const<br> |
|  [**AObjectActor**](class_a_object_actor.md) \* | [**GetSpawnedActorByID**](#function-getspawnedactorbyid) (const FString & ActorID) const<br> |
|  int | [**GetSpawnedActorCount**](#function-getspawnedactorcount) () const<br> |
|  TArray&lt; [**FTerrainMetadata**](struct_f_terrain_metadata.md) &gt; | [**GetTerrainData**](#function-getterraindata) () const<br> |
|  bool | [**HasSpawnedActor**](#function-hasspawnedactor) (const FString & ActorID) const<br> |
|  void | [**RemoveSpawnedActor**](#function-removespawnedactor) (const FString & ActorID) <br> |
|  void | [**SetEndTime**](#function-setendtime) (float time) <br> |
|  void | [**SetObjectActorVis**](#function-setobjectactorvis) (bool vis, [**AObjectActor**](class_a_object_actor.md) \* Actor) <br> |
|  void | [**SetSimulationData**](#function-setsimulationdata) (const [**FSimulationMetadata**](struct_f_simulation_metadata.md) & InData) <br> |
|  void | [**SetStartTime**](#function-setstarttime) (float time) <br> |
|  void | [**SetTelemetryData**](#function-settelemetrydata) (const double time, TMap&lt; FString, [**FObjectState**](struct_f_object_state.md) &gt; ObjectStates) <br> |
|  void | [**SetTelemetryDataBroadcast**](#function-settelemetrydatabroadcast) (const double time, TMap&lt; FString, [**FObjectState**](struct_f_object_state.md) &gt; ObjectStates) <br> |
|  void | [**SetTelemetryName**](#function-settelemetryname) (const FString & Name) <br> |




























## Detailed Description


[**USimulationGameInstance**](class_u_simulation_game_instance.md)


This class is responsible for managing the simulation data and state within the game instance. It stores metadata about the simulation, including models, terrains, lights, and telemetry data. 


    
## Public Attributes Documentation




### variable EndTime 

```C++
float USimulationGameInstance::EndTime;
```




<hr>



### variable GI\_BookmarkTime 

```C++
float USimulationGameInstance::GI_BookmarkTime;
```




<hr>



### variable GI\_BookmarksName 

```C++
TArray<FString> USimulationGameInstance::GI_BookmarksName;
```




<hr>



### variable GI\_BookmarksNotes 

```C++
TArray<FString> USimulationGameInstance::GI_BookmarksNotes;
```




<hr>



### variable GI\_BookmarksTime 

```C++
TArray<FString> USimulationGameInstance::GI_BookmarksTime;
```




<hr>



### variable GI\_CurrentTime 

```C++
float USimulationGameInstance::GI_CurrentTime;
```




<hr>



### variable GI\_EndTime 

```C++
float USimulationGameInstance::GI_EndTime;
```




<hr>



### variable GI\_ModelID 

```C++
FString USimulationGameInstance::GI_ModelID;
```




<hr>



### variable GI\_SimFilePath 

```C++
FString USimulationGameInstance::GI_SimFilePath;
```




<hr>



### variable GI\_StartTime 

```C++
float USimulationGameInstance::GI_StartTime;
```




<hr>



### variable GI\_TelemetryData 

```C++
TMap<float, FTelemetryDataValues> USimulationGameInstance::GI_TelemetryData;
```




<hr>



### variable GI\_TelemetryTimeIndexes 

```C++
TArray<float> USimulationGameInstance::GI_TelemetryTimeIndexes;
```




<hr>



### variable MPCProtocol 

```C++
FString USimulationGameInstance::MPCProtocol;
```




<hr>



### variable ObjectsOfInterest 

```C++
TArray<FObjectsOfInterest> USimulationGameInstance::ObjectsOfInterest;
```




<hr>



### variable OnTelemetryUpdated 

```C++
FOnTelemetryUpdated USimulationGameInstance::OnTelemetryUpdated;
```




<hr>



### variable SimulationData 

```C++
FSimulationMetadata USimulationGameInstance::SimulationData;
```




<hr>



### variable SimulationDirectory 

```C++
FString USimulationGameInstance::SimulationDirectory;
```




<hr>



### variable SimulationFilePath 

```C++
FString USimulationGameInstance::SimulationFilePath;
```




<hr>



### variable SpawnedActors 

```C++
TMap<FString, AObjectActor*> USimulationGameInstance::SpawnedActors;
```




<hr>



### variable StartTime 

```C++
float USimulationGameInstance::StartTime;
```




<hr>



### variable TelemetryData 

```C++
TMap<double, FTimeSnapshot> USimulationGameInstance::TelemetryData;
```




<hr>



### variable TelemetryTimeIndexes 

```C++
TArray<float> USimulationGameInstance::TelemetryTimeIndexes;
```




<hr>



### variable TimeUnit 

```C++
float USimulationGameInstance::TimeUnit;
```




<hr>



### variable Timeline 

```C++
UTelemetryTimeline* USimulationGameInstance::Timeline;
```




<hr>
## Public Functions Documentation




### function AddSpawnedActor 

```C++
void USimulationGameInstance::AddSpawnedActor (
    const FString & ActorID,
    AObjectActor * Actor
) 
```




<hr>



### function AddTelemetryIndex 

```C++
void USimulationGameInstance::AddTelemetryIndex (
    float time
) 
```




<hr>



### function ClearAllSpawnedActors 

```C++
void USimulationGameInstance::ClearAllSpawnedActors () 
```




<hr>



### function GetAllSpawnedActors 

```C++
TMap< FString, AObjectActor * > USimulationGameInstance::GetAllSpawnedActors () const
```




<hr>



### function GetAllSpawnedActorsAsArray 

```C++
inline TArray< AObjectActor * > USimulationGameInstance::GetAllSpawnedActorsAsArray () const
```




<hr>



### function GetLightData 

```C++
TArray< FLightData > USimulationGameInstance::GetLightData () const
```




<hr>



### function GetModelData 

```C++
TArray< FModelMetadata > USimulationGameInstance::GetModelData () const
```




<hr>



### function GetObjectsOfInterest 

```C++
TArray< FObjectsOfInterest > USimulationGameInstance::GetObjectsOfInterest () const
```




<hr>



### function GetSimulationData 

```C++
FSimulationMetadata USimulationGameInstance::GetSimulationData () const
```




<hr>



### function GetSpawnedActorByID 

```C++
AObjectActor * USimulationGameInstance::GetSpawnedActorByID (
    const FString & ActorID
) const
```




<hr>



### function GetSpawnedActorCount 

```C++
int USimulationGameInstance::GetSpawnedActorCount () const
```




<hr>



### function GetTerrainData 

```C++
TArray< FTerrainMetadata > USimulationGameInstance::GetTerrainData () const
```




<hr>



### function HasSpawnedActor 

```C++
bool USimulationGameInstance::HasSpawnedActor (
    const FString & ActorID
) const
```




<hr>



### function RemoveSpawnedActor 

```C++
void USimulationGameInstance::RemoveSpawnedActor (
    const FString & ActorID
) 
```




<hr>



### function SetEndTime 

```C++
void USimulationGameInstance::SetEndTime (
    float time
) 
```




<hr>



### function SetObjectActorVis 

```C++
void USimulationGameInstance::SetObjectActorVis (
    bool vis,
    AObjectActor * Actor
) 
```




<hr>



### function SetSimulationData 

```C++
void USimulationGameInstance::SetSimulationData (
    const FSimulationMetadata & InData
) 
```




<hr>



### function SetStartTime 

```C++
void USimulationGameInstance::SetStartTime (
    float time
) 
```




<hr>



### function SetTelemetryData 

```C++
void USimulationGameInstance::SetTelemetryData (
    const double time,
    TMap< FString, FObjectState > ObjectStates
) 
```




<hr>



### function SetTelemetryDataBroadcast 

```C++
void USimulationGameInstance::SetTelemetryDataBroadcast (
    const double time,
    TMap< FString, FObjectState > ObjectStates
) 
```




<hr>



### function SetTelemetryName 

```C++
void USimulationGameInstance::SetTelemetryName (
    const FString & Name
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `Source/DONToUnreal/Public/SimulationGameInstance.h`

