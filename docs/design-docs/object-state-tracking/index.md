![Object Positions Database](../../assets/images/block-diagram-object-info-store.png)
/// caption
This is the portion of the Block Diagram that deals with entity position representation & storage.
///

Once we receive the MPC2 simulation data (from either the DON Federate or our Python server simulator), we need to parse and convert it to a form we can work with. To do this, we have three core data structures:

1. ObjectInfo: Data structure storing the position & state of an object at a given timestamp
2. ObjectInfoStore: Data structure storing the ObjectInfo data (position data) for all the objects in the simulation at a given timestamp
3. Timeline: Data structure storing all of the ObjectInfoStore data for all the objects at each timestamp in the simulation

The position and state of every single object in the simulation at a given timestep is stored as an **ObjectInfo**. This is made specifically so we can directly calculate stuff relative to the parent and other objects in the simulation.

Each ObjectInfo is created and managed by the **ObjectInfoStore**, which represents a single timestep of the simulation.

Every ObjectInfoStore is then a slice of the **Timeline**, which is every single step of the simulation.

By doing it this way, we’re able to keep all of the logic for each puzzle piece separate from one another. This was how we managed the original DON team’s solution to the floating-point problem.

These 3 data structures are the ‘bones’ underpinning our object placement systems.

![Object State Tracking Diagram](../../assets/images/object-state-tracking-diagram.png)
/// caption
Visual showing how the 3 data structures (Timeline, ObjectInfoStore, ObjectInfo) relate to each other
///

This diagram shows the Timeline (at the top), which looks like a tape. Each tick/box, which we call **telemetry frames**, within the Timeline corresponds to an indexed timestamp in the sim. Each telemetry frame also stores a separate ObjectInfoStore, which holds all of the object positions at the corresponding timestamp. The ObjectInfoStore (at the bottom left in image) object holds the position data (Parent, Position, Orientation) for each object (planets, crafts, etc.) only for the given timestamp.

## ObjectInfo

**What information does each ObjectInfo object include about the object it refers to?**

- Parent
- Position
- Orientation

Read the documentation for the [FObjectInfo Struct](/api_data/struct_f_object_info)

## ObjectInfoStore

Read the documentation for the [FObjectInfoStore Struct](/api_data/struct_f_object_info_store)

## Timeline

The Timeline, also known as the TelemetryTimeline, basically stores the entire simulation.

Read the documentation for the [UTelemetryTimeline Struct](/api_data/class_u_telemetry_timeline/)

## Telemetry Parsing & Storage

## Unit Testing

The C++ classes for the Object State data structures have undergone extensive unit testing. We found this to be incredibly useful and performant. While it may have been a short-term pain, it had huge benefits: it minimized debugging and resulted in integration tests (sims) going very smoothly.

## Summary

So, in short, the entire MPC2 simulation is stored in our custom data structure: the Timeline. You can think of the Timeline as an array of ObjectInfoStore elements for each timestamp in the simulation. You can think of the ObjectInfoStore as a table storing a snapshot of every object's ObjectInfo at the corresponding timestamp in the simulation. You can think of the ObjectInfo as a snapshot of the relevant position information for a single object in the sim. These 3 data structures are the ‘bones’ underpinning our object placement systems.
