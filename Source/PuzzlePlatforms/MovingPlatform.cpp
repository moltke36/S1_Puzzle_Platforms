// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"

AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

	SetMobility(EComponentMobility::Movable);
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (HasAuthority())
	{
		FVector NewLoctaion = GetActorLocation();
		float DeltaX = FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime);
		NewLoctaion.X += DeltaX * 1000.f;
		RunningTime += DeltaTime;
		SetActorLocation(NewLoctaion);
	}
	
}