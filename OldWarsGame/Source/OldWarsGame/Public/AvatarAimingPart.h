// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "AvatarAimingPart.generated.h"

/**
 * Hold properties for the AimingPart 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class OLDWARSGAME_API UAvatarAimingPart : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	//TODO Move to AimingComponent

	// -1 is max downward speed, +1 is max up speed
	void Elevate(float RelativeSpeed);
	// -1 is max downward speed, +1 is max up speed
	void Rotate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category = Aiming)
	float MaxElevationDegreesPerSecond = 10.0f;

	UPROPERTY(EditAnywhere, Category = Aiming)
	float MaxRotateDegreesPerSecond = 25.0f;

	UPROPERTY(EditAnywhere, Category = Aiming)
	float MaxElevationDegree = 30.0f;

	UPROPERTY(EditAnywhere, Category = Aiming)
	float MinElevationDegree = 0.0f;
};
