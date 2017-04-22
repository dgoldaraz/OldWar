// Fill out your copyright notice in the Description page of Project Settings.

#include "OldWarsGame.h"
#include "Kismet/GameplayStatics.h"
#include "Public/AvatarAimingComponent.h"
#include "Public/AvatarAimingPart.h"

// Sets default values for this component's properties
UAvatarAimingComponent::UAvatarAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = false;
}

void UAvatarAimingComponent::AimAt(FVector Location,float Speed)
{
	//Try to get the velocity of the launch based on the speed
	//static bool SuggestProjectileVelocity(UObject* WorldContextObject, FVector& TossVelocity, FVector StartLocation, FVector EndLocation, float TossSpeed, bool bHighArc = false, float CollisionRadius = 0.f, float OverrideGravityZ = 0, ESuggestProjVelocityTraceOption::Type TraceOption = ESuggestProjVelocityTraceOption::TraceFullPath, const FCollisionResponseParams& ResponseParam = FCollisionResponseParams::DefaultResponseParam, const TArray<AActor*>& ActorsToIgnore = TArray<AActor*>(), bool bDrawDebug = false);
	if (ElevationAimingPart && RotateAimingPart)
	{
		FVector OutLaunchVelocity = FVector::ZeroVector;
		//Get the socket where the projectile should be thrown
		FVector StartPosition = ElevationAimingPart->GetSocketLocation("Projectile");
		if(UGameplayStatics::SuggestProjectileVelocity(GetWorld(), OutLaunchVelocity, ElevationAimingPart->GetComponentLocation(), Location, Speed, false, 0, 0, ESuggestProjVelocityTraceOption::DoNotTrace))
		{
			FVector AimDirection = OutLaunchVelocity.GetSafeNormal();
			//Move Aiming part
			MoveAimingPart(AimDirection);
		}
		else
		{
			auto Time = GetWorld()->GetTimeSeconds();
			UE_LOG(LogTemp, Warning, TEXT("%f No Solution"), Time);
		}

	}
}

void UAvatarAimingComponent::SetElevationAimingPart(UAvatarAimingPart* PartToSet)
{
	ElevationAimingPart = PartToSet;
}

void UAvatarAimingComponent::SetRotationAimingPart(UAvatarAimingPart* PartToSet)
{
	RotateAimingPart = PartToSet;
}

void UAvatarAimingComponent::MoveAimingPart(FVector AimDirection)
{

	//Get difference between current aimingpart rotation and AimDirection
	CalculateElevation(AimDirection);
	CalculateRotation(AimDirection);
}

void UAvatarAimingComponent::CalculateElevation(FVector AimDirection)
{
	auto AimingPartRotation = ElevationAimingPart->GetForwardVector().Rotation();
	auto AimAsRotation = AimDirection.Rotation();
	auto DeltaRotation = AimAsRotation - AimingPartRotation;

	ElevationAimingPart->Elevate(DeltaRotation.Pitch);
}

void UAvatarAimingComponent::CalculateRotation(FVector AimDirection)
{
	auto AimingPartRotation = RotateAimingPart->GetForwardVector().Rotation();
	auto AimAsRotation = AimDirection.Rotation();
	auto DeltaRotation = AimAsRotation - AimingPartRotation;

	RotateAimingPart->Rotate(DeltaRotation.Yaw);
}
