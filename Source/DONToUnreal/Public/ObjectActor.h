#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/WidgetComponent.h"
#include "ObjectActor.generated.h"

UCLASS()
class DONTOUNREAL_API AObjectActor : public AActor
{
    GENERATED_BODY()

public:
    // Identifier for this object
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Object Actor")
    FString ObjectId;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Object Actor")
    FString Name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Object Actor")
    bool IsObjectOfInterest;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Object Actor")
    bool vis = true;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Object Actor")
    bool isStatic = false;

protected:
    virtual void BeginPlay() override;
};
