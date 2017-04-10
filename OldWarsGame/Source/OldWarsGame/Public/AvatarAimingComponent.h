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

	void SetAimingPart(UAvatarAimingPart* PartToSet);

	//TODO Add Set MovingPart

	// Sets default values for this component's properties
	UAvatarAimingComponent();

private:
	UAvatarAimingPart* AimingPart = nullptr;

	void MoveAimingPart(FVector AimDirection);
	
};
