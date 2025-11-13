# Mac Setup Instructions

> NOTE: We were able to get DON to build on macOS, but it was extremely buggy and we could not reliably run simulations. The steps below explain how we set it up, but Windows is strongly recommended for development and testing.

---

## 1. Install Unreal Engine 5.1.1

- Open Epic Games Launcher → Unreal Engine → Library
- Install version **5.1.1** (required by project)

---

## 2. Required Plugins

Some plugins may not fully support macOS.

| Plugin                       | Install Method                                                       |
| ---------------------------- | -------------------------------------------------------------------- |
| Blueprint FileSDK            | Epic Marketplace or place into `Engine/Plugins` or `Project/Plugins` |
| Easy File Dialog             | May not support macOS — use only if already functional               |
| Read & Write Text File       | Usually works, verify macOS compatibility                            |
| Cesium for Unreal (DON 4.5+) | Install from Epic Marketplace                                        |

---

## 3. Required Development Tools

- **Xcode** (from Mac App Store) — open once to complete setup
- **Command Line Tools**  
  xcode-select --install

markdown
Copy code

- **.NET 6.0 SDK**  
  https://dotnet.microsoft.com/en-us/download/dotnet/6.0  
  Confirm install:
  dotnet --version

yaml
Copy code

---

## 4. Set Up DON Project

1. Clone the project from GitHub and extract it
2. Move the **VisualStudioTools** folder into:
   <DON Project Directory>/Plugins/

yaml
Copy code

---

## 5. Generate Xcode Project Files

Example:

```bash
cd <DON Project Directory>
/Users/Shared/Epic\ Games/UE_5.1/Engine/Build/BatchFiles/Mac/GenerateProjectFiles.sh \
-project="$(pwd)/DONToUnreal.uproject" -game -engine -xcode
```

6. Open and Build in Xcode
   Open DONToUnreal.xcworkspace

Select My Mac or Editor (Mac) target

Build & run (Cmd + R)

If build fails:

Try launching the .uproject file directly in Finder — this worked more consistently for us

7. Required Code Fix (DON 4.4+)
   File:
   Source/DONToUnreal/Private/UMPCSocketClient.cpp

Replace the constructor:

```cpp
FSocketClientThread(const FString& InAddress, FString InFileName, int32 InPort)
    : Address(InAddress), Port(InPort), Socket(nullptr), bStopRequested(false), FileName(InFileName) {}
With (correct initialization order):
```

With (correct initialization order):

```cpp
FSocketClientThread(const FString& InAddress, FString InFileName, int32 InPort)
    : FileName(InFileName), Address(InAddress), Port(InPort), Socket(nullptr), bStopRequested(false) {}
```
