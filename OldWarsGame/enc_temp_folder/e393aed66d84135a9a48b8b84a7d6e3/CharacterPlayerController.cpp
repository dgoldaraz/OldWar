// Fill out your copyright notice in the Description page of Project Settings.

#include "OldWarsGame.h"
#include "CharacterPlayerController.h"


void ACharacterPlayerController::BeginPlay()
{
	Super::BeginPlay();
	AAvatar* CAvatar = GetAvatar();
	UE_LOG(LogTemp, Warning, TEXT("Player Controller possesing : %s"),CAvatar != nullptr ? *CAvatar->GetName() : TEXT("<null>") );
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
	if (!GetAvatar())
	{
		return;
	}

	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation)) //Line trace trhough the 2d white dot
	{
		UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *HitLocation.ToString());
		//Tell controlled weapon to aim to this location
	}
	//Get World location if line trace through crosshair
	//if it hits the landscape
		//we wANT the control avatar to aim to this
}

//Get World location of linetracer through crosshair, true if hits landscape
bool ACharacterPlayerController::GetSightRayHitLocation(FVector& HitLocation)
{

	//Find Crosshair location
	//"De-project" the screen position of the crosshair to a world direction
	//Line trace along that direction
	//See what we hit (up to a max range)

	int32 ViewportSizeX, ViewportSizeY;

	GetViewportSize(ViewportSizeX, ViewportSizeY);

	FVector2D ScreenPosition(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
	return true;
}