// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "Avatar.h"
#include "AvatarAIController.generated.h"

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

	void AimTowardPlayer();
	
	// Override over Player Controller
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
