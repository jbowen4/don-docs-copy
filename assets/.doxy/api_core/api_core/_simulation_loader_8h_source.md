

# File SimulationLoader.h

[**File List**](files.md) **>** [**DONToUnreal**](dir_7e70b7b4a1df651b2af4c8dca0b54b92.md) **>** [**Public**](dir_c336ec6675be099178e02bcdcfb186ce.md) **>** [**SimulationLoader.h**](_simulation_loader_8h.md)

[Go to the documentation of this file](_simulation_loader_8h.md)


```C++
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SimulationGameInstance.h"
#include "DataTypes.h"
#include "MPC2Loader.h"
#include "CesiumGeoreference.h"
#include "Cesium3DTileset.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Engine/StaticMesh.h"
#include "SimulationLoader.generated.h"

UCLASS()
class DONTOUNREAL_API ASimulationLoader : public AActor
{
    GENERATED_BODY()
public:

    // Function to spawn objects based on model data
    UFUNCTION(BlueprintCallable, Category = "Simulation")
    void SpawnObjects();

    // Helper functions for Blueprint access
    UFUNCTION(BlueprintCallable, Category = "Simulation")
    AObjectActor* GetSpawnedActorById(const FString& ActorId);

    UFUNCTION(BlueprintCallable, Category = "Simulation", BlueprintPure)
    TMap<FString, AObjectActor*> GetAllSpawnedActors() const;

    // Get the number of spawned actors
    UFUNCTION(BlueprintCallable, Category = "Simulation", BlueprintPure)
    int32 GetSpawnedActorCount() const { return SpawnedActors.Num(); }

    // Get all model IDs as an array (useful for Blueprints)
    UFUNCTION(BlueprintCallable, Category = "Simulation", BlueprintPure)
    TArray<FString> GetAllModelIds() const;

    UFUNCTION(BlueprintCallable, Category = "Simulation")
    static void TeleportToObject(AObjectActor* TargetObject, APawn* PlayerPawn);

    UFUNCTION(BlueprintCallable, Category = "Simulation")
    static void InitializeSimulation(bool bImportObjects, const FString& InSimulationPath, const FString& InTelemetryName, const FString& MPCProtocol, const FString& TimeUnit, USimulationGameInstance* MyGameInstance);
private:
    FSimulationMetadata SimulationData;

    // Helper function to spawn a single model actor
    AObjectActor* SpawnModelActor(UWorld* World, const FModelMetadata& Model, USimulationGameInstance* GameInstance);

    AObjectActor* SetActorParents(UWorld* World, const FModelMetadata& Model);

    // Map to keep track of spawned actors by ID
    UPROPERTY(Transient)
    TMap<FString, AObjectActor*> SpawnedActors;

    // Configuration path
    UPROPERTY()
    FString CurrentConfigPath;
};
```


