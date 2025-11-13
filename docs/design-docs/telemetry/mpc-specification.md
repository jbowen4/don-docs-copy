# MPC Specification

The MPC3 specification defines the structure and syntax for both the **mission setup** and **data** files used to represent a complete simulation.

## Overview

Each element in an MPC file includes:

- A **general description** of the data it represents.
- Its **XML syntax**.
- A **breakdown of attributes**, including:
  - Description
  - Occurrence (e.g., required, optional)
  - Data type
  - Valid values
  - Default values
- A **listing of valid child elements**, with their occurrence counts (e.g., 0, 1, or N).

## File Components

- **Mission Setup File (`Mission.xml`)**
  - Contains visualization setup details (objects, hierarchy, lighting, cameras, telemetry sources).
- **Data File**
  - Contains dynamic, time-dependent telemetry information for simulation playback and analysis.

See [The Config.xml and Mission.xml Files](config-and-mission-files.md) for detailed element definitions.
