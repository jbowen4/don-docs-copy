

# File Timeline.h

[**File List**](files.md) **>** [**Data**](dir_436819c72972a51f013170f2c377a0ea.md) **>** [**Timeline.h**](_timeline_8h.md)

[Go to the documentation of this file](_timeline_8h.md)


```C++
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
    UTelemetryTimeline();

    void PushTelemetryData(TMap<FString, FObjectState> ObjectStates);

    FObjectInfoStore* FetchTelemetryData(int tlmIndex);

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
```


