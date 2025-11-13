#include "Data/Timeline.h"

/**
 *  Constructor for Timeline object
 *
 *  Initializes member variables
 */
UTelemetryTimeline::UTelemetryTimeline()
{
    numTlmElements = 0;
}

/**
 * Add a batch of telemetry data to the Timeline at the next index (sequential ordering)
 *
 * Called from MPC2Loader.cpp while parsing incoming telemetry data
 * Potential behavior is moving telemetry index forward
 */
void UTelemetryTimeline::PushTelemetryData(TMap<FString, FObjectState> ObjectStates)
{
    FTelemetryFrame* newFrame;
    
    if (numTlmElements > 0)
    {
        newFrame = ConstructTelemetryFrame(ObjectStates);
    }
    else
    {
        newFrame = BuildInitialTelemetryFrame(ObjectStates);
    }

    Timeline.Push(newFrame);

    UE_LOG(LogCore, Log, TEXT("Created ObjectInfoStore instance with data:\n %s"), *newFrame->TelemetryData.ToString());

    numTlmElements++;
}

/**
 * Access functions for telemetry data
 */
FObjectInfoStore* UTelemetryTimeline::FetchTelemetryData(int tlmIndex)
{
    if (!UTelemetryTimeline::Timeline.IsValidIndex(tlmIndex))
    {
        throw std::out_of_range("Illegal telemetry index access");
    }

    return &(UTelemetryTimeline::Timeline[tlmIndex]->TelemetryData);
}

FTelemetryFrame* UTelemetryTimeline::FetchTelemetryFrame(int tlmIndex)
{
    if (!UTelemetryTimeline::Timeline.IsValidIndex(tlmIndex))
    {
        throw std::out_of_range("Illegal telemetry index access");
    }

    return UTelemetryTimeline::Timeline[tlmIndex];
}

/**
 * Create the first telemetry frame using ObjectInfoStore builder
 */
FTelemetryFrame* UTelemetryTimeline::BuildInitialTelemetryFrame(TMap<FString, FObjectState>& ObjectStates)
{
    if (UTelemetryTimeline::numTlmElements != 0)
    {
        throw FString::Printf(TEXT("Attempted to build duplicate initial telemetry frame"));
    }

    auto objectBuilder = FObjectInfoStore::Builder();
    FTelemetryFrame* outputFrame = new FTelemetryFrame;

    for (auto& Object : ObjectStates)
    {
        auto& IncomingObject = Object.Value;

        ObjID Name = FName(IncomingObject.ID);
        ObjID ParentName = FName(IncomingObject.ParentID);

        const FVector Position = IncomingObject.Position;
        const FQuat Orientation = IncomingObject.Rotation;
        bool Visibility = IncomingObject.bIsVisible;

        TOptional<ObjID> ParentNameOpt = TOptional(ParentName);

        if (IncomingObject.ParentID == "")
        {
            ParentNameOpt.Reset();
        }

        objectBuilder.AddObject(Name, ParentNameOpt, Position, Orientation, Visibility);
    }

    objectBuilder.Build(outputFrame->TelemetryData);

    return outputFrame;
}

/**
 * Create all subsequent telemetry frames:
 * Copy the previous telemetry frame,
 * Update any subsequent frames as needed.
 */
FTelemetryFrame* UTelemetryTimeline::ConstructTelemetryFrame(TMap<FString, FObjectState>& ObjectStates)
{
    if (UTelemetryTimeline::numTlmElements == 0)
    {
        throw FString::Printf(TEXT("Attempted to build subsequent telemetry frames without executing a copy"));
    }

    FTelemetryFrame* outputFrame = new FTelemetryFrame;

    // Call the copy constructor
    auto builder = FObjectInfoStore::CopyBuilder(Timeline[UTelemetryTimeline::numTlmElements - 1]->TelemetryData);
    

    // Update all previous frames
    for (auto& Object : ObjectStates)
    {
        auto& IncomingObject = Object.Value;

        const FVector Position = IncomingObject.Position;
        const FQuat Orientation = IncomingObject.Rotation;

        builder.UpdateInfo(FName(IncomingObject.ID), TOptRef(TOptional(FName(IncomingObject.ParentID))), // TODO make this empty when the parent is the origin
            TOptRef(Position), TOptRef(Orientation), IncomingObject.bIsVisible);
    }
    
    builder.Build(outputFrame->TelemetryData);

    return outputFrame;
}