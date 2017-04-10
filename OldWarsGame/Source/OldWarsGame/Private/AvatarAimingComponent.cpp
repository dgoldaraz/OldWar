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
	PrimaryComponentTick.bCanEverTick = true;
}

void UAvatarAimingComponent::AimAt(FVector Location,float Speed)
{
	//Try to get the velocity of the launch based on the speed
	//static bool SuggestProjectileVelocity(UObject* WorldContextObject, FVector& TossVelocity, FVector StartLocation, FVector EndLocation, float TossSpeed, bool bHighArc = false, float CollisionRadius = 0.f, float OverrideGravityZ = 0, ESuggestProjVelocityTraceOption::Type TraceOption = ESuggestProjVelocityTraceOption::TraceFullPath, const FCollisionResponseParams& ResponseParam = FCollisionResponseParams::DefaultResponseParam, const TArray<AActor*>& ActorsToIgnore = TArray<AActor*>(), bool bDrawDebug = false);
	if (AimingPart)
	{
		FVector OutLaunchVelocity = FVector::ZeroVector;
		//Get the socket where the projectile should be thrown
		FVector StartPosition = AimingPart->GetSocketLocation("Projectile");
		if(UGameplayStatics::SuggestProjectileVelocity(GetWorld(), OutLaunchVelocity, AimingPart->GetComponentLocation(), Location, Speed, ESuggestProjVelocityTraceOption::DoNotTrace))
		{
			FVector AimDirection = OutLaunchVelocity.GetSafeNormal();
			//Move Aiming part
			MoveAimingPart(AimDirection);
		}

	}
}

void UAvatarAimingComponent::SetAimingPart(UAvatarAimingPart* PartToSet)
{
	AimingPart = PartToSet;
}

void UAvatarAimingComponent::MoveAimingPart(FVector AimDirection)
{

	//Get difference between current aimingpart rotation and AimDirection
	
	auto AimingPartRotation = AimingPart->GetForwardVector().Rotation();
	auto AimAsRotation = AimDirection.Rotation();
	auto DeltaRotation = AimAsRotation - AimingPartRotation;
	
	AimingPart->Elevate(5); //TODO Remove Magic Number
	//UE_LOG(LogTemp, Warning, TEXT("%s Aiming At : %s from %s with speed %f"), *GetOwner()->GetName(), *Location.ToString(), *AimDirection.ToString(), Speed);
	//UE_LOG(LogTemp, Warning, TEXT("Launch Direction : %s"), *AimDirection.ToString());
}