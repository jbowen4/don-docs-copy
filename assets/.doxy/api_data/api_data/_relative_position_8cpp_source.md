

# File RelativePosition.cpp

[**File List**](files.md) **>** [**Data**](dir_c6f65c82417afbaa7503bbb02bffcee2.md) **>** [**RelativePosition.cpp**](_relative_position_8cpp.md)

[Go to the documentation of this file](_relative_position_8cpp.md)


```C++
// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/RelativePosition.h"

FRelativePosition FRelativePosition::ORIGIN = FRelativePosition();

double FRelativePosition::DistanceSqTo(const FRelativePosition& Other) const
{
    if (Other.NestIndex == this->NestIndex && Other.Parent == this->Parent)
    {
        return FVector::DistSquared(this->RelativePos, Other.RelativePos);
    }

    FVector p1(0, 0, 0);
    FVector p2(0, 0, 0);
    if (auto err = GetPositionsRelativeToCommonParent(*this, Other, p1, p2))
        throw FString::Printf(TEXT("Error: %d"), err);
    return FVector::DistSquared(p1, p2);
}


void FRelativePosition::GetAbsoluteOrientation(FQuat& outOrientation) const
{
    return; // TODO
}

void FRelativePosition::GetAbsolutePosition(FVector& OutPos) const
{
    OutPos += this->RelativePos;
    if (Parent != nullptr)
    {
        Parent->GetAbsolutePosition(OutPos);
    }
}

FRelativePosition::ErrorCode FRelativePosition::GetPositionsRelativeToCommonParent(const FRelativePosition& Pos1, const FRelativePosition& Pos2, FVector& OutPos1, FVector& OutPos2)
{
    OutPos1 = FVector::ZeroVector;
    OutPos2 = FVector::ZeroVector;

    ErrorCode err = OK;

    if (Pos1.NestIndex == Pos2.NestIndex)
    {
        if (Pos1.Parent == Pos2.Parent)
        {
            OutPos1 = Pos1.RelativePos;
            OutPos2 = Pos2.RelativePos;
        }
        else
        {
            err = GetPositionsRelative_Both(Pos1, Pos2, OutPos1, OutPos2);
        }
    }
    else if (Pos1.NestIndex > Pos2.NestIndex)
    {
        err = GetPositionsRelative_Higher(Pos2, Pos1, OutPos2, OutPos1);
    }
    else
    {
        err = GetPositionsRelative_Higher(Pos1, Pos2, OutPos1, OutPos2);
    }

    if (err == OK)
        return OK;

    // on error
    OutPos1 = FVector::Zero();
    OutPos2 = FVector::Zero();
    return err;
}

FRelativePosition::ErrorCode FRelativePosition::GetPositionsRelative_Higher(const FRelativePosition& LessNested, const FRelativePosition& MoreNested, FVector& OutLessNested, FVector& OutMoreNested)
{
    const FRelativePosition* currentMoreNested = &MoreNested;

    while (currentMoreNested != nullptr && currentMoreNested->NestIndex > LessNested.NestIndex)
    {
        OutMoreNested += currentMoreNested->RelativePos;
        currentMoreNested = currentMoreNested->Parent;
    }

    if (currentMoreNested == nullptr)
    {
        return NO_COMMON_PARENT;
    }

    if (LessNested.Parent != currentMoreNested->Parent)
    {
        return GetPositionsRelative_Both(LessNested, *currentMoreNested, OutLessNested, OutMoreNested);
    }
    OutMoreNested += currentMoreNested->RelativePos;
    OutLessNested = LessNested.RelativePos;

    return OK;
}

FRelativePosition::ErrorCode FRelativePosition::GetPositionsRelative_Both(const FRelativePosition& Pos1, const FRelativePosition& Pos2, FVector& OutPos1, FVector& OutPos2)
{
    // Assertion
    if (!(Pos1.NestIndex == Pos2.NestIndex && Pos1.Parent != Pos2.Parent))
    {
        UE_LOG(LogLevel, Error, TEXT("Illegal Argument: Incoming positions must have same nest index but different parents: %ls and %ls"), *Pos1.ToString(), *Pos2.ToString());
        return ILLEGAL_STATE;
    }

    const FRelativePosition* currentParent1 = &Pos1;
    const FRelativePosition* currentParent2 = &Pos2;

    while (currentParent1 != nullptr && currentParent2 != nullptr && currentParent1 != currentParent2)
    {
        OutPos1 += currentParent1->RelativePos;
        OutPos2 += currentParent2->RelativePos;

        currentParent1 = currentParent1->Parent;
        currentParent2 = currentParent2->Parent;
    }

    if ((currentParent1 == nullptr || currentParent2 == nullptr) && currentParent1 != currentParent2)
    {
        UE_LOG(LogLevel, Error, TEXT("[RelativePosition | GetPositionsRelative_Both] Positions '%ls' and '%ls' do not have a common parent"), *Pos1.ToString(), *Pos2.ToString());
        return NO_COMMON_PARENT;
    }
    return OK;
}

FString FRelativePosition::ToString() const
{
    FString parentStr;
    if (Parent == nullptr)
    {
        parentStr = TEXT("null");
    }
    else
    {
        parentStr = Parent->ToString();
    }

    return FString::Printf(TEXT("FRootedPosition[RelativePos=%s,Orientation=%s,Parent=%s,NestIndex=%d]"), *RelativePos.ToString(), *Orientation.ToString(), *parentStr, NestIndex);
}

FRelativePosition::ErrorCode FRelativePosition::GetPositionRelativeTo(const FRelativePosition& Other, FVector& OutPos) const
{
    FVector otherPosRel;
    if (ErrorCode err = GetPositionsRelativeToCommonParent(*this, Other, OutPos, otherPosRel))
        return err;
    OutPos -= otherPosRel;

    return OK;
}
```


