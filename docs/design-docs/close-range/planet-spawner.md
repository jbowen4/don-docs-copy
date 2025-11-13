## Overview

The Planet Spawner is an Unreal Object (UObject) that is used to spawn and unspawn
Cesium planets in the simulations.

## PlanetSpawner.h File Code

```cpp
#pragma once

#include "Cesium3DTileset.h"
#include "CesiumGeoreference.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlanetSpawner.generated.h"

UCLASS()
class DONTOUNREAL_API UPlanetSpawner : public UObject
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	UPlanetSpawner();

	UFUNCTION(BlueprintCallable, Category = "Cesium")
	void SpawnPlanetAtLocation(UWorld* world, const FVector& position, int assetId);

	void UpdatePlanetPosition(const FVector& position);

	void UnspawnPlanet();

	UPROPERTY(EditAnywhere)
	ACesiumGeoreference* GeoreferenceActor;  // assign in editor

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ACesium3DTileset* CurrentPlanet;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector LastPlayerLocation;
};
```

## PlanetSpawner.cpp File Code

```cpp
#include "Level/Placement/Planetary/PlanetSpawner.h"

// Sets default values
UPlanetSpawner::UPlanetSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.

}

void UPlanetSpawner::SpawnPlanetAtLocation(UWorld* world, const FVector& position, int assetId)
{
    //GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Green, TEXT("[PlanetSpawner] Entered the SpawnPlanetAtLocation function!"));

    // If we already have a planet, destroy it before spawning a new one
    if (CurrentPlanet) {
        UE_LOG(LogTemp, Warning, TEXT("[PlanetSpawner] Destroying existing planet before spawning a new one."));
        CurrentPlanet->Destroy();
        CurrentPlanet = nullptr;
    }

    if (!GeoreferenceActor)
    {
        // None found in level, spawn one
        GeoreferenceActor = world->SpawnActor<ACesiumGeoreference>();

        // Align planets with their billboard equivalents by default
        GeoreferenceActor->SetOriginLongitude(90.0);
        GeoreferenceActor->SetOriginLatitude(90.0);
    }

    // Spawn the Cesium3DTileset actor
    FActorSpawnParameters SpawnParams;
    ACesium3DTileset* NewPlanet = world->SpawnActor<ACesium3DTileset>(
         ACesium3DTileset::StaticClass(),
         position,
         FRotator::ZeroRotator,
         SpawnParams
     );

    if (NewPlanet)
    {
        // Set tileset from Cesium ion
        NewPlanet->SetTilesetSource(ETilesetSource::FromCesiumIon);
        NewPlanet->SetIonAssetID(assetId);
        NewPlanet->SetIonAccessToken(TEXT("eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJqdGkiOiI0ZGE0Y2Q2OS0zZjNiLTQwNzMtOTI3My03OGFlMTI1MTZmMWYiLCJpZCI6MzE0NDcyLCJpYXQiOjE3NjE4NTk2NTl9.wZNQjsPeLJsGYJEZxEmbs75khMyPXLCu5ttDWw5wOK8"));
        NewPlanet->RefreshTileset();

        NewPlanet->SetGenerateSmoothNormals(true);

        // Disable collisions
        NewPlanet->SetActorEnableCollision(false);

        UE_LOG(LogTemp, Log, TEXT("Planet spawned at %s"), *position.ToString());

        CurrentPlanet = NewPlanet; // Save reference
    }

    if (GeoreferenceActor)
    {
        // Set active georeference for this planet.
        NewPlanet->SetGeoreference(GeoreferenceActor);
    }
}

void UPlanetSpawner::UpdatePlanetPosition(const FVector& position)
{
    if (CurrentPlanet)
    {
        CurrentPlanet->SetActorLocation(position);
    }
    else
    {
        // Planet does not exist
        UE_LOG(LogTemp, Error, TEXT("[PlanetSpawner] Could not update planet position: Planet not present."));
    }
}

void UPlanetSpawner::UnspawnPlanet()
{
    if (CurrentPlanet) {
        UE_LOG(LogTemp, Warning, TEXT("[PlanetSpawner] Unspawning current planet..."));
        GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("[PlanetSpawner] Unspawning planet..."));

        if (CurrentPlanet->Destroy()) {
            CurrentPlanet = nullptr;
        }
    }
}
```
