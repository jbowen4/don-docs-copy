

# File FileRecorder.h

[**File List**](files.md) **>** [**DONToUnreal**](dir_7e70b7b4a1df651b2af4c8dca0b54b92.md) **>** [**Public**](dir_c336ec6675be099178e02bcdcfb186ce.md) **>** [**FileRecorder.h**](_file_recorder_8h.md)

[Go to the documentation of this file](_file_recorder_8h.md)


```C++
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

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
```


