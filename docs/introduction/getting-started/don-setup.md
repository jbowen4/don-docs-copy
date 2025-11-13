# Windows Setup Guide

This guide covers setting up DON on Windows using Unreal Engine 5.1.1 and Visual Studio 2022.

---

## 1. Install Requirements

### Unreal Engine 5.1.1

- Epic Games Launcher → **Library** → Install **UE 5.1.1**

### Required Unreal Engine Plugins

Install via Epic Games Launcher:

- Blueprint FileSDK
- Easy File Dialog
- Read & Write Text File

### Visual Studio 2022

Installer workloads (check all):

- Game Development with C++
- Desktop Development with C++
- WinUI Application Development
- Linux/Mac/Embedded Development with C++
- .NET Desktop Development

Ensure latest **Windows 10/11 SDK** is selected on the right side.

### .NET 6.0

Download: https://dotnet.microsoft.com/en-us/download/dotnet/6.0

Restart PC after installation

---

## 2. Download DON Project

Clone repository:
https://github.com/FlaSpaceInst/2025-Summer-DON-.git

Extract the project folder fully before continuing.

---

## 3. Generate VS Project Files

Right-click **`DONToUnreal.uproject`** →

> **Generate Visual Studio Project Files**

On Windows 11: **Show More Options** menu may be required.

---

## 4. Install VisualStudioTools Plugin

Download ZIP (provided during onboarding):  
Google Drive: https://drive.google.com/file/d/1-FtQp7JpBaO_TshDM3aMNDkqqoCWMlbH/view?usp=sharing

Extract and move folder to:
<DON Project>/Plugins/

yaml
Copy code

---

## 5. Build the Project

1. Open **DONToUnreal.sln** in Visual Studio 2022
2. Wait for Unreal auto-configuration panel to appear
3. Click **Reset** and resolve any remaining alerts  
   Ensure these are **green**:
   - Visual Studio Integration Tool Status
   - Unreal Engine Test Adapter Status
4. Restart PC if prompted
5. Click **▶ Build/Run** (Local Windows Debugger)

DON should launch in Unreal automatically

---

### Troubleshooting

If project fails to open or build:

- Ensure UE version is **exactly 5.1.1**
- Confirm all required plugins are installed
- Run "Generate project files" again
- Fully restart PC after installing toolchains

---

If you get stuck, ask the team — setup issues often depend on environment differences.
