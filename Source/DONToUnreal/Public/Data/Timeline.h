#pragma once

#include "CoreMinimal.h"
#include "Data/ObjectInfoStore.h"
#include "Data/ObjectInfo.h"
#include "DataTypes.h"
#include <vector>
#include <stdexcept>

struct FTelemetryFrame
{
    // Currently just a wrapper to ObjectInfoStore
    // Allows extensibility.

    FObjectInfoStore TelemetryData;
};

class DONTOUNREAL_API UTelemetryTimeline
{
public:
    /**
     *  Constructor for Timeline object
     *
     *  Called once, object to be attached to SimulationGameInstance
     */
    UTelemetryTimeline();

    /**
     * Add a batch of telemetry data to the Timeline at the next index (sequential ordering)
     *
     * Called from MPC2Loader.cpp while parsing incoming telemetry data
     */
    void PushTelemetryData(TMap<FString, FObjectState> ObjectStates);

    /**
     * Gets a telemetry frame with the specified index
     * 
     * Throws out-of-range exception with illegal tlmIndex
     */
    FObjectInfoStore* FetchTelemetryData(int tlmIndex);

    /**
     * Get a specified telemetry frame
     * 
     * Throws out-of-range exception with illegal tlmIndex
     */
    FTelemetryFrame* FetchTelemetryFrame(int tlmIndex);

private:
    // Internals for use ObjectInfoStore is indev
    FTelemetryFrame* UTelemetryTimeline::BuildInitialTelemetryFrame(TMap<FString, FObjectState>& ObjectStates);

    FTelemetryFrame* UTelemetryTimeline::ConstructTelemetryFrame(TMap<FString, FObjectState>& ObjectStates);

    // Instance variables
public: 
    int numTlmElements;

private:
    TArray<FTelemetryFrame*> Timeline;

};