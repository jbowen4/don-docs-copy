---
hide:
  - toc
---

# Overview

This section covers DON's architecture, key design decisions, and design methodology.

## Design Methodology

DON is a simulation viewer. Prior to our team, DON was only able to handle very small-scale simulations
on a small piece of sculpted terrain. The **goal** of our team was to enable DON to handle simulations
at space-scale distances while also maintaining the high level of detail (LOD) and precision needed.

Space is big and to achieve our goal, we needed to implement a solution that overcame the limits of
Unreal Engine's coordinate system and could handle / represent the insanely large distances of space.
To accomplish this, we implemented a system described below which is defined by using two rendering modes:
distant rendering mode & close-range rendering mode.

Our main goal was to maintain the perception of real space-scale interplanetary travel.

More specifically, we needed to implement a scalable system to allow us to move these huge distances, and to make some demos demonstrate this.

This involves not only representing planetary distances and sizes at 1:1 scale, but also allowing simulated objects to move between planetary objects (where a planetary object is a planet or large moon) freely and without disruption.

## Block Diagram

![Block Diagram](../assets/images/block-diagram.png)
///caption
Block Diagram for DON v4.5
///

This Block Diagram outlines the process that is followed to run a simulation in done, from reading in
the telemetry data outlining the simulation's behavior to all the processes involved in rendering the
sim correctly. This diagram shows essentially everything our group has done in DON.

Here is the steps outlined again:

1. First, we create sample telemetry (using the MPC2 format) for our demo simulations. This is meant to
   roughly mimic the behavior of the DON Federate Server, which streams telemetry data from real simulations,
   since we are not able to access the Federate.

2. When the telemetry data enters the DON application, it is converted to a format that we created that makes it
   easy to work with, namely three core data structures that we created: ObjectInfo, ObjectInfoStore & the Timeline. We
   describe these more in detail [here](./object-state-tracking/index.md).

3. Then, we use the player's camera position (the one object position not directly tracked by the ObjectInfoStore) to
   figure out which rendering mode we need to be in. If there is a planet within a certain defined range of the
   player's camera, then we switch to terrain rendering mode. If there are no nearby planets within range, we
   use distant rendering mode.

4. Then, the next step depends on the rendering mode that we've been detected as being in:

   - In terrain rendering mode, the closest planet becomes the center of the Unreal world (centered at origin). This planet is rendered at a high level of detail (LOD) using the Cesium plugin. The visibility and positioning of all other planets are handled by the Scale Manager & they are visualized using billboarding if in view. The player's camera is used more "normally" in this mode, with its location being updated as the player moves around (free camera movement). The camera's location is relative to the center of the specified closest planet.

   - In full distant rendering mode, the player's camera is locked at the origin of the Unreal world. The camera is the 'root.' The visibility, scaling, and positioning of all the planets in the simulation are controlled by the Scale Manager. Instead of using Cesium to render them at high detail, all planets are billboarded at the appropriate scale & position as they would be given the player's position (which isn't actually updating the camera / moving but will give the illusion of movement by changing the planets' scale + position). Although the player isn't "moving," the updates in their position as they press WASD are tracked by the Global Position Manager.
