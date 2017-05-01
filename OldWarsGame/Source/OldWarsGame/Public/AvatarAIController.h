// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "AvatarAIController.generated.h"

class AAvatar;
/**
 * This class manages the AI Controller of the enemies
 */
UCLASS()
class OLDWARSGAME_API AAvatarAIController : public AAIController
{
	GENERATED_BODY()
	
private:

	AAvatar* GetAvatar() const;

	AAvatar* GetPlayerAvatar() const;

	bool AimTowardPlayer(FVector& HitLocation);
	
	// Override over Player Controller
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	//How close AI can be to the player
	float AcceptanceRadius = 3000;


};
