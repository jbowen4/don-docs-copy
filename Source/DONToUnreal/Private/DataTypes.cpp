#include "DataTypes.h"

// FModelMetadata conversion functions
FVector FModelMetadata::ConvertPositionToUnreal() const
{
	return StaticPosition;
}


FQuat FModelMetadata::ConvertOrientationToUnreal() const
{
	return StaticOrientation;
}


FVector FModelMetadata::ConvertScaleToUnreal() const
{
    return StaticScale;
}


// FTerrainMetadata conversion functions
FVector FTerrainMetadata::ConvertPositionToUnreal() const
{
	return Position;
}


FQuat FTerrainMetadata::ConvertOrientationToUnreal() const
{
	return Orientation;
}


// FObjectState conversion functions
FVector FObjectState::ConvertPositionToUnreal() const
{
	return Position;
}


FVector FObjectState::ConvertVelocityToUnreal() const
{
	return Velocity;
}


FQuat FObjectState::ConvertRotationToUnreal() const
{
	return Rotation;	
}
