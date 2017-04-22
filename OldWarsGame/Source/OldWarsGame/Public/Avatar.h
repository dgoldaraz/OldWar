// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "Avatar.generated.h"

/**
* Avatar of all the players, can be different weapon cars
*/

class UAvatarAimingComponent;
class UAvatarAimingPart;

UCLASS()
class OLDWARSGAME_API AAvatar : public APawn
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetAiminParts(UAvatarAimingPart* ElevationPart, UAvatarAimingPart* RotationPart);

	UFUNCTION(BlueprintCallable, Category = Firing)
	void Fire();

	void AimAt(FVector Location);

protected:
	UAvatarAimingComponent* AvatarAimingComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	AAvatar();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 4000.0f; //m/s
	
};
