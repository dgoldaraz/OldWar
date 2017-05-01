// Fill out your copyright notice in the Description page of Project Settings.

#include "OldWarsGame.h"
#include "Public/Avatar.h"
#include "Public/AvatarAimingComponent.h"
#include "Public/Projectile.h"
#include "Public/AvatarMovementComponent.h"
#include "Public/AvatarAimingPart.h"


// Sets default values
AAvatar::AAvatar()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//No need to protect pointers as added at constructor
	AvatarAimingComponent = CreateDefaultSubobject<UAvatarAimingComponent>(FName("AimComponent"));
}

// Called to bind functionality to input
void AAvatar::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

void AAvatar::AimAt(FVector Location)
{
	AvatarAimingComponent->AimAt(Location, LaunchSpeed);
}


void AAvatar::SetAiminParts(UAvatarAimingPart* ElevationPart, UAvatarAimingPart* RotationPart)
{
	AvatarAimingComponent->SetElevationAimingPart(ElevationPart);
	ShootingPart = ElevationPart;
	AvatarAimingComponent->SetRotationAimingPart(RotationPart);
}

void AAvatar::Fire()
{

	bool IsReloaded = (FPlatformTime::Seconds() - LastTimeFire) > ReloadTimeInSeconds;
	if (ShootingPart && IsReloaded)
	{
		LastTimeFire = FPlatformTime::Seconds();
		//Spawn a projectile on the socket position of the shooting part
		AProjectile* CurrentProjectile = GetWorld()->SpawnActor<AProjectile>(ProjectileBlueprint, ShootingPart->GetSocketLocation("Projectile"), ShootingPart->GetSocketRotation("Projectile"));
		CurrentProjectile->LaunchProjectile(LaunchSpeed);
	}
}