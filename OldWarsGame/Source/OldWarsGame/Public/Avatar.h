// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "AvatarAimingComponent.h"
#include "Avatar.generated.h"

/**
* Avatar of all the players, can be different weapon cars
*/

class UAvatarAimingPart;

UCLASS()
class OLDWARSGAME_API AAvatar : public APawn
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetAimingPart(UAvatarAimingPart* PartToSet);

	void AimAt(FVector Location);

protected:
	UAvatarAimingComponent* AvatarAimingComponent = nullptr;

private:
	// Sets default values for this pawn's properties
	AAvatar();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	// TODO : Find sensible Launch speed
	UPROPERTY(EditAnywhere, Category = Firing)
	float LaunchSpeed = 100000.0f; //m/s
	
};
