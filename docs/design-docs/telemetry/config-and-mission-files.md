# The Config.xml and Mission.xml Files

The **DON Mission directory** must contain a file named `Config.xml`.  
This file is essential — it allows **Distributed Observer Network (DON)** to populate the simulation menu and locate the `Mission.xml` file.

---

## Config.xml

Traditionally includes:

- Pointers to mission and telemetry files.
- Configuration parameters for visualization setup.

With **MPC 3.0**, much of this information has been **moved** to `Mission.xml`, leaving `Config.xml` primarily as a **pointer** to the mission file.

Future versions of MPC may further separate configuration logic from mission data.

---

## Mission.xml

Defines all the data required to construct a complete visualization scene, including:

- Object hierarchy
- Lighting
- Cameras and viewpoints
- Items of interest
- Scene background and terrain information
- Telemetry data locations

### Purpose

Provides the foundation for reproducing simulation activities within DPV tools like DON or EVE.

### Example Usage

The file structure supports:

- Reusable mission configurations.
- Multiple telemetry datasets per scene.
- Extensible scene and data definitions.

---

## General Syntax

While a full XML schema is defined in Appendix B of the ICD, in general:

```xml
<Mission>
    <Scene>
        <Object name="VehicleA" parent="Ground">
            <Model file="vehicleA.fbx" />
            <Telemetry file="vehicleA_telemetry.xml" />
        </Object>
        <Lighting type="Directional" intensity="1.0" />
        <Camera name="MainView" position="0,0,100" />
    </Scene>
</Mission>
```

## Mission Level Element Definitions

### `<mpcMission>`

#### Description

The primary element of the mission file. This element encompasses all other elements of the file.

#### Format

```xml
<mpcMission version="3.0" epoch="YYYY-MM-DDTHH:mm:ss.ssZ" author="string" baseFilePath="dir/">  …  </mpcMission>
```

#### Attributes

| **Attribute**  | **Description**                                                                                                                                            | **Occurrence** | **Type**                                           | **Values**   | **Default**            |
| -------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------- | -------------- | -------------------------------------------------- | ------------ | ---------------------- |
| `version`      | Defines the version of the MPC file.                                                                                                                       | Required       | String                                             | `3.0`        | None                   |
| `epoch`        | Specifies a Gregorian date/time in UTC that maps to time “zero” of the simulation data. Used for integrating with other datasets (e.g., celestial bodies). | Optional       | String (ISO 8601 format `YYYY-MM-DDTHH:mm:ss.ssZ`) | User Defined | Application defined    |
| `author`       | Name of the mission developer.                                                                                                                             | Optional       | String                                             | User Defined | Empty String           |
| `baseFilePath` | Provides a default path location where all future file paths within the mission may be relative to.                                                        | Optional       | String                                             | User Defined | Mission file directory |

#### Subelements

note (0..1)
scene (1..1)
telemetries (0..1)

### `<note>`

#### Description

A note is an optional element used to provide descriptions or additional information that may be of interest regarding the overall mission file. Only one note is expected in any given section that provides the ability to store a note. The data contained within the note is not designed to be used by software reading MPC, other than for display purposes, but should be maintained with the MPC file if the file is imported and exported.

#### Format

```xml
<note>string</note>
```

#### Attributes

None

#### Subelements

None

### `<scene>`

#### Description

The main element tag for the scene section, enclosing all scene elements. Only one `<scene>` section is allowed within the mission file, and it is **required**.

#### Format

```xml
<scene name="string" baseFilePath="dir/"> … </scene>
```

| **Attribute**  | **Description**                                                                                           | **Occurrence** | **Type** | **Values**   | **Default**            |
| -------------- | --------------------------------------------------------------------------------------------------------- | -------------- | -------- | ------------ | ---------------------- |
| `name`         | Informative name that can be provided for the scene.                                                      | Optional       | String   | User Defined | Empty String           |
| `baseFilePath` | Provides a default path location where all future file paths within the Scene element may be relative to. | Optional       | String   | User Defined | Mission Base File Path |

#### Subelements

note (0..1)
units (0..1)
environment (1)
objects (1)
