// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataTypes.h" 
#include "Subsystems/GameInstanceSubsystem.h"
#include "UMPCSocketClient.generated.h" 

UCLASS()
class DONTOUNREAL_API UMPCSocketClient : public UGameInstanceSubsystem
{
    GENERATED_BODY()

public:
    void Initialize(FSubsystemCollectionBase& Collection) override;
    void Deinitialize() override;
    UFUNCTION(BlueprintCallable, Category = "MPC Socket")
    bool ConnectToServer(const FString& IPAddress, const FString& FileName, int32 Port, bool bImportModels, const FString& RecordingDirectory);

    UFUNCTION(BlueprintCallable, Category = "MPC Socket")
    void DisconnectFromServer();

    UFUNCTION(BlueprintCallable, Category = "MPC Socket")
    void InitializeNetworkSimulation(const FString& IPAddress, const FString& FileName, int32 Port, bool bImportObjects, 
        const FString& SimulationDirectory, const FString& RecordingDirectory, const FString& MPCProtocol, const FString& TimeUnit);

private:
    class FSocketClientThread* ClientThread = nullptr;
    FRunnableThread* Thread = nullptr;
    FCriticalSection ConnectionMutex;
    bool bIsConnectingOrConnected = false;
    bool bImportModels = true;
};

