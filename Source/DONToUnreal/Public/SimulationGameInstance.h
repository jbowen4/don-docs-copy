#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "DataTypes.h" 
#include "ObjectActor.h"
#include "Kismet/GameplayStatics.h"
#include "Data/Timeline.h"
#include "SimulationGameInstance.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnTelemetryUpdated, double, TimeValue);

/**
 * USimulationGameInstance
 *
 * This class is responsible for managing the simulation data and state within the game instance.
 * It stores metadata about the simulation, including models, terrains, lights, and telemetry data.
 */

UCLASS()
class DONTOUNREAL_API USimulationGameInstance : public UGameInstance
{
    GENERATED_BODY()

public:
    // Store the simulation data
    UPROPERTY(BlueprintReadWrite, Category = "Simulation")
    FSimulationMetadata SimulationData;

    UPROPERTY(BlueprintReadWrite, Category = "Simulation")
    FString SimulationDirectory;

    UPROPERTY(BlueprintReadWrite, Category = "Simulation")
    FString SimulationFilePath;

    UPROPERTY(BlueprintReadWrite, Category = "Simulation")
    float StartTime;

    UPROPERTY(BlueprintReadWrite, Category = "Simulation")
    float EndTime;

    UPROPERTY(BlueprintReadWrite, Category = "Simulation")
    float TimeUnit;

    UPROPERTY(BlueprintReadWrite, Category = "Simulation")
    FString MPCProtocol;

    UPROPERTY(BlueprintReadWrite, Category = "Simulation")
    TArray<FObjectsOfInterest> ObjectsOfInterest;

	UPROPERTY(BlueprintReadWrite, Category = "Simulation")
	TMap<double, FTimeSnapshot> TelemetryData;

    UPROPERTY(BlueprintReadWrite, Category = "Simulation")
    TArray<float> TelemetryTimeIndexes;

    UTelemetryTimeline* Timeline = new UTelemetryTimeline();

    // Initialize (can be called when data is loaded)
    UFUNCTION(BlueprintCallable, Category = "Simulation")
    void SetTelemetryDataBroadcast(const double time, TMap<FString, FObjectState> ObjectStates);

    UFUNCTION(BlueprintCallable, Category = "Simulation")
    void SetTelemetryData(const double time, TMap<FString, FObjectState> ObjectStates);

    UFUNCTION(BlueprintCallable, Category = "Simulation")
    void SetTelemetryName(const FString& Name);

    // Initialize (can be called when data is loaded)
    UFUNCTION(BlueprintCallable, Category = "Simulation")
    void SetSimulationData(const FSimulationMetadata& InData);

    // Access functions
    UFUNCTION(BlueprintCallable, Category = "Simulation")
    FSimulationMetadata GetSimulationData() const;

    UFUNCTION(BlueprintCallable, Category = "Simulation")
    TArray<FModelMetadata> GetModelData() const;

    UFUNCTION(BlueprintCallable, Category = "Simulation")
    TArray<FTerrainMetadata> GetTerrainData() const;

    UFUNCTION(BlueprintCallable, Category = "Simulation")
    TArray<FLightData> GetLightData() const;

    // Store all spawned actors
    UPROPERTY(BlueprintReadWrite, Category = "Simulation")
    TMap<FString, AObjectActor*> SpawnedActors;

    // Functions to manage spawned actors
    UFUNCTION(BlueprintCallable, Category = "Simulation")
    void AddSpawnedActor(const FString& ActorID, AObjectActor* Actor);

    UFUNCTION(BlueprintCallable, Category = "Simulation")
    void RemoveSpawnedActor(const FString& ActorID);

    UFUNCTION(BlueprintCallable, Category = "Simulation", BlueprintPure)
    AObjectActor* GetSpawnedActorByID(const FString& ActorID) const;

    UFUNCTION(BlueprintCallable, Category = "Simulation", BlueprintPure)
    TMap<FString, AObjectActor*> GetAllSpawnedActors() const;

    UFUNCTION(BlueprintCallable, Category = "Simulation")
    void ClearAllSpawnedActors();

    UFUNCTION(BlueprintCallable, Category = "Simulation")
    void SetStartTime(float time);

    UFUNCTION(BlueprintCallable, Category = "Simulation")
    void SetEndTime(float time);

    UFUNCTION(BlueprintCallable, Category = "Simulation")
    void AddTelemetryIndex(float time);

    UFUNCTION(BlueprintCallable, Category = "Simulation")
    bool HasSpawnedActor(const FString& ActorID) const;

    UFUNCTION(BlueprintCallable, Category = "Simulation", BlueprintPure)
    int GetSpawnedActorCount() const;

    UFUNCTION(BlueprintCallable, Category = "Simulation", BlueprintPure)
    TArray<AObjectActor*> GetAllSpawnedActorsAsArray() const
    {
        TArray<AObjectActor*> ActorArray;
        SpawnedActors.GenerateValueArray(ActorArray);
        return ActorArray;
    }

    TArray<FObjectsOfInterest> GetObjectsOfInterest() const;

    UPROPERTY(BlueprintAssignable, Category = "Simulation")
    FOnTelemetryUpdated OnTelemetryUpdated;

    UFUNCTION(BlueprintCallable, Category = "Simulation")
    void SetObjectActorVis(bool vis, AObjectActor* Actor);

    //Original MPC2 Stuff
    UPROPERTY(BlueprintReadWrite, Category = "Simulation")
    TMap<float, FTelemetryDataValues> GI_TelemetryData;

    UPROPERTY(BlueprintReadWrite, Category = "Simulation")
    FString GI_ModelID;

    UPROPERTY(BlueprintReadWrite, Category = "Simulation")
    TArray<float> GI_TelemetryTimeIndexes;

    UPROPERTY(BlueprintReadWrite, Category = "Simulation")
    float GI_StartTime;

    UPROPERTY(BlueprintReadWrite, Category = "Simulation")
    float GI_EndTime;

    UPROPERTY(BlueprintReadWrite, Category = "Simulation")
    FString GI_SimFilePath;

    UPROPERTY(BlueprintReadWrite, Category = "Simulation")
    TArray<FString> GI_BookmarksName;

    UPROPERTY(BlueprintReadWrite, Category = "Simulation")
    TArray<FString> GI_BookmarksNotes;

    UPROPERTY(BlueprintReadWrite, Category = "Simulation")
    TArray<FString> GI_BookmarksTime;

    UPROPERTY(BlueprintReadWrite, Category = "Simulation")
    float GI_CurrentTime;

    UPROPERTY(BlueprintReadWrite, Category = "Simulation")
    float GI_BookmarkTime;
};