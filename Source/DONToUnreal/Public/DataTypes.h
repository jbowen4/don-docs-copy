// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "CoreMinimal.h"
#include "DataTypes.generated.h"

USTRUCT(BlueprintType)
struct FModelComponentData
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Filename;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FVector Position;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FQuat Orientation;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FVector Scale;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bIsCelestialBody = false;
};

USTRUCT(BlueprintType)
struct FModelMetadata
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Id;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bStatic = false;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FVector StaticPosition;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FQuat StaticOrientation;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FVector StaticScale;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString StaticParent;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString DynamicParent;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FModelComponentData> Components;

    // Conversion functions for coordinate system transformations
    FVector ConvertPositionToUnreal() const;
    FQuat ConvertOrientationToUnreal() const;
    FVector ConvertScaleToUnreal() const;
};

USTRUCT(BlueprintType)
struct FObjectsOfInterest
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Id;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Name;
};

USTRUCT(BlueprintType)
struct FTerrainMetadata
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Id;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FVector Position;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FQuat Orientation;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Parent;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FVector TerrainOffset;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FVector Tiling;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Source;

    // Conversion functions
    FVector ConvertPositionToUnreal() const;
    FQuat ConvertOrientationToUnreal() const;
};

USTRUCT(BlueprintType)
struct FLightData
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Name;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Parent;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString type;
};

USTRUCT(BlueprintType)
struct FSimulationMetadata
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FModelMetadata> Models;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FTerrainMetadata> Terrains;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FLightData> Lights;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FObjectsOfInterest> ObjectsOfInterest;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Name;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TelemetryName = "Network";
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString TimeUnit = "Seconds";
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString SpaceUnit = "Meters";
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Description;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Author;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float StartTime = 0;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float EndTime = 0;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<float> TelemetryTimeIndexes;
};

USTRUCT(BlueprintType)
struct FObjectState
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ID;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FVector Velocity;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FVector Position;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FVector Scale;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FQuat Rotation;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString ParentID;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bIsVisible = true;

    // Conversion functions
    
    FVector ConvertPositionToUnreal() const;
    FVector ConvertVelocityToUnreal() const;
    FQuat ConvertRotationToUnreal() const;
};

USTRUCT(BlueprintType)
struct FTimeSnapshot
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    double TimeValue;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TMap<FString, FObjectState> ObjectStates;
};

USTRUCT(BlueprintType)
struct FTelemetryDataKey
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString Id;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Time;
};

USTRUCT(BlueprintType)
struct FTelemetryData
{
    GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString Id;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FTransform Transformation;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int Visibility;
};

USTRUCT(BlueprintType)
struct FTelemetryDataValues
{
	GENERATED_BODY()
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    float Time;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FTelemetryData> Data;
};