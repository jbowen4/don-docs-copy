

# File MPC2Loader.h

[**File List**](files.md) **>** [**DONToUnreal**](dir_7e70b7b4a1df651b2af4c8dca0b54b92.md) **>** [**Public**](dir_c336ec6675be099178e02bcdcfb186ce.md) **>** [**MPC2Loader.h**](_m_p_c2_loader_8h.md)

[Go to the documentation of this file](_m_p_c2_loader_8h.md)


```C++
#pragma once
#include "CoreMinimal.h"
#include "tinyxml2.h"
#include "SimulationGameInstance.h"
#include "DataTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MPC2Loader.generated.h"

UCLASS()
class DONTOUNREAL_API UMPC2Loader : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category = "Simulation", meta = (WorldContext = "World"))
    static bool LoadSimulationConfigMPC2(const bool importModels, const FString& SimulationDirectory);

    UFUNCTION(BlueprintCallable, Category = "Simulation")
    static void ImportSimulationModelsMPC2(const FString& ModelsFolderPath);

    UFUNCTION(BlueprintCallable, Category = "Simulation")
    static void ParseModelFileMPC2(const FString& FilePath);

    UFUNCTION(BlueprintCallable, Category = "Simulation")
    static TArray<FModelMetadata> GetModelData();

    UFUNCTION(BlueprintCallable, Category = "Simulation")
    static TArray<FTerrainMetadata> GetTerrainData();

    UFUNCTION(BlueprintCallable, Category = "Simulation")
    static TArray<FLightData> GetLightData();

    UFUNCTION(BlueprintCallable, Category = "Simulation")
    static TArray<FObjectsOfInterest> GetObjectsOfInterest();

    UFUNCTION(BlueprintCallable, Category = "Simulation")
    static FString GetAuthor();

    UFUNCTION(BlueprintCallable, Category = "Simulation")
    static FString GetName();

    UFUNCTION(BlueprintCallable, Category = "Simulation")
    static FString GetDescription();

    UFUNCTION(BlueprintCallable, Category = "Simulation")
    static double ExtractTimeValueMPC2(const FString& TimeTagXML);

    UFUNCTION(BlueprintCallable, Category = "Simulation")
    static void ProcessTelemetryFileMPC2(const FString& TelemetryPath, USimulationGameInstance* GameInstance);

    static FString FModelMetadatatoStr(const FModelMetadata& Model);

    static TMap<FString, FObjectState> ExtractObjectStatesMPC2(tinyxml2::XMLElement* TimeTagXML);

private:
    static FSimulationMetadata CurrentSimulationData;

    static void parseObjectsOfInterestElement(tinyxml2::XMLElement* ObjectsOfInterestNode, TArray<FObjectsOfInterest> ObjectsOfInterest);
    static void parseTerrainElement(tinyxml2::XMLElement* TerrainNode, FTerrainMetadata& TerrainData);
    static void ParseVector(const std::string& Text, const std::string& Prefix, FVector& OutVector);
    static void ParseQuat(const std::string& Text, const std::string& Prefix, FQuat& OutQuat);
    static void ParseString(const std::string& Text, const std::string& Prefix, FString& OutString);
    static void ParseComponents(const std::string& ModelBlock, TArray<FModelComponentData>& OutComponents);
};
```


