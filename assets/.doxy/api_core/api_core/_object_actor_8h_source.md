

# File ObjectActor.h

[**File List**](files.md) **>** [**DONToUnreal**](dir_7e70b7b4a1df651b2af4c8dca0b54b92.md) **>** [**Public**](dir_c336ec6675be099178e02bcdcfb186ce.md) **>** [**ObjectActor.h**](_object_actor_8h.md)

[Go to the documentation of this file](_object_actor_8h.md)


```C++
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
```


