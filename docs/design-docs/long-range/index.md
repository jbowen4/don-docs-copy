# Distant Rendering

![Block Diagram - Distant Rendering](../../assets/images/block-diagram-long-range.png)
/// caption
This is the portion of the Block Diagram that deals with distant rendering and the Scale Manager.
///

**Distant rendering**, also referred to as **outer space mode** or **long range rendering mode**, represents the baseline rendering state of the simulation.  
Even when the user is operating in **terrain rendering mode**, distant rendering still occurs for celestial bodies that remain visible in the background.  
For instance, the Earth may be rendered in terrain mode while the Moon is rendered in distant mode.

---

## Overview

Distant rendering is the **default mode** of the simulation and is always active in some capacity. It has two primary variations:

1. **Full Distant Rendering Mode**
2. **Limited Distant Rendering Mode**

---

## Full Distant Rendering Mode

In full distant rendering mode, the player camera is **fixed at the Unreal Engine origin** (`0, 0, 0`).

Two classes of objects are rendered:

- **Planetary objects** – billboarded inside a spherical shell (“billboarding dome”) at fixed distances to emulate astronomical spacing without representing full-scale distances.
- **Standard objects** – rendered at true scale and distance, relative to the player’s position in solar coordinates.

### Motion Illusion

Movement in full distant mode is **an illusion**.  
The player’s camera never physically moves; instead, **keyboard inputs** update the **player’s sun-relative position**, managed by the **Solar Position Manager** subsystem.

This system:

- Tracks and updates the positions of **all objects**, including the player camera, relative to the Sun (or ultimate parent object).
- Runs **every game tick**, computing acceleration and deceleration of the player’s camera.
- Walks the **parent-child hierarchy** to compute absolute positions for all objects.
- Stores positions in **two hash maps**, each mapping object names to their `(x, y, z)` coordinates.

The Solar Position Manager continuously operates, but only controls player motion logic when in full distant rendering mode.  
When in terrain or limited distant mode, the player’s Unreal Engine position is instead determined relative to the active Cesium object.

---

## Limited Distant Rendering Mode

Limited distant rendering mode becomes active when a **Cesium planetary object** is loaded in (i.e., during close-range rendering).

Key differences:

- The **origin** of the Unreal world shifts to the **center of the active planet**, not the player camera.
- The **billboarding dome** follows the player’s position rather than being fixed.
- **Standard objects** are rendered relative to the planet’s center.
- One fewer planetary object is billboarded, since the active Cesium planet is rendered directly.

---

## Scaled Distances Manager

After the Solar Position Manager updates all object positions, the **Scaled Distances Manager** determines where and how planetary objects should appear in Unreal Engine space.

It:

1. Takes each object’s **sun-relative position** and projects it onto the **Unreal billboarding dome**.
2. Calculates the **angles** (`α` and `β`) between the object and the player camera (see Figure 8).
3. Determines the **render scale** needed to maintain the same _apparent size_ based on the billboarding dome’s radius.
   - For example, a scale of 10 means the object is drawn **10× its actual size** to preserve apparent scale.
4. Translates the calculated angles into `(x, y, z)` coordinates on the Unreal plane.
5. Stores all positions and scales in a **vector of arrays**, with each array holding the planetary object’s `x`, `y`, `z`, and scale values.

---

![Scaled Distances Manager](../../assets/images/scaled-distances-manager.png)
///caption
**Figure 7:** Scaled Distances Manager — determines apparent size and placement of celestial objects on the billboarding dome.
///

![Billboarding Dome Geometry](../../assets/images/billboarding-dome-angles.png)
///caption
**Figure 8:** Angular relationship between planetary objects and player camera used to calculate billboard positions.
///
