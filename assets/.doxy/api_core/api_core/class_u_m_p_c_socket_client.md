

# Class UMPCSocketClient



[**ClassList**](annotated.md) **>** [**UMPCSocketClient**](class_u_m_p_c_socket_client.md)








Inherits the following classes: UGameInstanceSubsystem


































## Public Functions

| Type | Name |
| ---: | :--- |
|  bool | [**ConnectToServer**](#function-connecttoserver) (const FString & IPAddress, const FString & FileName, int32 Port, bool bImportModels, const FString & RecordingDirectory) <br> |
|  void | [**Deinitialize**](#function-deinitialize) () override<br> |
|  void | [**DisconnectFromServer**](#function-disconnectfromserver) () <br> |
|  void | [**Initialize**](#function-initialize) (FSubsystemCollectionBase & Collection) override<br> |
|  void | [**InitializeNetworkSimulation**](#function-initializenetworksimulation) (const FString & IPAddress, const FString & FileName, int32 Port, bool bImportObjects, const FString & SimulationDirectory, const FString & RecordingDirectory, const FString & MPCProtocol, const FString & TimeUnit) <br> |




























## Public Functions Documentation




### function ConnectToServer 

```C++
bool UMPCSocketClient::ConnectToServer (
    const FString & IPAddress,
    const FString & FileName,
    int32 Port,
    bool bImportModels,
    const FString & RecordingDirectory
) 
```




<hr>



### function Deinitialize 

```C++
void UMPCSocketClient::Deinitialize () override
```




<hr>



### function DisconnectFromServer 

```C++
void UMPCSocketClient::DisconnectFromServer () 
```




<hr>



### function Initialize 

```C++
void UMPCSocketClient::Initialize (
    FSubsystemCollectionBase & Collection
) override
```




<hr>



### function InitializeNetworkSimulation 

```C++
void UMPCSocketClient::InitializeNetworkSimulation (
    const FString & IPAddress,
    const FString & FileName,
    int32 Port,
    bool bImportObjects,
    const FString & SimulationDirectory,
    const FString & RecordingDirectory,
    const FString & MPCProtocol,
    const FString & TimeUnit
) 
```




<hr>

------------------------------
The documentation for this class was generated from the following file `Source/DONToUnreal/Public/UMPCSocketClient.h`

