// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Util/Types/TOptRef.h"
#include "Util/ClassMacros.h"
#include "RelativePosition.generated.h"


/**
 * A position that's relative to some parent.
 *
 * Allows you to find the position, distance, etc. between two objects that are rooted in different parents.
 */
USTRUCT()
struct DONTOUNREAL_API FRelativePosition
{
	GENERATED_BODY()
	/**
	 * The universal origin for the coordinate system.
	 */
	static FRelativePosition ORIGIN;

	enum ErrorCode
	{
		/// No error
		OK = 0,
		/// Internal exception
		ILLEGAL_STATE,
		/// The two positions do not have any parents in common.
		NO_COMMON_PARENT
	};

protected: // effectively immutable
	/**
	 * The object that @link RelativePos @endlink is relative to.
	 *
	 * Should never be stale, assuming everything is constructed through and stored in the @link FObjectInfoStore @endlink.
	 */
	FRelativePosition const* Parent;

	/**
	 * How deeply this object is nested in the parent-child tree. Root is 0.
	 */
	int NestIndex;

	/**
	 * The offset of this object from the parent's position.
	 */
	FVector RelativePos;

	/**
	 * The orientation of this object in 3D space relative to the parent, in Unreal's format.
	 */
	FQuat Orientation;

public:
	/**
	 * The object that @link GetRelativePos@endlink is relative to.
	 *
	 * Should never be stale, assuming everything is constructed through and stored in the @link FObjectInfoStore@endlink.
	 */
	[[nodiscard]] FORCEINLINE TOptRef<const FRelativePosition> GetParent() const { return Parent; }

	/**
	 * How deeply this object is nested in the parent-child tree. Root is 0.
	 */
	GETTER(int, NestIndex)

	/**
	 * The offset of this object from the parent's position.
	 */
	GETTER(FVector, RelativePos)

	/**
	 * The orientation of this object in 3D space relative to the parent, in Unreal's format.
	 */
	GETTER(FQuat, Orientation)

	/**
	 * 
	 * @param ParentIn The position RelativePosIn is relative to. If empty, will be set to the universal origin.
	 * @param RelativePosIn The relative offset of this object from the parent's position.
	 * @param OrientationIn The orientation of this object relative to the parent.
	 */
	inline FRelativePosition(const TOptRef<const FRelativePosition>& ParentIn, const FVector& RelativePosIn, const FQuat& OrientationIn)
		: Parent(&ParentIn.GetOrDefault(ORIGIN)), NestIndex(Parent->NestIndex + 1), RelativePos(RelativePosIn), Orientation(OrientationIn)
	{
	}

	inline FRelativePosition(const FRelativePosition* ParentIn_Nullable, const FVector& RelativePosIn, const FQuat& OrientationIn)
		: Parent((ParentIn_Nullable == nullptr) ? &ORIGIN : ParentIn_Nullable), NestIndex(Parent->NestIndex + 1), RelativePos(RelativePosIn), Orientation(OrientationIn)
	{
	}


	void GetAbsoluteOrientation(FQuat& outOrientation) const;

	/**
	 * Adds the absolute position relative to the universal origin to the OutPos vector.
	 * @param OutPos Return value for the position.  Should be zeroed before calling, as the output position is iteratively added to it.
	 */
	void GetAbsolutePosition(FVector& OutPos) const;

	/**
	 * Get the position of this object relative to the other.
	 *
	 * For example, the position of the Moon relative to Mars would be "Moon->Earth + Earth->Sun - Mars->Sun"
	 * @param Other The position this should be gotten relative to.
	 * @param OutPos Where the output position should be saved to.
	 * @return 0 if successful, else the error code.
	 */
	[[nodiscard]] ErrorCode GetPositionRelativeTo(const FRelativePosition& Other, FVector& OutPos) const;

	/**
	 * Get the distance squared to another FRootedPosition's position.
	 *
	 * Traverses the nesting tree to find an absolute distance between the two points.
	 */
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

	/**
	 * Get both positions as relative offsets from their common parent.
	 *
	 * For example: @code GetPositionsRelativeToCommonParent(earth, moon)@endcode would output @code (<position of earth relative to sun>, <position of moon relative to sun>)@endcode.
	 * @param Pos1
	 * @param Pos2
	 * @param OutPos1 Return slot for the potentially-transformed position of Pos1.
	 * @param OutPos2 Return slot for the potentially-transformed position of Pos2.
	 * @return 0 if successful, else the error code.
	 */
	[[nodiscard]] static ErrorCode GetPositionsRelativeToCommonParent(const FRelativePosition& Pos1, const FRelativePosition& Pos2, FVector& OutPos1, FVector& OutPos2);

private:
	[[nodiscard]] inline static ErrorCode GetPositionsRelative_Higher(const FRelativePosition& LessNested, const FRelativePosition& MoreNested, FVector& OutLessNested, FVector& OutMoreNested);

	[[nodiscard]] inline static ErrorCode GetPositionsRelative_Both(const FRelativePosition& Pos1, const FRelativePosition& Pos2, FVector& OutPos1, FVector& OutPos2);

public:
	/**
	 * I hate how everything has to be public for Unreal's reflection system. DON'T USE THIS!!! EVER!!!!!!!
	 */
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

	/**
	 * Create a new instance that has all of the same values as this but with the provided Parent.
	 */
	_WITH(TOptRef<const FRelativePosition>, Parent)
	{
		return FRelativePosition(NewParent, RelativePos, Orientation);
	}

	/**
	 * Create a new instance that has all of the same values as this but with the provided RelativePos.
	 */
	_WITH(FVector, RelativePos)
	{
		return FRelativePosition(Parent, NewRelativePos, Orientation);
	}

	/**
	 * Create a new instance that has all of the same values as this but with the provided Orientation.
	 */
	_WITH(FQuat, Orientation)
	{
		return FRelativePosition(Parent, RelativePos, NewOrientation);
	}

	#undef _WITH
	//endregion FTIO
};
