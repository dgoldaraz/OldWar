// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "AvatarMovementComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class OLDWARSGAME_API UAvatarMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:	


	UFUNCTION(BlueprintCallable, Category = Movement)
	void IntendToMoveForward(float Move);

	UFUNCTION(BlueprintCallable, Category = Movement)
	void IntendToMoveBackward(float Move);

	UFUNCTION(BlueprintCallable, Category = Movement)
	void IntendTurnRight(float Move);

	UFUNCTION(BlueprintCallable, Category = Movement)
	void IntendTurnLeft(float Move);
	

	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

	// Axis Movement (between -1 and 1)
	UFUNCTION(BlueprintCallable, Category = Movement)
	void SetLeftMovement(float Move);
	UFUNCTION(BlueprintCallable, Category = Movement)
	void SetRightMovement(float Move);

	UFUNCTION(BlueprintCallable, Category = Movement)
	void SetMovingParts(UStaticMeshComponent* LeftMovingPart, UStaticMeshComponent* RightMovingPart);

	//Max Force per part in Newtons
	UPROPERTY(VisibleAnywhere, Category = Movement)
	float MaxDrivingForce = 40000000.0f; //base on mass tank of 40 tons and 1G acceleration

	// Sets default values for this component's properties
	UAvatarMovementComponent();

private:

	UStaticMeshComponent* LeftPart;
	UStaticMeshComponent* RightPart;

	void ApplyForceToRoot(FVector ForwardVector, FVector Location, float MovementAxis);
	
};
