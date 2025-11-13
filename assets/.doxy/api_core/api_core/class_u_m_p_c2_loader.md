

# Class UMPC2Loader



[**ClassList**](annotated.md) **>** [**UMPC2Loader**](class_u_m_p_c2_loader.md)








Inherits the following classes: UBlueprintFunctionLibrary




































## Public Static Functions

| Type | Name |
| ---: | :--- |
|  TMap&lt; FString, [**FObjectState**](struct_f_object_state.md) &gt; | [**ExtractObjectStatesMPC2**](#function-extractobjectstatesmpc2) ([**tinyxml2::XMLElement**](classtinyxml2_1_1_x_m_l_element.md) \* TimeTagXML) <br> |
|  double | [**ExtractTimeValueMPC2**](#function-extracttimevaluempc2) (const FString & TimeTagXML) <br> |
|  FString | [**FModelMetadatatoStr**](#function-fmodelmetadatatostr) (const [**FModelMetadata**](struct_f_model_metadata.md) & Model) <br> |
|  FString | [**GetAuthor**](#function-getauthor) () <br> |
|  FString | [**GetDescription**](#function-getdescription) () <br> |
|  TArray&lt; [**FLightData**](struct_f_light_data.md) &gt; | [**GetLightData**](#function-getlightdata) () <br> |
|  TArray&lt; [**FModelMetadata**](struct_f_model_metadata.md) &gt; | [**GetModelData**](#function-getmodeldata) () <br> |
|  FString | [**GetName**](#function-getname) () <br> |
|  TArray&lt; [**FObjectsOfInterest**](struct_f_objects_of_interest.md) &gt; | [**GetObjectsOfInterest**](#function-getobjectsofinterest) () <br> |
|  TArray&lt; [**FTerrainMetadata**](struct_f_terrain_metadata.md) &gt; | [**GetTerrainData**](#function-getterraindata) () <br> |
|  void | [**ImportSimulationModelsMPC2**](#function-importsimulationmodelsmpc2) (const FString & ModelsFolderPath) <br> |
|  bool | [**LoadSimulationConfigMPC2**](#function-loadsimulationconfigmpc2) (const bool importModels, const FString & SimulationDirectory) <br> |
|  void | [**ParseModelFileMPC2**](#function-parsemodelfilempc2) (const FString & FilePath) <br> |
|  void | [**ProcessTelemetryFileMPC2**](#function-processtelemetryfilempc2) (const FString & TelemetryPath, [**USimulationGameInstance**](class_u_simulation_game_instance.md) \* GameInstance) <br> |


























## Public Static Functions Documentation




### function ExtractObjectStatesMPC2 

```C++
static TMap< FString, FObjectState > UMPC2Loader::ExtractObjectStatesMPC2 (
    tinyxml2::XMLElement * TimeTagXML
) 
```




<hr>



### function ExtractTimeValueMPC2 

```C++
static double UMPC2Loader::ExtractTimeValueMPC2 (
    const FString & TimeTagXML
) 
```




<hr>



### function FModelMetadatatoStr 

```C++
static FString UMPC2Loader::FModelMetadatatoStr (
    const FModelMetadata & Model
) 
```




<hr>



### function GetAuthor 

```C++
static FString UMPC2Loader::GetAuthor () 
```




<hr>



### function GetDescription 

```C++
static FString UMPC2Loader::GetDescription () 
```




<hr>



### function GetLightData 

```C++
static TArray< FLightData > UMPC2Loader::GetLightData () 
```




<hr>



### function GetModelData 

```C++
static TArray< FModelMetadata > UMPC2Loader::GetModelData () 
```




<hr>



### function GetName 

```C++
static FString UMPC2Loader::GetName () 
```




<hr>



### function GetObjectsOfInterest 

```C++
static TArray< FObjectsOfInterest > UMPC2Loader::GetObjectsOfInterest () 
```




<hr>



### function GetTerrainData 

```C++
static TArray< FTerrainMetadata > UMPC2Loader::GetTerrainData () 
```




<hr>



### function ImportSimulationModelsMPC2 

```C++
static void UMPC2Loader::ImportSimulationModelsMPC2 (
    const FString & ModelsFolderPath
) 
```




<hr>



### function LoadSimulationConfigMPC2 

```C++
static bool UMPC2Loader::LoadSimulationConfigMPC2 (
    const bool importModels,
    const FString & SimulationDirectory
) 
```




<hr>



### function ParseModelFileMPC2 

```C++
static void UMPC2Loader::ParseModelFileMPC2 (
    const FString & FilePath
) 
```




<hr>



### function ProcessTelemetryFileMPC2 

```C++
static void UMPC2Loader::ProcessTelemetryFileMPC2 (
    const FString & TelemetryPath,
    USimulationGameInstance * GameInstance
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `Source/DONToUnreal/Public/MPC2Loader.h`

