// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "AvatarAimingPart.generated.h"

/**
 * Hold properties for the AimingPart 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class OLDWARSGAME_API UAvatarAimingPart : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:

	void Elevate(float DegreesPerSecond);

private:
	UPROPERTY(EditAnywhere, Category = Aiming)
	float MaxDegreesPerSecond = 20.0f;

	UPROPERTY(EditAnywhere, Category = Aiming)
	float MaxElevationDegree = 30.0f;

	UPROPERTY(EditAnywhere, Category = Aiming)
	float MinElevationDegree = 0.0f;
};
