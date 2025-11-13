// SimulationLoader.cpp
// Implementation of the SimulationLoader class

#include "SimulationLoader.h"
#include <Engine/DirectionalLight.h>

void ASimulationLoader::InitializeSimulation(bool bImportObjects, const FString& InSimulationPath, const FString& InTelemetryName, const FString& MPCProtocol, const FString& TimeUnit, USimulationGameInstance* MyGameInstance)
{
    UWorld* MyWorld = MyGameInstance->GetWorld();
    FSimulationMetadata SimData;
	FString ConfigFilePath = FPaths::Combine(*InSimulationPath, TEXT("Config.xml"));
	FString TelemetryFilePath = FPaths::Combine(*InSimulationPath, TEXT("/Telemetry"), *InTelemetryName);
	UE_LOG(LogTemp, Log, TEXT("Config file path: %s"), *ConfigFilePath);
	UE_LOG(LogTemp, Log, TEXT("Telemetry file path: %s"), *TelemetryFilePath);

    if (MPCProtocol == "MPC-2")
    {
        // Load simulation config
		UE_LOG(LogTemp, Log, TEXT("Loading simulation config from %s"), *ConfigFilePath);
        bool bSuccess = UMPC2Loader::LoadSimulationConfigMPC2(bImportObjects, InSimulationPath);
        if (!bSuccess)
        {
            UE_LOG(LogTemp, Error, TEXT("Failed to load simulation config from %s"), *ConfigFilePath);
            return;
        }

        // Create simulation metadata
        SimData.Models = UMPC2Loader::GetModelData();
        SimData.Terrains = UMPC2Loader::GetTerrainData();
        SimData.Lights = UMPC2Loader::GetLightData();
        SimData.ObjectsOfInterest = UMPC2Loader::GetObjectsOfInterest();
        SimData.Author = UMPC2Loader::GetAuthor();
		SimData.Name = UMPC2Loader::GetName();
		SimData.Description = UMPC2Loader::GetDescription();
        SimData.TelemetryName = *InTelemetryName;

        MyGameInstance->MPCProtocol = MPCProtocol;

        // Log the data we're about to set
        UE_LOG(LogTemp, Log, TEXT("Setting simulation data: %d models, %d terrains, %d lights"),
            SimData.Models.Num(), SimData.Terrains.Num(), SimData.Lights.Num());
    }
    else if (MPCProtocol == "MPC-3")
    {
        UE_LOG(LogTemp, Error, TEXT("Unsupported MPC protocol: %s"), *MPCProtocol);
        return;
    }

    // Set simulation data 
    try
    {
        MyGameInstance->SetSimulationData(SimData);
        if (TimeUnit == "Seconds") {
            MyGameInstance->TimeUnit = 1.0;
        }
        else {
            MyGameInstance->TimeUnit = 0.1;
        }

    }
    catch (const std::exception& e)
    {
        UE_LOG(LogTemp, Error, TEXT("Exception in SetSimulationData: %s"), UTF8_TO_TCHAR(e.what()));
        return;
    }

	UMPC2Loader::ProcessTelemetryFileMPC2(TelemetryFilePath, MyGameInstance);

    // Spawn simulation loader
    FActorSpawnParameters SpawnParams;
    SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
    ASimulationLoader* SimLoader = MyWorld->SpawnActor<ASimulationLoader>(ASimulationLoader::StaticClass(), FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
    if (!SimLoader)
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to spawn SimulationLoader"));
        return;
    }

    SimLoader->SpawnObjects();

    UE_LOG(LogTemp, Log, TEXT("Simulation initialization completed successfully"));
}


void ASimulationLoader::SpawnObjects()
{
	// Clear existing actors
    SpawnedActors.Empty();

    UE_LOG(LogTemp, Log, TEXT("Spawning simulation objects..."));

    // Get the world
    UWorld* World = GetWorld();
    USimulationGameInstance* GameInstance = Cast<USimulationGameInstance>(World->GetGameInstance());

    TArray<FModelMetadata> Models = GameInstance->GetModelData();
    
    for (FModelMetadata Model : Models)
    {
        SpawnModelActor(World, Model, GameInstance);
    }

    bool PlayerPositionSet = false;
    for (FModelMetadata Model : Models)
    {
        AObjectActor* ModelActor = SetActorParents(World, Model);
        // Teleport player to first object with static parent
        if (ModelActor && ModelActor->isStatic && !PlayerPositionSet)
        {
            APlayerController* PlayerController = UGameplayStatics::GetPlayerController(World, 0);
            APawn* PlayerPawn = PlayerController->GetPawn();
            PlayerPawn->SetActorLocation(ModelActor->GetActorLocation());
            PlayerPositionSet = true;
        }
    }

    for (FObjectsOfInterest Object : GameInstance->GetObjectsOfInterest())
    {
        AObjectActor* Actor = GetSpawnedActorById(Object.Id);
        Actor->IsObjectOfInterest = true;
        Actor->Name = Object.Name;
        UE_LOG(LogTemp, Log, TEXT("Successfully set object of interest ID %s NAME %s:"), *Actor->ObjectId, *Actor->Name);
    }

    UE_LOG(LogTemp, Log, TEXT("Successfully spawned %d model actors"), SpawnedActors.Num());
}


// Handles initial spawning and configuration of model actors
AObjectActor* ASimulationLoader::SpawnModelActor(UWorld* World, const FModelMetadata& Model, USimulationGameInstance* GameInstance)
{
    // Create specialized actor for this model
    FActorSpawnParameters SpawnParams;
    SpawnParams.Name = FName(*Model.Id);
    SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

    AObjectActor* ModelActor = World->SpawnActor<AObjectActor>(SpawnParams);

    USceneComponent* RootComp = NewObject<USceneComponent>(ModelActor, TEXT("RootComponent"));
    ModelActor->SetRootComponent(RootComp);
    RootComp->RegisterComponent();

    // Set the object ID and name
    ModelActor->ObjectId = Model.Id;

    // Add to the map of spawned actors
    SpawnedActors.Add(Model.Id, ModelActor);
    UE_LOG(LogTemp, Log, TEXT("Model ID Name: %s"), *Model.Id);

    if (!Model.StaticParent.IsEmpty())
    {
        UE_LOG(LogTemp, Log, TEXT("Model Static Parent Name: %s"), *Model.StaticParent);
    }

    // Set the actor label in the editor
    ModelActor->SetActorLabel(Model.Id);

    if (GameInstance)
    {
        GameInstance->AddSpawnedActor(Model.Id, ModelActor);
    }

    // Create components for each part
    for (int32 i = 0; i < Model.Components.Num(); i++)
	{	
        const FModelComponentData& Component = Model.Components[i];
        FString MeshName = Component.Filename;
        UStaticMeshComponent* MeshComp;

        // Create directional light for the Sun
        if (MeshName == "Sun")
        {
            // Create directional light for global illumination
            ADirectionalLight* SunLight = World->SpawnActor<ADirectionalLight>();

            // Set light parameters
            SunLight->SetBrightness(50.0f);
            SunLight->SetLightColor(FLinearColor(1.0f, 0.98f, 0.95f));
            SunLight->SetCastShadows(true);

            // Attach the light to the Sun actor
            SunLight->AttachToActor(ModelActor, FAttachmentTransformRules::KeepWorldTransform);
        }

		if (Component.bIsCelestialBody) 
		{
            FString MaterialPath = FString::Printf(TEXT("/Game/Assets/Planets/%s/MI_%s"), *MeshName, *MeshName);
            FString MeshPath = TEXT("/Game/Assets/Planets/SM_CelestialBase");

            UStaticMesh* SphereMesh = LoadObject<UStaticMesh>(nullptr, *MeshPath);

            MeshComp = NewObject<UStaticMeshComponent>(ModelActor, TEXT("CelestialBodyMesh"));

            UMaterialInterface* Material = LoadObject<UMaterialInterface>(nullptr, *MaterialPath);

            MeshComp->SetStaticMesh(SphereMesh);
            MeshComp->SetMaterial(0, Material); // Your function to load the right texture
            MeshComp->SetupAttachment(ModelActor->GetRootComponent());
		}
        else 
        {
            FString MeshPath = FString::Printf(TEXT("/Game/Assets/models/%s/%s.%s"), *MeshName, *MeshName, *MeshName);

            // Load the mesh
            UStaticMesh* Mesh = LoadObject<UStaticMesh>(nullptr, *MeshPath);

            // Create mesh component
            FString ComponentName = FString::Printf(TEXT("MeshComponent_%d"), i);
            MeshComp = NewObject<UStaticMeshComponent>(ModelActor, *ComponentName);
            MeshComp->SetStaticMesh(Mesh);
            MeshComp->SetupAttachment(ModelActor->GetRootComponent());
        }

        ModelActor->SetActorLabel(Model.Id);
        ModelActor->Name = MeshName;

        MeshComp->SetRelativeLocation(Component.Position);
        MeshComp->SetRelativeRotation(Component.Orientation.Rotator());
        MeshComp->SetRelativeScale3D(Component.Scale);

        // Register the component
        MeshComp->RegisterComponent();

        UE_LOG(LogTemp, Log, TEXT("Added component to model %s"), *Model.Id);

    }

    return ModelActor;
}


// Handles setting parent relationships for actors
AObjectActor* ASimulationLoader::SetActorParents(UWorld* World, const FModelMetadata& Model)
{
    // Skip if no valid ID
    if (Model.Id.IsEmpty())
    {
        UE_LOG(LogTemp, Warning, TEXT("Skipping parent setup for model with empty ID"));
        return nullptr;
    }

    // Get the actor for this model
    AObjectActor* ModelActor = nullptr;
    if (SpawnedActors.Contains(Model.Id))
    {
        ModelActor = SpawnedActors[Model.Id];
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Cannot set parent for %s - actor not found"), *Model.Id);
        return nullptr;
    }

    // Handle parent relationship
    if (!Model.StaticParent.IsEmpty())
    {
        if (SpawnedActors.Contains(Model.StaticParent))
        {
            ModelActor->isStatic = true;
            ModelActor->SetActorLocation(Model.StaticPosition);
            ModelActor->SetActorRotation(Model.StaticOrientation.Rotator());
            ModelActor->SetActorScale3D(Model.StaticScale);

            AObjectActor* ParentActor = SpawnedActors[Model.StaticParent];
            ModelActor->AttachToActor(ParentActor, FAttachmentTransformRules::KeepRelativeTransform);
            UE_LOG(LogTemp, Log, TEXT("Set parent for %s -> %s"), *Model.Id, *Model.StaticParent);
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Parent %s for model %s not found in spawned actors"),
                *Model.StaticParent, *Model.Id);
        }
    }
    else
    {
        if (!Model.DynamicParent.IsEmpty() && SpawnedActors.Contains(Model.DynamicParent))
        {
            AObjectActor* ParentActor = SpawnedActors[Model.DynamicParent];

            // You might want different attachment rules for dynamic objects
            ModelActor->AttachToActor(ParentActor, FAttachmentTransformRules::KeepRelativeTransform);
            UE_LOG(LogTemp, Log, TEXT("Set dynamic parent for %s -> %s"), *Model.Id, *Model.DynamicParent);
        }
    }

    return ModelActor;
}


// Teleport the player pawn to a specific object and automatically adjust distance depending on size of object
void ASimulationLoader::TeleportToObject(AObjectActor* TargetObject, APawn* PlayerPawn)
{
    if (!TargetObject || !PlayerPawn)
    {
        UE_LOG(LogTemp, Warning, TEXT("TeleportToObject: Invalid target object or player pawn"));
        return;
    }

    // Get the object's bounds to determine its size
    FVector Origin;
    FVector BoxExtent;  
    TargetObject->GetActorBounds(false, Origin, BoxExtent, true);

    // Use the BoxExtent to calculate a sphere radius
    float SphereRadius = BoxExtent.GetMax();

    // Calculate appropriate viewing distance based on radius
    float ViewingDistance = SphereRadius * 2.0f;

    // Ensure minimum viewing distance
    ViewingDistance = FMath::Min(ViewingDistance, 10000.0f);

    // Calculate teleport position
    FVector TeleportOffset = FVector(1.0f, 1.0f, 0.5f).GetSafeNormal() * ViewingDistance;
    FVector TeleportPosition = TeleportOffset;

    // Teleport the player pawn directly
    PlayerPawn->SetActorLocation(TeleportPosition);

    UE_LOG(LogTemp, Log, TEXT("Successfully teleported player to %s"), *TargetObject->ObjectId);
}


AObjectActor* ASimulationLoader::GetSpawnedActorById(const FString& ActorId)
{
    if (SpawnedActors.Contains(ActorId))
    {
        return SpawnedActors[ActorId];
    }
    return nullptr;
}


TMap<FString, AObjectActor*> ASimulationLoader::GetAllSpawnedActors() const
{
    return SpawnedActors;
}


TArray<FString> ASimulationLoader::GetAllModelIds() const
{
    TArray<FString> ModelIds;

    // Extract all keys from the SpawnedActors map
    SpawnedActors.GetKeys(ModelIds);

    return ModelIds;
}
