

# File ObjectInfo.h

[**File List**](files.md) **>** [**Data**](dir_436819c72972a51f013170f2c377a0ea.md) **>** [**ObjectInfo.h**](_object_info_8h.md)

[Go to the documentation of this file](_object_info_8h.md)


```C++
// ReSharper disable CppRedundantBaseClassInitializer
#pragma once

#include "CoreMinimal.h"
#include "RelativePosition.h"
#include "Util/Types/TOptRef.h"
#include "ObjectInfo.generated.h"


using ObjID = FName;

USTRUCT()
struct DONTOUNREAL_API FObjectInfo : public FRelativePosition
{
    GENERATED_BODY()

private:
    friend struct FObjectInfoStore;

public:
    static FObjectInfo ORIGIN;

protected: // effectively immutable from the outside
    UPROPERTY()
    FName name;

    UPROPERTY()
    bool isVisible;

private:
    TOptRef<const FObjectInfo> parent;

protected:
    FORCEINLINE void SetParentRef(TOptRef<const FObjectInfo> NewParent)
    {
        parent = NewParent;
        // ReSharper disable once CppRedundantQualifier
        FRelativePosition::Parent = NewParent.GetPtrOrNull();
    }

public:
    FORCEINLINE const ObjID& GetName() const { return name; }

    FORCEINLINE bool IsVisible() const { return isVisible; }

    FORCEINLINE const TOptRef<const FObjectInfo>& GetParent() const { return parent; }

    inline FObjectInfo(const ObjID& Name, const bool Visibility, const TOptRef<const FObjectInfo>& ParentIn, const FVector& Position, const FQuat& Orientation)
        : FRelativePosition(&ParentIn.GetOrDefault(ORIGIN), Position, Orientation), name(Name), isVisible(Visibility), parent(ParentIn.GetOrDefault(ORIGIN))
    {
    };

    inline FObjectInfo()
        : FRelativePosition(), isVisible(false)
    {
    };


    inline FString ToString() const
    {
        return FString::Printf(TEXT("FObjectInfo[Name=%ls,Visibility=%d,Parent=%ls,%ls]"), *name.ToString(), isVisible, *parent.MapOwned<FString>([](auto it) { return it.ToString(); }).Get(TEXT("null")), *FRelativePosition::ToString());
    }

    //region Move
    FObjectInfo(const FObjectInfo& other)
        : FRelativePosition(other),
          name(other.name),
          isVisible(other.isVisible),
          parent(other.parent)
    {
    }

    FObjectInfo(FObjectInfo&& other) noexcept
        : FRelativePosition(MoveTempIfPossible(other)),
          name(MoveTempIfPossible(other.name)),
          isVisible(other.isVisible),
          parent(MoveTempIfPossible(other.parent))
    {
    }

    FObjectInfo& operator=(const FObjectInfo& other)
    {
        if (this == &other)
            return *this;
        FRelativePosition::operator =(other);
        name = other.name;
        isVisible = other.isVisible;
        parent = other.parent;
        return *this;
    }

    FObjectInfo& operator=(FObjectInfo&& other) noexcept
    {
        if (this == &other)
            return *this;
        FRelativePosition::operator =(MoveTempIfPossible(other));
        name = MoveTempIfPossible(other.name);
        isVisible = other.isVisible;
        parent = MoveTempIfPossible(other.parent);
        return *this;
    }

    //endregion

    //region Comparison
    friend bool operator==(const FObjectInfo& lhs, const FObjectInfo& rhs)
    {
        // ReSharper disable CppRedundantCastExpression
        return lhs.name == rhs.name
            && lhs.isVisible == rhs.isVisible
            && lhs.RelativePos == rhs.RelativePos
            && lhs.Orientation == rhs.Orientation
            // parents have loose equality
            && lhs.parent.MapRef<const FName>([](auto& it) -> const FName& { return it.GetName(); })
            == rhs.parent.MapRef<const FName>([](auto& it) -> const FName& { return it.GetName(); });
    }

    friend bool operator!=(const FObjectInfo& lhs, const FObjectInfo& rhs)
    {
        return !(lhs == rhs);
    }

    //endregion

    //region Functional Transformation of Immutable Objects
    #define _WITH(_varType, _varName) FObjectInfo With##_varName(TCallTraits<_varType>::ParamType New##_varName)

    _WITH(FName, Name)
    {
        return FObjectInfo(NewName, isVisible, parent, RelativePos, Orientation);
    }
    _WITH(bool, Visibility)
    {
        return FObjectInfo(name, NewVisibility, parent, RelativePos, Orientation);
    }
    _WITH(TOptRef<const FObjectInfo>, Parent)
    {
        return FObjectInfo(name, isVisible, NewParent, RelativePos, Orientation);
    }
    _WITH(FVector, RelativePos)
    {
        return FObjectInfo(name, isVisible, parent, NewRelativePos, Orientation);
    }
    _WITH(FQuat, Orientation)
    {
        return FObjectInfo(name, isVisible, parent, RelativePos, NewOrientation);
    }
    
    #undef _WITH
    //endregion
};
```


