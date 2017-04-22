// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "AvatarAimingComponent.generated.h"

class UAvatarAimingPart;

/*
* Actor Component that deals with the Aiming
*/

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class OLDWARSGAME_API UAvatarAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	


	void AimAt(FVector Location, float Speed);

	void SetElevationAimingPart(UAvatarAimingPart* PartToSet);
	void SetRotationAimingPart(UAvatarAimingPart* PartToSet);

	// Sets default values for this component's properties
	UAvatarAimingComponent();

private:

	//Make a separation because we can have different parts that aim (like a tank)
	//TODO: Refactor code to not use AvatarAimingPart and do the work on the aiming component
	UAvatarAimingPart* ElevationAimingPart = nullptr;
	UAvatarAimingPart* RotateAimingPart = nullptr;

	void MoveAimingPart(FVector AimDirection);
	
	void CalculateElevation(FVector AimDirection);
	void CalculateRotation(FVector AimDirection);
};
