// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);


}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
	{
		SetReplicates(true);
		SetReplicateMovement(true);
		OldLocation = GetActorLocation();
	}
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (HasAuthority())
	{
		FVector NewLoctaion = GetActorLocation();
		float DistanceRemain = FVector::Distance(TargetLocation + OldLocation,NewLoctaion) / FVector::Distance(TargetLocation,OldLocation) ;
		FVector DeltaVectorSpeed = FVector(FMath::Sin(2* DistanceRemain)- FMath::Sin(DistanceRemain), FMath::Sin(2 * DistanceRemain) - FMath::Sin(DistanceRemain), FMath::Sin(2 * DistanceRemain) - FMath::Sin(DistanceRemain))*TargetLocation.GetSafeNormal();
		NewLoctaion += DeltaVectorSpeed * MaxSpeed * DeltaTime;
		SetActorLocation(NewLoctaion);
	}
	
}
