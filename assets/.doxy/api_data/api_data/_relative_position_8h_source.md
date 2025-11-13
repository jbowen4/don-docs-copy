

# File RelativePosition.h

[**File List**](files.md) **>** [**Data**](dir_436819c72972a51f013170f2c377a0ea.md) **>** [**RelativePosition.h**](_relative_position_8h.md)

[Go to the documentation of this file](_relative_position_8h.md)


```C++
// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Util/Types/TOptRef.h"
#include "Util/ClassMacros.h"
#include "RelativePosition.generated.h"


USTRUCT()
struct DONTOUNREAL_API FRelativePosition
{
    GENERATED_BODY()
    static FRelativePosition ORIGIN;

    enum ErrorCode
    {
        OK = 0,
        ILLEGAL_STATE,
        NO_COMMON_PARENT
    };

protected: // effectively immutable
    FRelativePosition const* Parent;

    int NestIndex;

    FVector RelativePos;

    FQuat Orientation;

public:
    [[nodiscard]] FORCEINLINE TOptRef<const FRelativePosition> GetParent() const { return Parent; }

    GETTER(int, NestIndex)

    
    GETTER(FVector, RelativePos)

    
    GETTER(FQuat, Orientation)

    
    inline FRelativePosition(const TOptRef<const FRelativePosition>& ParentIn, const FVector& RelativePosIn, const FQuat& OrientationIn)
        : Parent(&ParentIn.GetOrDefault(ORIGIN)), NestIndex(Parent->NestIndex + 1), RelativePos(RelativePosIn), Orientation(OrientationIn)
    {
    }

    inline FRelativePosition(const FRelativePosition* ParentIn_Nullable, const FVector& RelativePosIn, const FQuat& OrientationIn)
        : Parent((ParentIn_Nullable == nullptr) ? &ORIGIN : ParentIn_Nullable), NestIndex(Parent->NestIndex + 1), RelativePos(RelativePosIn), Orientation(OrientationIn)
    {
    }


    void GetAbsoluteOrientation(FQuat& outOrientation) const;

    void GetAbsolutePosition(FVector& OutPos) const;

    [[nodiscard]] ErrorCode GetPositionRelativeTo(const FRelativePosition& Other, FVector& OutPos) const;

    double DistanceSqTo(const FRelativePosition& Other) const;

    double DistanceTo(const FRelativePosition& Other) const
    {
        return FMath::Sqrt(DistanceSqTo(Other));
    }

    FString ToString() const;

    bool IsOrigin() const
    {
        return NestIndex == 0;
    }

    [[nodiscard]] static ErrorCode GetPositionsRelativeToCommonParent(const FRelativePosition& Pos1, const FRelativePosition& Pos2, FVector& OutPos1, FVector& OutPos2);

private:
    [[nodiscard]] inline static ErrorCode GetPositionsRelative_Higher(const FRelativePosition& LessNested, const FRelativePosition& MoreNested, FVector& OutLessNested, FVector& OutMoreNested);

    [[nodiscard]] inline static ErrorCode GetPositionsRelative_Both(const FRelativePosition& Pos1, const FRelativePosition& Pos2, FVector& OutPos1, FVector& OutPos2);

public:
    FRelativePosition()
        : Parent(nullptr), NestIndex(0), RelativePos(0), Orientation(0)
    {
    };

    //region Copy/Move
    FRelativePosition(const FRelativePosition& other)
        : Parent(other.Parent),
          NestIndex(other.NestIndex),
          RelativePos(other.RelativePos),
          Orientation(other.Orientation)
    {
    }

    FRelativePosition(FRelativePosition&& other) noexcept
        : Parent(other.Parent),
          NestIndex(other.NestIndex),
          RelativePos(MoveTempIfPossible(other.RelativePos)),
          Orientation(MoveTempIfPossible(other.Orientation))
    {
    }

    FRelativePosition& operator=(const FRelativePosition& other)
    {
        if (this == &other)
            return *this;
        Parent = other.Parent;
        NestIndex = other.NestIndex;
        RelativePos = other.RelativePos;
        Orientation = other.Orientation;
        return *this;
    }

    FRelativePosition& operator=(FRelativePosition&& other) noexcept
    {
        if (this == &other)
            return *this;
        Parent = other.Parent;
        NestIndex = other.NestIndex;
        RelativePos = MoveTempIfPossible(other.RelativePos);
        Orientation = MoveTempIfPossible(other.Orientation);
        return *this;
    }

    //endregion

    //region Equality
    friend bool operator==(const FRelativePosition& lhs, const FRelativePosition& rhs)
    {
        return lhs.Parent == rhs.Parent // TODO figure out how to compare without either comparing reference equality or going all the way down the tree
            && lhs.NestIndex == rhs.NestIndex
            && lhs.RelativePos == rhs.RelativePos
            && lhs.Orientation == rhs.Orientation;
    }

    friend bool operator!=(const FRelativePosition& lhs, const FRelativePosition& rhs)
    {
        return !(lhs == rhs);
    }

    //endregion

    //region Functional Transformation of Immutable Objects
    #define _WITH(_varType, _varName) FRelativePosition With##_varName(TCallTraits<_varType>::ParamType New##_varName)

    _WITH(TOptRef<const FRelativePosition>, Parent)
    {
        return FRelativePosition(NewParent, RelativePos, Orientation);
    }

    _WITH(FVector, RelativePos)
    {
        return FRelativePosition(Parent, NewRelativePos, Orientation);
    }

    _WITH(FQuat, Orientation)
    {
        return FRelativePosition(Parent, RelativePos, NewOrientation);
    }

    #undef _WITH
    //endregion FTIO
};
```


