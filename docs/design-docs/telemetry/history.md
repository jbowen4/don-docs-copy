# History

The **Model Process Control (MPC)** telemetry format has evolved through several iterations to improve usability, flexibility, and extensibility.

## MPC (Original Version)

- Implemented as a **comma-delimited text file**.
- Each line corresponded to:
  - A unique object and time point.
  - 14 fields defining:
    - Object position
    - Orientation
    - Scale
    - Visibility
    - Commands for the visualization environment.
- Required **all 14 fields per time step** and **for every object** in the simulation.

---

## MPC2

- Migrated to **XML format** for improved readability and extensibility.
- Retained core data (position, orientation, scale, visibility).
- **Dropped** the command section.
- Introduced:
  - **State change philosophy:**  
    Only objects that changed from one time step to the next needed to be included.
  - **Metadata section:**  
    Captured extra, time-dependent data not directly tied to visualization.
  - **Parenting:**  
    Allowed the data stream to dynamically reassign parent-child relationships between objects.

---

## MPC3 (Current Version)

- Latest generation of the XML-based MPC format.
- Split into **two files**:
  - **Mission setup file** — defines objects, hierarchy, lighting, and visualization setup.
  - **Data file** — contains dynamic, time-dependent simulation data.
- Focused on:
  - Improved usability for developers.
  - More precise data definitions.
  - Expanded supported data types.
