// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class DONTOUNREAL_API FileRecorder
{
private:
	FString FilePath;
	IFileHandle* FileHandle;
public:
	explicit FileRecorder(const FString& inFilename, const FString& RecordingDirectory);
	~FileRecorder();

	void AppendXML(const FString& XMLChunk);
	FString FormatXML(const FString& XMLChunk);
	std::string formatXMLWithTinyXML2(const std::string& inputXML);
	void ConvertTxtToXML(FString inputPath, FString outPath);
	void CloseWriter();
};
