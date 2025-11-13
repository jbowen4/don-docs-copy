# Distributed Observer Network (DON) Documentation

Welcome to the official documentation for the **Distributed Observer Network (DON)** — a data presentation tool developed by student groups from UCF and Floriday Polytechnic that enables standardized distribution and review of space simulations.

This site serves as a comprehensive guide for developers, engineers, and researchers working with DON, providing both **conceptual overviews** and **detailed implementation documentation**.

---

## 🚀 Overview

The **Distributed Observer Network (DON)** is an Unreal Engine-based simulation viewer that uses MPC2 telemetry.

---

## 📂 Documentation Structure

### 🧭 [Introduction](introduction/index.md)

Start here to understand the foundation of DON, its purpose, and its installation process.

- [What is DON?](introduction/what-is-don.md)
- [Background](introduction/background.md)
- [Getting Started](introduction/getting-started/index.md)
  - [Windows Installation & Setup](introduction/getting-started/don-setup.md)
  - [Mac Installation & Setup](introduction/getting-started/mac-don-setup.md)
- [Administrative](introduction/administrative.md)
- [Project History](introduction/project-history/index.md)
  - [Version History](introduction/project-history/version-history.md)

---

### 🧩 [Design Docs](design-docs/index.md)

Dive into the architecture and design philosophy behind DON’s simulation systems.

- [Design Methodology](design-docs/methodology/index.md)
- [Object State Tracking](design-docs/object-state-tracking/index.md)
- [Camera Rework](design-docs/camera-rework/index.md)
- [Rendering Modes](design-docs/rendering-modes/index.md)
  - [Close Range Rendering](design-docs/close-range/index.md)
  - [Distant Rendering](design-docs/long-range/index.md)
  - [Billboarding](design-docs/long-range/billboarding.md)
- [Telemetry](design-docs/telemetry/index.md)
  - [History](design-docs/telemetry/history.md)
  - [MPC Specification](design-docs/telemetry/mpc-specification.md)
  - [Config & Mission Files](design-docs/telemetry/config-and-mission-files.md)
- [Blueprints Overview](design-docs/blueprints/index.md)

---

### 💻 [API Reference](api/index.md)

Detailed technical documentation of DON’s C++ and Blueprint interfaces, generated automatically from source code.

Explore the following API modules:

- [Core](api_core/annotated.md)
- [Data](api_data/annotated.md)
- [Level](api_level/annotated.md)
- [Utils](api_utils/annotated.md)

Each includes:

- Class hierarchies
- Member functions and variables
- File references
- Macros and global definitions

---

### 🎮 [Using DON](using-don/index.md)

Learn how to run simulations, navigate the user interface, and experiment with built-in demos.

- [User Interface Overview](using-don/user-interface/index.md)
  - [Simulation Selection](using-don/user-interface/user-interface.md)
  - [In-Simulation GUI](using-don/user-interface/in-sim-gui.md)
- [Running a Simulation](using-don/running-simulations.md)
- [Demos](using-don/demos/index.md)
  - [Orbits Demo](using-don/demos/orbits-demo.md)
  - [New Demo](using-don/demos/new-demo.md)
  - [Making Testing Simulations](using-don/making-simulations.md)

---

## 🛰️ About the Project

DON was developed to enable real-time planetary rendering, orbital visualization, and mission-level simulation for research and engineering applications.  
It integrates Unreal Engine’s visualization power with custom rendering and telemetry logic for scientific accuracy and extensibility.

---
