

# Class UTelemetryTimeline



[**ClassList**](annotated.md) **>** [**UTelemetryTimeline**](class_u_telemetry_timeline.md)


























## Public Attributes

| Type | Name |
| ---: | :--- |
|  int | [**numTlmElements**](#variable-numtlmelements)  <br> |
















## Public Functions

| Type | Name |
| ---: | :--- |
|  [**FObjectInfoStore**](struct_f_object_info_store.md) \* | [**FetchTelemetryData**](#function-fetchtelemetrydata) (int tlmIndex) <br> |
|  [**FTelemetryFrame**](struct_f_telemetry_frame.md) \* | [**FetchTelemetryFrame**](#function-fetchtelemetryframe) (int tlmIndex) <br> |
|  void | [**PushTelemetryData**](#function-pushtelemetrydata) (TMap&lt; FString, FObjectState &gt; ObjectStates) <br> |
|   | [**UTelemetryTimeline**](#function-utelemetrytimeline) () <br> |




























## Public Attributes Documentation




### variable numTlmElements 

```C++
int UTelemetryTimeline::numTlmElements;
```




<hr>
## Public Functions Documentation




### function FetchTelemetryData 

```C++
FObjectInfoStore * UTelemetryTimeline::FetchTelemetryData (
    int tlmIndex
) 
```



Gets a telemetry frame with the specified index


Throws out-of-range exception with illegal tlmIndex


Access functions for telemetry data 


        

<hr>



### function FetchTelemetryFrame 

```C++
FTelemetryFrame * UTelemetryTimeline::FetchTelemetryFrame (
    int tlmIndex
) 
```



Get a specified telemetry frame


Throws out-of-range exception with illegal tlmIndex 


        

<hr>



### function PushTelemetryData 

```C++
void UTelemetryTimeline::PushTelemetryData (
    TMap< FString, FObjectState > ObjectStates
) 
```



Add a batch of telemetry data to the Timeline at the next index (sequential ordering)


Called from MPC2Loader.cpp while parsing incoming telemetry data


Add a batch of telemetry data to the Timeline at the next index (sequential ordering)


Called from MPC2Loader.cpp while parsing incoming telemetry data Potential behavior is moving telemetry index forward 


        

<hr>



### function UTelemetryTimeline 

```C++
UTelemetryTimeline::UTelemetryTimeline () 
```



Constructor for Timeline object


Called once, object to be attached to SimulationGameInstance


Constructor for Timeline object


Initializes member variables 


        

<hr>

------------------------------
The documentation for this class was generated from the following file `Source/DONToUnreal/Public/Data/Timeline.h`

