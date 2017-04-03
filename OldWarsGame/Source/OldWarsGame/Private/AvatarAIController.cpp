// Fill out your copyright notice in the Description page of Project Settings.

#include "OldWarsGame.h"
#include "AvatarAIController.h"

void AAvatarAIController::BeginPlay()
{
	Super::BeginPlay();
	AAvatar* CAvatar = GetAvatar();
	AAvatar* PAvatar = GetPlayerAvatar();
	UE_LOG(LogTemp, Warning, TEXT("AI Controller possesing : %s"), CAvatar != nullptr ? *CAvatar->GetName() : TEXT("<null>"));
	UE_LOG(LogTemp, Warning, TEXT("AI Controller find Player as: %s"), PAvatar != nullptr ? *PAvatar->GetName() : TEXT("<null>"));
}

void AAvatarAIController::Tick(float DeltaTime)
{

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

void AAvatarAIController::AimTowardPlayer()
{

}

