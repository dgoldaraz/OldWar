// Fill out your copyright notice in the Description page of Project Settings.

#include "OldWarsGame.h"
#include "Public/Avatar.h"
#include "CharacterPlayerController.h"


void ACharacterPlayerController::BeginPlay()
{
	Super::BeginPlay();
	AAvatar* CAvatar = GetAvatar();
}


AAvatar* ACharacterPlayerController::GetAvatar() const
{
	return Cast<AAvatar>(GetPawn());
}

void ACharacterPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardCrosshair();
}

void ACharacterPlayerController::AimTowardCrosshair()
{
	if (GetAvatar())
	{
		FVector HitLocation = FVector::ZeroVector;
		if (GetSightRayHitLocation(HitLocation)) //Line trace trhough the 2d white dot
		{
			GetAvatar()->AimAt(HitLocation);
		}
	}

	
}

//Get World location of linetracer through crosshair, true if hits landscape
bool ACharacterPlayerController::GetSightRayHitLocation(FVector& HitLocation)
{
	//Find Crosshair location
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenPosition(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
	FVector LookDirection;
	//"De-project" the screen position of the crosshair to a world direction
	if (GetLookDirection(ScreenPosition, LookDirection))
	{
		//Line trace along that direction andSee what we hit (up to a max range)
		return GetVectorHitLocation(LookDirection, HitLocation);
	}
	return false;
}

bool ACharacterPlayerController::GetLookDirection(FVector2D ScreenPosition, FVector& LookDirection) const
{
	//"De-project" the screen position of the crosshair to a world direction
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(ScreenPosition.X, ScreenPosition.Y, CameraWorldLocation, LookDirection);
}

bool ACharacterPlayerController::GetVectorHitLocation(FVector LookDirection, FVector& HitLocation ) const
{
	
	FHitResult HitResult;

	FVector StartPosition = PlayerCameraManager->GetCameraLocation();
	bool bHit = GetWorld()->LineTraceSingleByChannel(HitResult, StartPosition, StartPosition + (LookDirection * LineTraceRange),ECollisionChannel::ECC_Visibility);
	if (bHit)
	{
		HitLocation = HitResult.Location;
	}
	else
	{
		HitLocation = FVector::ZeroVector;
	}

	return bHit;
}