// USimulationGameInstance.cpp
#include "SimulationGameInstance.h"

void USimulationGameInstance::SetSimulationData(const FSimulationMetadata& InData)
{
    SimulationData = InData;
    UE_LOG(LogTemp, Log, TEXT("Simulation data set in GameInstance: %d models, %d terrains, %d lights"),
        SimulationData.Models.Num(), SimulationData.Terrains.Num(), SimulationData.Lights.Num());
}

void USimulationGameInstance::SetTelemetryDataBroadcast(const double time, TMap<FString, FObjectState> ObjectStates)
{
    FTimeSnapshot NewTelemetryData;
	NewTelemetryData.TimeValue = time;
	NewTelemetryData.ObjectStates = ObjectStates;
	TelemetryData.Add(time, NewTelemetryData);
    
    //for (const auto& Pair : ObjectStates)
    //{
    //    const FString& ObjectID = Pair.Key; 
    //    const FObjectState& ObjectState = Pair.Value; 

    //    AObjectActor* ModelActor = GetSpawnedActorByID(ObjectID);
    //    AObjectActor* ParentActor = GetSpawnedActorByID(ObjectState.ParentID);

    //    if (!ModelActor || !ParentActor) continue;

    //    AObjectActor* AttachParentActor = Cast<AObjectActor>(ModelActor->GetAttachParentActor());

    //    if (!AttachParentActor || AttachParentActor->ObjectId != ObjectState.ParentID)
    //    {
    //        ModelActor->AttachToActor(ParentActor, FAttachmentTransformRules::KeepRelativeTransform);
    //    }
    //}

	OnTelemetryUpdated.Broadcast(time);
	UE_LOG(LogTemp, Log, TEXT("Telemetry data set for time: %f"), time);
}


void USimulationGameInstance::SetTelemetryData(const double time, TMap<FString, FObjectState> ObjectStates)
{
    FTimeSnapshot NewTelemetryData;
    NewTelemetryData.TimeValue = time;
    NewTelemetryData.ObjectStates = ObjectStates;
    SimulationData.TelemetryTimeIndexes.Add(time);
    TelemetryData.Add(time, NewTelemetryData);

    UE_LOG(LogTemp, Log, TEXT("Telemetry data set for time: %f"), time);
}

FSimulationMetadata USimulationGameInstance::GetSimulationData() const
{
    return SimulationData;
}

TArray<FModelMetadata> USimulationGameInstance::GetModelData() const
{
    return SimulationData.Models;
}

TArray<FTerrainMetadata> USimulationGameInstance::GetTerrainData() const
{
    return SimulationData.Terrains;
}

TArray<FLightData> USimulationGameInstance::GetLightData() const
{
    return SimulationData.Lights;
}

TArray<FObjectsOfInterest> USimulationGameInstance::GetObjectsOfInterest() const
{
    return SimulationData.ObjectsOfInterest;
}

void USimulationGameInstance::SetObjectActorVis(bool vis, AObjectActor* Actor)
{
	if (Actor)
	{
		Actor->vis = vis;
	}
}

void USimulationGameInstance::SetStartTime(float time)
{
    SimulationData.StartTime = time;
}

void USimulationGameInstance::SetEndTime(float time)
{
    SimulationData.EndTime = time;
}

void USimulationGameInstance::SetTelemetryName(const FString& Name)
{
    SimulationData.TelemetryName = Name;
}

void USimulationGameInstance::AddTelemetryIndex(float time)
{
	SimulationData.TelemetryTimeIndexes.Add(time);
}

void USimulationGameInstance::AddSpawnedActor(const FString& ActorID, AObjectActor* Actor)
{
    if (Actor)
    {
        SpawnedActors.Add(ActorID, Actor);
    }
}

void USimulationGameInstance::RemoveSpawnedActor(const FString& ActorID)
{
    SpawnedActors.Remove(ActorID);
}

AObjectActor* USimulationGameInstance::GetSpawnedActorByID(const FString& ActorID) const
{
    if (SpawnedActors.Contains(ActorID))
    {
        return SpawnedActors[ActorID];
    }
    return nullptr;
}

TMap<FString, AObjectActor*> USimulationGameInstance::GetAllSpawnedActors() const
{
    return SpawnedActors;
}

void USimulationGameInstance::ClearAllSpawnedActors()
{
    SpawnedActors.Empty();
}

bool USimulationGameInstance::HasSpawnedActor(const FString& ActorID) const
{
    return SpawnedActors.Contains(ActorID);
}

int USimulationGameInstance::GetSpawnedActorCount() const
{
    return SpawnedActors.Num();
}


