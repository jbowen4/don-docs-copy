This page discusses all the different managers that we created / use, what they each do, how they work together, etc.

## High-Level Overview

## Solar Position Manager

## Global Position Manager

## Actor Placement Manager

## Scale Manager

The Scale Manager is used to determine where on the Unreal plane the billboarded planetary objects should lie.
The solar positions are then utilized by the Scaled Distances Manager (Figure 7). This subsystem runs after the solar position manager, and uses the positions of all planetary objects on the sun-relative plane to determine where on the Unreal plane the planetary objects should lie.

![Block Diagram](../assets/images/block-diagram-old-version.png)
///caption
Block Diagram for DON v4.5
///

The solar position manager is the initial module through which all rendering systems interact. Both rendering modes leverage the scale manager to load assets into the Unreal Engine level scene. Camera management is determined by the active mode selection. Terrain assets are stored in memory and leveraged by both the Cesium and rendering manager subcomponents.
