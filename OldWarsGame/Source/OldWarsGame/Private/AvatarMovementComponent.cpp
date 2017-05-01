// Fill out your copyright notice in the Description page of Project Settings.

#include "OldWarsGame.h"
#include "Public/AvatarMovementComponent.h"


// Sets default values for this component's properties
UAvatarMovementComponent::UAvatarMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
}

void UAvatarMovementComponent::SetMovingParts(UStaticMeshComponent* LeftMovingPart, UStaticMeshComponent* RightMovingPart)
{
	LeftPart = LeftMovingPart;
	RightPart = RightMovingPart;
}

void UAvatarMovementComponent::SetLeftMovement(float Move)
{
	ApplyForceToRoot(LeftPart->GetForwardVector(),LeftPart->GetComponentLocation(), Move);
}

void UAvatarMovementComponent::SetRightMovement(float Move)
{
	ApplyForceToRoot(RightPart->GetForwardVector(), RightPart->GetComponentLocation(), Move);
}

void UAvatarMovementComponent::ApplyForceToRoot(FVector ForwardVector,FVector Location, float MovementAxis)
{
	if (FMath::Abs(MovementAxis) > 0.0f)
	{
		auto ForceApplied = ForwardVector * MovementAxis * MaxDrivingForce;
		auto AvatarRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
		AvatarRoot->AddForceAtLocation(ForceApplied, Location);
	}
}

void UAvatarMovementComponent::IntendToMoveForward(float Move)
{
	ApplyForceToRoot(LeftPart->GetForwardVector(), LeftPart->GetComponentLocation(), Move);
	ApplyForceToRoot(RightPart->GetForwardVector(), RightPart->GetComponentLocation(), Move);
}

void UAvatarMovementComponent::IntendToMoveBackward(float Move)
{
	ApplyForceToRoot(LeftPart->GetForwardVector(), LeftPart->GetComponentLocation(), Move);
	ApplyForceToRoot(RightPart->GetForwardVector(), RightPart->GetComponentLocation(), Move);
}

void UAvatarMovementComponent::IntendTurnRight(float Move)
{
	ApplyForceToRoot(LeftPart->GetForwardVector(), LeftPart->GetComponentLocation(), Move);
	ApplyForceToRoot(RightPart->GetForwardVector(), RightPart->GetComponentLocation(), -Move);
}

void UAvatarMovementComponent::IntendTurnLeft(float Move)
{
	ApplyForceToRoot(LeftPart->GetForwardVector(), LeftPart->GetComponentLocation(), -Move);
	ApplyForceToRoot(RightPart->GetForwardVector(), RightPart->GetComponentLocation(), Move);
}

void UAvatarMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	auto AvatarForward = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto MoveForwardIntention = MoveVelocity.GetSafeNormal();
	auto FwdIntention = FVector::DotProduct(AvatarForward, MoveForwardIntention);
	auto IntendRotationVector = FVector::CrossProduct(MoveForwardIntention, AvatarForward);

	IntendTurnRight(IntendRotationVector.Z);
	IntendToMoveForward(FwdIntention);

	UE_LOG(LogTemp, Warning, TEXT(" %s -> Forward : %f, Right : %f"), *GetOwner()->GetName(), FwdIntention, IntendRotationVector.Z);
}