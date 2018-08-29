// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/StaticMeshActor.h"
#include "Runtime/Engine/Classes/GameFramework/Actor.h"
#include "MovingPlatform.generated.h"


/**
 * 
 */
UCLASS()
class PUZZLEPLATFORMS_API AMovingPlatform : public AStaticMeshActor
{
	GENERATED_BODY()

public:
	AMovingPlatform();

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Meta = (MakeEditWidget = true))
	FVector TargetLocation;

private:

	UPROPERTY(EditAnywhere)
	float MaxSpeed = 200;



	FVector OldLocation;

	FVector Distance;

};
