// Fill out your copyright notice in the Description page of Project Settings.

#include "FileRecorder.h"
#include "tinyxml2.h"
#include "Misc/FileHelper.h"

FileRecorder::FileRecorder(const FString& inFilename, const FString& RecordingDirectory) 
{

	FString RecordingFilePath = FPaths::Combine(RecordingDirectory, inFilename + FString(TEXT(".xml")));
	FString RecordingDir = FPaths::GetPath(RecordingFilePath);

	// Creates Recording Directory if nonexistent
	if (!IFileManager::Get().DirectoryExists(*RecordingDir))
	{
		bool bCreated = IFileManager::Get().MakeDirectory(*RecordingDir, true);
		if (bCreated)
		{
			UE_LOG(LogTemp, Log, TEXT("Directory created successfully: %s"), *RecordingDir);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Failed to create directory: %s"), *RecordingDir);
		}
	}

	//Saves Recording File Path
	FilePath = RecordingFilePath;

	//Recording File open in append mode
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	FileHandle = PlatformFile.OpenWrite(*FilePath, true);
	if (!FileHandle)
	{
		UE_LOG(LogTemp, Error, TEXT("Failed to open recording file"));
	}

	UE_LOG(LogTemp, Log, TEXT("FileRecorder created using filename: %s"), *inFilename);
}

std::string FileRecorder::formatXMLWithTinyXML2(const std::string& inputXML) {
	tinyxml2::XMLDocument doc;
	tinyxml2::XMLError result = doc.Parse(inputXML.c_str());

	if (result != tinyxml2::XML_SUCCESS) {
		UE_LOG(LogTemp, Error, TEXT("Error parsing XML: %s"), UTF8_TO_TCHAR(doc.ErrorStr()));
		return "";
	}

	tinyxml2::XMLPrinter printer;
	doc.Print(&printer);

	return printer.CStr();
}

void FileRecorder::ConvertTxtToXML(FString inputPath, FString outPath)
{
	FString fileContent;
	if (!FFileHelper::LoadFileToString(fileContent, *inputPath)) {
		UE_LOG(LogTemp, Error, TEXT("Error: Could not open input file %s"), *inputPath);
		return;
	}

	std::string formattedXml = formatXMLWithTinyXML2(TCHAR_TO_UTF8(*fileContent));

	if (formattedXml.empty()) {
		UE_LOG(LogTemp, Error, TEXT("Error: Failed to format XML content from %s"), *inputPath);
		return;
	}

	if (!FFileHelper::SaveStringToFile(UTF8_TO_TCHAR(formattedXml.c_str()), *outPath)) {
		UE_LOG(LogTemp, Error, TEXT("Error: Could not open output file %s"), *outPath);
		return;
	}

	UE_LOG(LogTemp, Log, TEXT("Successfully converted and formatted XML from %s to %s"), *inputPath, *outPath);
}

void FileRecorder::CloseWriter()
{
	if (FileHandle)
	{
		delete FileHandle;
		FileHandle = nullptr;
	}
	ConvertTxtToXML(FilePath, FilePath);
	UE_LOG(LogTemp, Log, TEXT("FileRecorder destroyed"));
}

void FileRecorder::AppendXML(const FString& XMLChunk)
{
	if (FileHandle)
	{
		// Add original XML chunk
		FileHandle->Write((const uint8*)TCHAR_TO_ANSI(*XMLChunk), XMLChunk.Len());

		//UE_LOG(LogTemp, Log, TEXT("Chunk successfully appended to: %s"), *FilePath);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("File handle is invalid, cannot append"));
	}
}
