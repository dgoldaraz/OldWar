// Fill out your copyright notice in the Description page of Project Settings.

#include "OldWarsGame.h"
#include "Public/Avatar.h"
#include "Public/AvatarAimingPart.h"

// Sets default values
AAvatar::AAvatar()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//No need to protect pointers as added at constructor
	AvatarAimingComponent = CreateDefaultSubobject<UAvatarAimingComponent>(FName("AimComponent"));
}

// Called when the game starts or when spawned
void AAvatar::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAvatar::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

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


void AAvatar::SetAimingPart(UAvatarAimingPart* PartToSet)
{
	AvatarAimingComponent->SetAimingPart(PartToSet);
}
