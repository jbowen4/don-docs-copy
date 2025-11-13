

# File UMPCSocketClient.h

[**File List**](files.md) **>** [**DONToUnreal**](dir_7e70b7b4a1df651b2af4c8dca0b54b92.md) **>** [**Public**](dir_c336ec6675be099178e02bcdcfb186ce.md) **>** [**UMPCSocketClient.h**](_u_m_p_c_socket_client_8h.md)

[Go to the documentation of this file](_u_m_p_c_socket_client_8h.md)


```C++
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

```


