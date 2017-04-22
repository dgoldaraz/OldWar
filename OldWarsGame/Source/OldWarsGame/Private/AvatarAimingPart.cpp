// Fill out your copyright notice in the Description page of Project Settings.

#include "OldWarsGame.h"
#include "Public/AvatarAimingPart.h"


void UAvatarAimingPart::Elevate(float RelativeSpeed)
{
	//Move the aiming part the right amount this frame
	//Given a max elevation speed, and the frame time
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0f, 1.0f);
	auto ElevationChange = RelativeSpeed * MaxElevationDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Elevation = FMath::Clamp<float>(RelativeRotation.Pitch + ElevationChange, MinElevationDegree, MaxElevationDegree);
	SetRelativeRotation(FRotator(Elevation, RelativeRotation.Yaw, RelativeRotation.Roll));
}

void UAvatarAimingPart::Rotate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.0f, 1.0f);
	auto RotationChange = RelativeSpeed * MaxRotateDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	auto Rotation = RelativeRotation.Yaw + RotationChange;
	SetRelativeRotation(FRotator(RelativeRotation.Pitch, Rotation, RelativeRotation.Roll));
}