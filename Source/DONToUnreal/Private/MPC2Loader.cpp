#include "MPC2Loader.h" 
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <regex>
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "Engine/World.h"
#include "Factories/FbxFactory.h"
#include "Factories/FbxTextureImportData.h"
#include "Factories/FbxImportUI.h"
#include "AssetRegistry/AssetRegistryModule.h"
#include "Factories/FbxStaticMeshImportData.h"
#include "PackageTools.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Components/PointLightComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Containers/Map.h"
#include "Containers/UnrealString.h"
#include "InterchangeManager.h"
#include "InterchangeSourceData.h"
#include <AssetToolsModule.h>

using namespace tinyxml2;
FSimulationMetadata UMPC2Loader::CurrentSimulationData = FSimulationMetadata();

// Function to load the simulation configuration file
void UMPC2Loader::ParseModelFileMPC2(const FString& FilePath) {
    TArray<FModelMetadata> Models;
    FString FileContent;

    FString ObjMetadataPath = FPaths::Combine(*FilePath, "metadata" + FString(TEXT(".txt")));

    if (!FFileHelper::LoadFileToString(FileContent, *ObjMetadataPath)) {
        UE_LOG(LogTemp, Error, TEXT("Failed to load model metadata file: %s"), *FilePath);
        return;
    }

    // Convert to std::string for easier parsing with std::regex
    std::string Content = TCHAR_TO_UTF8(*FileContent);

    // Regex to match model blocks
    std::regex IdRegex("id=\"([^\"]+)\":\\s*");

    // Find all model blocks
    std::sregex_iterator IdIter(Content.begin(), Content.end(), IdRegex);
    std::sregex_iterator End;

    size_t CurrentPosition = 0;

    for (auto It = IdIter; It != End; ++It) {
        std::smatch IdMatch = *It;
        std::string IdStr = IdMatch[1];

        // Find where this model block starts
        size_t ModelStart = IdMatch.position();

        // Find where the next model block starts (or end of file)
        size_t ModelEnd;
        auto NextIt = It;
        ++NextIt;
        if (NextIt != End) {
            ModelEnd = NextIt->position();
        }
        else {
            ModelEnd = Content.length();
        }

        // Extract the model block
        std::string ModelBlock = Content.substr(ModelStart, ModelEnd - ModelStart);

        // Parse the model data
        FModelMetadata Model;
        Model.Id = UTF8_TO_TCHAR(IdStr.c_str());

        // Check if static
        if (ModelBlock.find("static: true") != std::string::npos) {
            Model.bStatic = true;
        }

        // Parse static position
        ParseVector(ModelBlock, "static_position:", Model.StaticPosition);
        Model.StaticPosition *= 100;

        // Parse static orientation
        ParseQuat(ModelBlock, "static_orientation:", Model.StaticOrientation);

        // Parse static scale
        ParseVector(ModelBlock, "static_scale:", Model.StaticScale);

        // Parse static parent
        ParseString(ModelBlock, "static_parent:", Model.StaticParent);

        // Parse components
        ParseComponents(ModelBlock, Model.Components);

        Models.Add(Model);
    }

    CurrentSimulationData.Models = Models;
    for (const FModelMetadata& Model : CurrentSimulationData.Models) {
        FModelMetadatatoStr(Model);
    }
}


// Function to parse a vector from a block of text
void UMPC2Loader::ParseVector(const std::string& Text, const std::string& Prefix, FVector& OutVector) {
    std::regex VectorRegex(Prefix + "\\s*\\(([^,)]+),\\s*([^,)]+),\\s*([^,)]+)\\)");
    std::smatch Match;
    if (std::regex_search(Text, Match, VectorRegex) && Match.size() == 4) {
        OutVector.X = std::stof(Match[1]);
        OutVector.Y = std::stof(Match[2]);
        OutVector.Z = std::stof(Match[3]);
    }
}


// Function to parse a quaternion from a block of text
void UMPC2Loader::ParseQuat(const std::string& Text, const std::string& Prefix, FQuat& OutQuat) {
    std::regex QuatRegex(Prefix + "\\s*\\(([^,)]+),\\s*([^,)]+),\\s*([^,)]+),\\s*([^,)]+)\\)");
    std::smatch Match;

    // Axis were swapped to match ue5 coordinate system
    if (std::regex_search(Text, Match, QuatRegex) && Match.size() == 5) {
        OutQuat.X = std::stof(Match[1]);
        OutQuat.Y = std::stof(Match[2]);
        OutQuat.Z = std::stof(Match[3]);
        OutQuat.W = std::stof(Match[4]);
    }
}


// Function to parse a string from a block of text
void UMPC2Loader::ParseString(const std::string& Text, const std::string& Prefix, FString& OutString) {
    std::regex StringRegex(Prefix + "\\s*([^\\s\\n]+)");
    std::smatch Match;

    if (std::regex_search(Text, Match, StringRegex) && Match.size() == 2) {
        OutString = UTF8_TO_TCHAR(Match[1].str().c_str());
    }
}


// Function to parse components from a model block
void UMPC2Loader::ParseComponents(const std::string& ModelBlock, TArray<FModelComponentData>& OutComponents) {
    TSet<FString> CelestialBodiesSet = { "Sun", "Moon", "Mars", "Earth" };

    // Regex to find filename entries
    std::regex FilenameRegex("filename=\"([^\"]+)\":");
    std::sregex_iterator FilenameIter(ModelBlock.begin(), ModelBlock.end(), FilenameRegex);
    std::sregex_iterator End;

    for (auto It = FilenameIter; It != End; ++It) {
        std::smatch FilenameMatch = *It;
        std::string FilenameStr = FilenameMatch[1];

        // Find where the component data starts
        size_t ComponentStart = FilenameMatch.position();

        // Find where the next component data starts or end of model block
        size_t ComponentEnd;
        auto NextIt = It;
        ++NextIt;
        if (NextIt != End) {
            ComponentEnd = NextIt->position();
        }
        else {
            ComponentEnd = ModelBlock.length();
        }

        // Extract the component data
        std::string ComponentData = ModelBlock.substr(ComponentStart, ComponentEnd - ComponentStart);

        // Create the component
        FModelComponentData Component;
        Component.Filename = FPaths::GetBaseFilename(UTF8_TO_TCHAR(FilenameStr.c_str()));
        if (CelestialBodiesSet.Contains(Component.Filename)) {
            Component.bIsCelestialBody = true;
        }

        // Parse position, orientation, and scale
        ParseVector(ComponentData, "position:", Component.Position);
        ParseQuat(ComponentData, "orientation:", Component.Orientation);
        ParseVector(ComponentData, "scale:", Component.Scale);

        OutComponents.Add(Component);
    }
}



// Function to load the XML configuration and spawn actors
bool UMPC2Loader::LoadSimulationConfigMPC2(bool importModels, const FString& SimulationDirectory)
{
    FString ConfigFilePath;
    FTerrainMetadata Terrain;
    TArray<FObjectsOfInterest> ObjectsOfInterest;

    ConfigFilePath = FPaths::Combine(*SimulationDirectory, "Config" + FString(TEXT(".xml")));
	UE_LOG(LogTemp, Log, TEXT("Config file path: %s"), *ConfigFilePath);
    XMLDocument XmlDoc;
    if (XmlDoc.LoadFile(TCHAR_TO_UTF8(*ConfigFilePath)) != XML_SUCCESS)
    {
        UE_LOG(LogTemp, Error, TEXT("Failed to load XML configuration file: %s"), *ConfigFilePath);
        return false;
    }

    XMLElement* root = XmlDoc.FirstChildElement("SimulationConfig");
    if (!root)
    {
        UE_LOG(LogTemp, Error, TEXT("Invalid XML root node."));
        return false;
    }

	XMLElement* simulationElement = root->FirstChildElement("Simulation");
	if (simulationElement) {
		const char* NameAttr = simulationElement->Attribute("name");
		const char* DescAttr = simulationElement->Attribute("description");
		const char* AuthorAttr = simulationElement->Attribute("author");

		if (NameAttr) {
			CurrentSimulationData.Name = UTF8_TO_TCHAR(NameAttr);
		}
		if (DescAttr) {
			CurrentSimulationData.Description = UTF8_TO_TCHAR(DescAttr);
		}
		if (AuthorAttr) {
			CurrentSimulationData.Author = UTF8_TO_TCHAR(AuthorAttr);
		}
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("Invalid Simulation node"));
	}

    XMLElement* terrainElement = root->FirstChildElement("Terrain");
    if (terrainElement) {
        parseTerrainElement(terrainElement, Terrain);
    }
    else {
        UE_LOG(LogTemp, Error, TEXT("Invalid Terrain node"));
    }

    XMLElement* objectsOfInterestElement = root->FirstChildElement("ObjectsOfInterest");
    if (objectsOfInterestElement) {
        parseObjectsOfInterestElement(objectsOfInterestElement, ObjectsOfInterest);
    }
    else {
        UE_LOG(LogTemp, Error, TEXT("Invalid ObjectsOfInterest node"));
    }

    // Hard coded object path for testing 
    FString Folder1 = TEXT("models");
    FString ModelsFolderPath = FPaths::Combine(*SimulationDirectory, Folder1);

    ParseModelFileMPC2(ModelsFolderPath);

    if (importModels) {
        ImportSimulationModelsMPC2(ModelsFolderPath);
    }
    else {
        UE_LOG(LogTemp, Log, TEXT("Models not being imported"));
    }

    return true;
}


// TODO: Instead of importing all models in directory, only import necessary models
//       (e.g. in ParseComponents above or SpawnModelActor in SimulationLoader.cpp)

// Function to import models from a directory
void UMPC2Loader::ImportSimulationModelsMPC2(const FString& ModelsFolderPath)
{
    // Find all FBX files in the directory
    TArray<FString> FoundFilesFbx;
    IFileManager::Get().FindFiles(FoundFilesFbx, *FPaths::Combine(ModelsFolderPath, TEXT("*.fbx")), true, false);
    FString ModelImportBasePath = TEXT("/Game/Assets/models/");

    // Import each FBX file using the editor's import flow
    for (const FString& FileName : FoundFilesFbx)
    {
        FString FullFilePath = FPaths::Combine(ModelsFolderPath, FileName);
        FString BaseFileName = FPaths::GetBaseFilename(FileName);

        UE_LOG(LogTemp, Log, TEXT("Importing FBX file: %s"), *FullFilePath);

        // Set the destination path
        FString DestPath = FPaths::Combine(*ModelImportBasePath, *BaseFileName);

        TArray<FString> FilesToImport;
        FilesToImport.Add(FullFilePath);

        FAssetToolsModule& AssetToolsModule = FModuleManager::GetModuleChecked<FAssetToolsModule>("AssetTools");
        AssetToolsModule.Get().ImportAssets(FilesToImport, DestPath);
    }

    // Find all OBJ files in the directory
    TArray<FString> FoundFilesObj;
    IFileManager::Get().FindFiles(FoundFilesObj, *FPaths::Combine(ModelsFolderPath, TEXT("*.obj")), true, false);
    UInterchangeManager* InterchangeManager = UInterchangeManager::GetInterchangeManagerScripted();

    FImportAssetParameters ImportAssetParams;

    for (const FString& FileName : FoundFilesObj)
    {
        FString FullFilePath = FPaths::Combine(ModelsFolderPath, FileName);
        FString BaseFileName = FPaths::GetBaseFilename(FileName);

        // Create SourceData object and initialize with the file path
        UInterchangeSourceData* SourceData = InterchangeManager->CreateSourceData(FullFilePath);

        //FString ComponentImportPath = ModelImportBasePath + Model.Id + "_" + FString::FromInt(Index) + "/";
        FString DestPath = FPaths::Combine(*ModelImportBasePath, *BaseFileName);

        // Import the asset
        InterchangeManager->ImportAsset(DestPath, SourceData, ImportAssetParams);
    }
}


void UMPC2Loader::parseObjectsOfInterestElement(XMLElement* ObjectsOfInterestNode, TArray<FObjectsOfInterest> ObjectsOfInterest)
{
    if (!ObjectsOfInterestNode)
    {
        UE_LOG(LogTemp, Error, TEXT("Invalid ObjectsOfInterest node."));
        return;
    }
    

    // Iterate through all Object nodes
    XMLElement* ObjectNode = ObjectsOfInterestNode->FirstChildElement("Object");
    while (ObjectNode)
    {
        FObjectsOfInterest NewObject;
        // Get object ID and name attributes
        const char* IdStr = ObjectNode->Attribute("id");
        const char* NameStr = ObjectNode->Attribute("name");

        if (IdStr && NameStr)
        {
            // Create new object info
            NewObject.Id = FString(UTF8_TO_TCHAR(IdStr));
            NewObject.Name = FString(UTF8_TO_TCHAR(NameStr));

            // Add to the objects array
            ObjectsOfInterest.Add(NewObject);
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("Object node missing required attributes (id or name)."));
        }

        // Move to next Object node
        ObjectNode = ObjectNode->NextSiblingElement("Object");
    }
    CurrentSimulationData.ObjectsOfInterest = ObjectsOfInterest;
    UE_LOG(LogTemp, Log, TEXT("Parsed %d Objects of Interest"), ObjectsOfInterest.Num());
}

void UMPC2Loader::parseTerrainElement(XMLElement* TerrainNode, FTerrainMetadata& TerrainData)
{
    if (!TerrainNode)
    {
        UE_LOG(LogTemp, Error, TEXT("Invalid Terrain node."));
        return;
    }


    // Extract ID attribute
    const char* idAttr = TerrainNode->Attribute("id");
    if (idAttr)
    {
        TerrainData.Id = UTF8_TO_TCHAR(idAttr);
    }


    // Extract position attribute
    const char* posAttr = TerrainNode->Attribute("pos");
    if (posAttr)
    {
        float x, y, z;
        if (sscanf(posAttr, "%f %f %f", &x, &y, &z) == 3)
        {
            TerrainData.Position = FVector(x, y, z);
        }
    }


    // Extract quaternion attribute
    const char* quatAttr = TerrainNode->Attribute("quat");
    if (quatAttr)
    {
        float x, y, z, w;
        if (sscanf(quatAttr, "%f %f %f %f", &x, &y, &z, &w) == 4)
        {
            TerrainData.Orientation = FQuat(x, y, z, w);
        }
    }


    // Extract parent attribute
    const char* parentAttr = TerrainNode->Attribute("parent");
    if (parentAttr)
    {
        TerrainData.Parent = UTF8_TO_TCHAR(parentAttr);
    }


    // Extract terrainOffset attribute
    const char* offsetAttr = TerrainNode->Attribute("terrainOffset");
    if (offsetAttr)
    {
        float x, y, z;
        if (sscanf(offsetAttr, "%f %f %f", &x, &y, &z) == 3)
        {
            TerrainData.TerrainOffset = FVector(x, y, z);
        }
    }


    // Extract tiling attribute
    const char* tilingAttr = TerrainNode->Attribute("tiling");
    if (tilingAttr)
    {
        float x, y;
        if (sscanf(tilingAttr, "%f %f", &x, &y) == 2)
        {
            // Store as FVector but only using X and Y components
            TerrainData.Tiling = FVector(x, y, 0.0f);
        }
    }


    // Extract source attribute
    const char* sourceAttr = TerrainNode->Attribute("source");
    if (sourceAttr)
    {
        TerrainData.Source = UTF8_TO_TCHAR(sourceAttr + 3);
    }
    TArray<FTerrainMetadata> Terrains;
    Terrains.Add(TerrainData);
    CurrentSimulationData.Terrains = Terrains;
    UE_LOG(LogTemp, Log, TEXT("Parsed Terrain: ID=%s, Parent=%s, Source=%s"),
        *TerrainData.Id, *TerrainData.Parent, *TerrainData.Source);
}


// For testing, displays the loaded in models metadata
FString UMPC2Loader::FModelMetadatatoStr(const FModelMetadata& Model)
{
    FString Result;

    Result += FString::Printf(TEXT("ModelMetadata:\n"));
    Result += FString::Printf(TEXT("  Id: %s\n"), *Model.Id);
    Result += FString::Printf(TEXT("  Static: %s\n"), Model.bStatic ? TEXT("true") : TEXT("false"));

    if (Model.bStatic)
    {
        Result += FString::Printf(TEXT("  StaticPosition: X=%.2f Y=%.2f Z=%.2f\n"),
            Model.StaticPosition.X, Model.StaticPosition.Y, Model.StaticPosition.Z);
        Result += FString::Printf(TEXT("  StaticOrientation: X=%.2f Y=%.2f Z=%.2f W=%.2f\n"),
            Model.StaticOrientation.X, Model.StaticOrientation.Y,
            Model.StaticOrientation.Z, Model.StaticOrientation.W);
        Result += FString::Printf(TEXT("  StaticScale: X=%.2f Y=%.2f Z=%.2f\n"),
            Model.StaticScale.X, Model.StaticScale.Y, Model.StaticScale.Z);
        Result += FString::Printf(TEXT("  StaticParent: %s\n"), *Model.StaticParent);
    }

    Result += FString::Printf(TEXT("  Components (%d):\n"), Model.Components.Num());
    for (int32 i = 0; i < Model.Components.Num(); i++)
    {
        const FModelComponentData& Component = Model.Components[i];
        Result += FString::Printf(TEXT("    Component %d:\n"), i);
        Result += FString::Printf(TEXT("      Filename: %s\n"), *Component.Filename);
        Result += FString::Printf(TEXT("      Position: X=%.2f Y=%.2f Z=%.2f\n"),
            Component.Position.X, Component.Position.Y, Component.Position.Z);
        Result += FString::Printf(TEXT("      Orientation: X=%.2f Y=%.2f Z=%.2f W=%.2f\n"),
            Component.Orientation.X, Component.Orientation.Y,
            Component.Orientation.Z, Component.Orientation.W);
        Result += FString::Printf(TEXT("      Scale: X=%.2f Y=%.2f Z=%.2f\n"),
            Component.Scale.X, Component.Scale.Y, Component.Scale.Z);
    }

    return Result;
}

double UMPC2Loader::ExtractTimeValueMPC2(const FString& TimeTagXML)
{
    std::string XmlStr = TCHAR_TO_UTF8(*TimeTagXML);

    tinyxml2::XMLDocument Doc;
    tinyxml2::XMLError Error = Doc.Parse(XmlStr.c_str());
    if (Error != tinyxml2::XML_SUCCESS)
    {
        UE_LOG(LogTemp, Warning, TEXT("Failed to parse XML: %s"), *FString(Doc.ErrorStr()));
        return 0.0;
    }

    tinyxml2::XMLElement* TimeElement = Doc.FirstChildElement("time");

    const char* ValueStr = TimeElement->Attribute("value");

    return FCString::Atod(UTF8_TO_TCHAR(ValueStr));
}

TMap<FString, FObjectState> UMPC2Loader::ExtractObjectStatesMPC2(XMLElement* TimeTagXML)
{
    TMap<FString, FObjectState> ObjectStates;

    // Iterate through all object elements within the time element
    for (tinyxml2::XMLElement* ObjectElement = TimeTagXML->FirstChildElement("object");
        ObjectElement;
        ObjectElement = ObjectElement->NextSiblingElement("object"))
    {
        FObjectState NewState;

        // Extract ID
        const char* IdStr = ObjectElement->Attribute("id");
        if (IdStr)
        {
            NewState.ID = UTF8_TO_TCHAR(IdStr);
        }

        // Extract Position
        tinyxml2::XMLElement* PosElement = ObjectElement->FirstChildElement("pos");
        if (PosElement && PosElement->GetText())
        {
            FString PosStr = UTF8_TO_TCHAR(PosElement->GetText());

            // Split the position string by spaces
            TArray<FString> PosComponents;
            PosStr.ParseIntoArray(PosComponents, TEXT(" "), true);

            if (PosComponents.Num() >= 3)
            {
                NewState.Position.X = FCString::Atod(*PosComponents[0]);
                NewState.Position.Y = FCString::Atod(*PosComponents[1]);
                NewState.Position.Z = FCString::Atod(*PosComponents[2]);
            }
			NewState.Position *= 100; // Convert from centimeters to meters
        }

        // Extract Velocity from metaData if present
        tinyxml2::XMLElement* MetaDataElement = ObjectElement->FirstChildElement("metaData");
        while (MetaDataElement)
        {
            const char* MetaDataIdStr = MetaDataElement->Attribute("id");
            if (MetaDataIdStr && strcmp(MetaDataIdStr, "Velocity") == 0 && MetaDataElement->GetText())
            {
                FString VelStr = UTF8_TO_TCHAR(MetaDataElement->GetText());

                // Split the velocity string by spaces
                TArray<FString> VelComponents;
                VelStr.ParseIntoArray(VelComponents, TEXT(" "), true);

                if (VelComponents.Num() >= 3)
                {
                    NewState.Velocity.X = FCString::Atod(*VelComponents[0]);
                    NewState.Velocity.Y = FCString::Atod(*VelComponents[1]);
                    NewState.Velocity.Z = FCString::Atod(*VelComponents[2]);
                }
                break;
            }
            MetaDataElement = MetaDataElement->NextSiblingElement("metaData");
        }

        // Extract Rotation (Quaternion)
        tinyxml2::XMLElement* QuatElement = ObjectElement->FirstChildElement("quat");
        if (QuatElement && QuatElement->GetText())
        {
            FString QuatStr = UTF8_TO_TCHAR(QuatElement->GetText());

            // Split the quaternion string by spaces
            TArray<FString> QuatComponents;
            QuatStr.ParseIntoArray(QuatComponents, TEXT(" "), true);

            if (QuatComponents.Num() >= 4)
            {
                NewState.Rotation.X = FCString::Atod(*QuatComponents[0]);
                NewState.Rotation.Y = FCString::Atod(*QuatComponents[1]);
                NewState.Rotation.Z = FCString::Atod(*QuatComponents[2]);
                NewState.Rotation.W = FCString::Atod(*QuatComponents[3]);
            }
        }

        // Extract Parent
        tinyxml2::XMLElement* ParentElement = ObjectElement->FirstChildElement("parent");
        if (ParentElement && ParentElement->GetText())
        {
            NewState.ParentID = UTF8_TO_TCHAR(ParentElement->GetText());
        }

        // Extract Visibility
        tinyxml2::XMLElement* VisElement = ObjectElement->FirstChildElement("vis");
        if (VisElement && VisElement->GetText())
        {
            FString VisStr = UTF8_TO_TCHAR(VisElement->GetText());
            NewState.bIsVisible = (VisStr == TEXT("1"));
        }

        // Add the object state to our array
        ObjectStates.Add(NewState.ID, NewState);
    }

    return ObjectStates;
}


void UMPC2Loader::ProcessTelemetryFileMPC2(const FString& TelemetryPath, USimulationGameInstance* GameInstance)
{
    // Load XML File
    XMLDocument doc;
	if (doc.LoadFile(TCHAR_TO_UTF8(*TelemetryPath)) != XML_SUCCESS)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to load XML file: %s"), *TelemetryPath);
		return;
	}

	// Get the root element
	XMLElement* root = doc.FirstChildElement("mpc");
	if (!root)
	{
		UE_LOG(LogTemp, Error, TEXT("Invalid XML root node."));
		return;
	}

    // Get first time tag
	XMLElement* timeTag = root->FirstChildElement("time");
	if (!timeTag)
	{
		UE_LOG(LogTemp, Error, TEXT("Invalid time tag node."));
		return;
	}

    const char* timeValue = timeTag->Attribute("value");
    double TimeValue = FCString::Atod(UTF8_TO_TCHAR(timeValue));
    GameInstance->SetStartTime(static_cast<float>(TimeValue));
	// Iterate through all time tags
	while (timeTag)
	{
		timeValue = timeTag->Attribute("value");
		if (timeValue)
		{
			TimeValue = FCString::Atod(UTF8_TO_TCHAR(timeValue));
			FString TimeTagXML = UTF8_TO_TCHAR(timeTag->GetText());

			// Extract object states
			TMap<FString, FObjectState> ObjectStates = ExtractObjectStatesMPC2(timeTag);

			// Create a new snapshot
			FTimeSnapshot NewSnapshot;
			NewSnapshot.TimeValue = TimeValue;
			NewSnapshot.ObjectStates = ObjectStates;
            GameInstance->SetTelemetryData(NewSnapshot.TimeValue, NewSnapshot.ObjectStates);

            // Load data onto the timeline (this should replace the above)
            if (GameInstance->Timeline == NULL)
            {
                GameInstance->Timeline = new UTelemetryTimeline();
            }
            
            GameInstance->Timeline->PushTelemetryData(ObjectStates);
		}
		timeTag = timeTag->NextSiblingElement("time");
	}
	GameInstance->SetEndTime(static_cast<float>(TimeValue));
}


TArray<FTerrainMetadata> UMPC2Loader::GetTerrainData()
{
    return CurrentSimulationData.Terrains;
}


TArray<FLightData> UMPC2Loader::GetLightData()
{
    return CurrentSimulationData.Lights;
}


TArray<FModelMetadata> UMPC2Loader::GetModelData()
{
    return CurrentSimulationData.Models;
}

TArray<FObjectsOfInterest> UMPC2Loader::GetObjectsOfInterest()
{
    return CurrentSimulationData.ObjectsOfInterest;
}

FString UMPC2Loader::GetAuthor()
{
    return CurrentSimulationData.Author;
}

FString UMPC2Loader::GetDescription()
{
	return CurrentSimulationData.Description;
}

FString UMPC2Loader::GetName()
{
	return CurrentSimulationData.Name;
}
