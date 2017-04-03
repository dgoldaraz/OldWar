// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "Avatar.h"
#include "CharacterPlayerController.generated.h"

/**
 * Player Controller 
 */
UCLASS()
class OLDWARSGAME_API ACharacterPlayerController : public APlayerController
{
	GENERATED_BODY()
	
		
public:


private:
	UPROPERTY(EditAnywhere, Category = CrossHair)
	float CrossHairXLocation = 0.5f;
	UPROPERTY(EditAnywhere, Category = CrossHair)
	float CrossHairYLocation = 0.33333f;

	AAvatar* GetAvatar() const;
	//Start the Avatar moving the weapon so as the shot will hit where is pointing
	void AimTowardCrosshair();

	bool GetSightRayHitLocation(FVector& HitLocation);

	// Override over Player Controller
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
