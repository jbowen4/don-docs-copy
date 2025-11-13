

# File Timeline.cpp

[**File List**](files.md) **>** [**Data**](dir_c6f65c82417afbaa7503bbb02bffcee2.md) **>** [**Timeline.cpp**](_timeline_8cpp.md)

[Go to the documentation of this file](_timeline_8cpp.md)


```C++
#include "Data/Timeline.h"

UTelemetryTimeline::UTelemetryTimeline()
{
    numTlmElements = 0;
}

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
```


