// Fill out your copyright notice in the Description page of Project Settings.

#include "OldWarsGame.h"
#include "Avatar.h"
#include "Public/AvatarAIController.h"

void AAvatarAIController::BeginPlay()
{
	Super::BeginPlay();
}

void AAvatarAIController::Tick(float DeltaTime)
{
	if (GetAvatar() && GetPlayerAvatar())
	{	
		//Move towards the player

		//Aim to the player
		FVector HitLocation = FVector::ZeroVector;
		if (AimTowardPlayer(HitLocation))
		{
			GetAvatar()->AimAt(HitLocation);
		}
		//Fire is ready
	}
	
}

AAvatar* AAvatarAIController::GetAvatar() const
{
	return Cast<AAvatar>(GetPawn());
}

AAvatar* AAvatarAIController::GetPlayerAvatar() const
{
	APawn* FirstPlayerController = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (FirstPlayerController)
	{
		return Cast<AAvatar>(FirstPlayerController);
	}

	return nullptr;
}

bool AAvatarAIController::AimTowardPlayer(FVector& HitLocation)
{
	HitLocation = GetPlayerAvatar()->GetActorLocation();
	return true;
}

