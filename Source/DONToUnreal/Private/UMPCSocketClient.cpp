// Fill out your copyright notice in the Description page of Project Settings.


#include "UMPCSocketClient.h"
#include "SocketSubsystem.h"
#include "Sockets.h"
#include "SimulationLoader.h"
#include "FileRecorder.h"
#include "HAL/Runnable.h"
#include "HAL/RunnableThread.h"
#include "MPC2Loader.h"
#include <Async/Async.h>

// Separate FRunnable class for the thread
class FSocketClientThread : public FRunnable
{
public:
    FSocketClientThread(const FString& InAddress, FString InFileName, int32 InPort, UGameInstance* InBaseGameInstance, const FString& InRecordingDirectory)
        : Address(InAddress), Port(InPort), Socket(nullptr), bStopRequested(false), FileName(InFileName), BaseGameInstance(InBaseGameInstance), RecordingDirectory(InRecordingDirectory){}

    virtual uint32 Run() override;
    virtual void Stop() override;
    virtual void Exit() override {}
    virtual bool Init() override { return true; }
    void ProcessTimeTagMPC2(const FString& TimeTagXML, UGameInstance* BaseGameInstance);

private:
    FString FileName;
    FString RecordingDirectory;
    FString Address;
    int32 Port;
    UGameInstance* BaseGameInstance;
    FSocket* Socket;
    FThreadSafeBool bStopRequested;
};

uint32 FSocketClientThread::Run()
{
    bStopRequested = false;
    // Create socket inside of thread
    ISocketSubsystem* SocketSubsystem = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM);
    if (!SocketSubsystem)
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to get socket subsystem"));
        return 1; // Indicate failure
    }

    Socket = SocketSubsystem->CreateSocket(NAME_Stream, TEXT("ClientSocket"), false);

    if (!Socket)
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to create socket"));
        return 1;
    }

    // Convert address and port to standardized InternetAddr format 
    TSharedRef<FInternetAddr> Addr = SocketSubsystem->CreateInternetAddr();
    bool bIsValid;
    Addr->SetIp(*Address, bIsValid);
    Addr->SetPort(Port);
    if (!bIsValid)
    {
        UE_LOG(LogTemp, Error, TEXT("Invalid address: %s"), *Address);
        // Clean up socket
        SocketSubsystem->DestroySocket(Socket);
        Socket = nullptr;
        return 1; // Indicate failure
    }

    // Connect to socket
    bool bConnected = Socket->Connect(*Addr);

    if (bConnected)
    {
        UE_LOG(LogTemp, Log, TEXT("Thread: Connected to server."));
        FileRecorder* fileWriter = new FileRecorder(*FileName, *RecordingDirectory);
        // 4. Receive Data 
        uint8 Buffer[1024];
        TArray<uint8> AccumulatedBuffer;
        int32 BytesRead;
        bool startTimeTag = false;

        while (!bStopRequested && Socket->GetConnectionState() == SCS_Connected) // Check for stop request and connection
        {
            if (Socket->Wait(ESocketWaitConditions::WaitForRead, FTimespan::FromSeconds(0.1))) // Wait for data to be available, or to timeout
            {
                FMemory::Memzero(Buffer, sizeof(Buffer));
                bool bSuccess = Socket->Recv(Buffer, sizeof(Buffer), BytesRead);
      
                if (!bSuccess || BytesRead == 0) {
                    UE_LOG(LogTemp, Warning, TEXT("Recv failed."));
                    break; //Exit if failed
                }

                // Loop through each new byte to ensure we catch tags as soon as they appear
                for (int32 Index = 0; Index < BytesRead; ++Index)
                {
                    // Add the received byte to our accumulation buffer
                    AccumulatedBuffer.Add(Buffer[Index]);

                    // Create a null-terminated string from the buffer for searching
                    TArray<uint8> SearchBuffer = AccumulatedBuffer;
                    SearchBuffer.Add(0); // Add null terminator
                    FString CurrentBuffer = FString(UTF8_TO_TCHAR(reinterpret_cast<const char*>(SearchBuffer.GetData())));

                    // Check for a complete message
                    if (startTimeTag == false && CurrentBuffer.EndsWith(TEXT("<time")))
                    {
                        //UE_LOG(LogTemp, Log, TEXT("Thread: Start time tag detected"));
                        startTimeTag = true; // start time tag recieved, will not process data till end time tag is found
                    }
                    else if (startTimeTag == true && CurrentBuffer.EndsWith(TEXT("</time>")))
                    {
                        //UE_LOG(LogTemp, Log, TEXT("Thread: End time tag recieved: %s"), *CurrentBuffer);
                        startTimeTag = false;
                        fileWriter->AppendXML(CurrentBuffer);
						ProcessTimeTagMPC2(CurrentBuffer, BaseGameInstance); // Process the time tag to extract time and object states
                        AccumulatedBuffer.Empty(); // Clear the accumulation buffer for the next message
                    }
                    else if (startTimeTag == false && CurrentBuffer.EndsWith(TEXT("?>")))
                    {
                        //UE_LOG(LogTemp, Log, TEXT("Thread: xml version tag recieved: %s"), *CurrentBuffer);
                        fileWriter->AppendXML(CurrentBuffer);
                        AccumulatedBuffer.Empty(); // Clear the accumulation buffer for the next message
                    }
                    else if (startTimeTag == false && CurrentBuffer.EndsWith(TEXT("</metadata>")))
                    {
                        //UE_LOG(LogTemp, Log, TEXT("Thread: Complete metadata tag received: %s"), *CurrentBuffer);
                        fileWriter->AppendXML(CurrentBuffer);
                        AccumulatedBuffer.Empty(); // Clear the accumulation buffer for the next message
                    }
                    else if (startTimeTag == false && CurrentBuffer.EndsWith(TEXT("<mpc>")))
                    {
                        //UE_LOG(LogTemp, Log, TEXT("Thread: mpc openeing tag recieved: %s"), *CurrentBuffer);
                        fileWriter->AppendXML(CurrentBuffer);
                        AccumulatedBuffer.Empty(); // Clear the accumulation buffer for the next message
                    }
                }
            }
        }
        fileWriter->AppendXML(TEXT("</mpc>"));
        fileWriter->CloseWriter();
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Thread: Connection failed."));
    }


    // Clean up if fail or stream ended
    if (Socket)
    {
        Socket->Close();
        SocketSubsystem->DestroySocket(Socket);
        Socket = nullptr; // Set to nullptr after destroying.
    }


    return 0; // Return 0 for success
}

// Forcefully close the connection if needed prior to stream end
void FSocketClientThread::Stop()
{
    bStopRequested = true;
    if (Socket)
    {
        Socket->Close();
    }
}

void UMPCSocketClient::Initialize(FSubsystemCollectionBase& Collection)
{
    Super::Initialize(Collection);
}

void UMPCSocketClient::Deinitialize() {
    DisconnectFromServer();
    Super::Deinitialize();
}

bool UMPCSocketClient::ConnectToServer(const FString& IPAddress, const FString& FileName, int32 Port, bool bImportObjects, const FString& RecordingDirectory)
{
    // Prevent connecting multiple times
    FScopeLock Lock(&ConnectionMutex);
    if (ClientThread != nullptr || Thread != nullptr) {
        UE_LOG(LogTemp, Warning, TEXT("Already connected or connecting."));
        return false;
    }

    UMPCSocketClient::bImportModels = bImportObjects;

    ClientThread = new FSocketClientThread(IPAddress, FileName, Port, GetGameInstance(), RecordingDirectory); // Create the runnable object 
    Thread = FRunnableThread::Create(ClientThread, TEXT("MPCSocketThread")); // Create the thread with runnable object 

    // Failed to create thread, perform cleanup
    if (!Thread)
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to create thread."));
        delete ClientThread;
        ClientThread = nullptr;
        bIsConnectingOrConnected = false;
        return false;
    }
    return true;
}

void UMPCSocketClient::DisconnectFromServer()
{

    if (ClientThread)
    {
        UE_LOG(LogTemp, Log, TEXT("Stopping Client"));
        ClientThread->Stop(); //Signal to stop
    }

    if (Thread)
    {
        UE_LOG(LogTemp, Log, TEXT("Deleting Thread"));
        Thread->WaitForCompletion(); // Wait for the thread to finish
        delete Thread;
        Thread = nullptr;
    }

    if (ClientThread)
    {
        UE_LOG(LogTemp, Log, TEXT("Deleting Client"));
        delete ClientThread; //Clean up
        ClientThread = nullptr;
    }

    FScopeLock Lock(&ConnectionMutex);
    bIsConnectingOrConnected = false;
}


void FSocketClientThread::ProcessTimeTagMPC2(const FString& TimeTagXML, UGameInstance* InBaseGameInstance)
{
    // Parse XML to extract time value and object states
    double TimeValue = UMPC2Loader::ExtractTimeValueMPC2(TimeTagXML);

    // Create a new snapshot
    FTimeSnapshot NewSnapshot;
    NewSnapshot.TimeValue = TimeValue;

    // Convert FString to std::string for tinyxml2
    std::string XmlStr = TCHAR_TO_UTF8(*TimeTagXML);

    // Parse the XML
    tinyxml2::XMLDocument Doc;
    tinyxml2::XMLError Error = Doc.Parse(XmlStr.c_str());
    if (Error != tinyxml2::XML_SUCCESS)
    {
        UE_LOG(LogTemp, Warning, TEXT("Failed to parse XML: %s"), *FString(Doc.ErrorStr()));
        return;
    }

    // Get the time element
    tinyxml2::XMLElement* TimeElement = Doc.FirstChildElement("time");
    if (!TimeElement)
    {
        UE_LOG(LogTemp, Warning, TEXT("Failed to find time element in XML"));
        return;
    }

    // Extract all object states from XML
    TMap<FString, FObjectState> ObjectStates = UMPC2Loader::ExtractObjectStatesMPC2(TimeElement);

    NewSnapshot.ObjectStates = ObjectStates;

    USimulationGameInstance* MyGameInstance = Cast<USimulationGameInstance>(InBaseGameInstance);

    // Add to telemetry data (potentially on Game Thread)
    AsyncTask(ENamedThreads::GameThread, [this, NewSnapshot, MyGameInstance]() {
		MyGameInstance->SetTelemetryDataBroadcast(NewSnapshot.TimeValue, NewSnapshot.ObjectStates);

        if (MyGameInstance->Timeline == NULL)
        {
            MyGameInstance->Timeline = new UTelemetryTimeline();
        }

        MyGameInstance->Timeline->PushTelemetryData(NewSnapshot.ObjectStates);
        });
}


void UMPCSocketClient::InitializeNetworkSimulation(const FString& IPAddress, const FString& FileName, int32 Port, bool bImportObjects, const FString& SimulationDirectory, const FString& RecordingDirectory, const FString& MPCProtocol, const FString& TimeUnit)
{
    FString ConfigFilePath = FPaths::Combine(*SimulationDirectory, "Config" + FString(TEXT(".xml")));
    FSimulationMetadata SimData;

    // Get game instance with null check
    UGameInstance* BaseGameInstance = GetGameInstance();
    if (!BaseGameInstance)
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to get base game instance"));
        return;
    }

    USimulationGameInstance* MyGameInstance = Cast<USimulationGameInstance>(BaseGameInstance);
    if (!MyGameInstance)
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to cast to USimulationGameInstance"));
        return;
    }

	if (MPCProtocol == "MPC-2")
	{
        // Load simulation config
        bool bSuccess = UMPC2Loader::LoadSimulationConfigMPC2(bImportObjects, SimulationDirectory);
        if (!bSuccess)
        {
            UE_LOG(LogTemp, Error, TEXT("Failed to load simulation config from %s"), *ConfigFilePath);
            return;
        }

        // Connect to server
        ConnectToServer(IPAddress, FileName, Port, bImportObjects, RecordingDirectory);

        // Create simulation metadata
        SimData.Models = UMPC2Loader::GetModelData();
        SimData.Terrains = UMPC2Loader::GetTerrainData();
        SimData.Lights = UMPC2Loader::GetLightData();
        SimData.ObjectsOfInterest = UMPC2Loader::GetObjectsOfInterest();
        SimData.Author = UMPC2Loader::GetAuthor();
        SimData.Name = UMPC2Loader::GetName();
        SimData.Description = UMPC2Loader::GetDescription();

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

    // Set simulation data with error handling
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

    // Spawn simulation loader
    UWorld* MyWorld = GetWorld();
    if (!MyWorld)
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to get world"));
        return;
    }

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