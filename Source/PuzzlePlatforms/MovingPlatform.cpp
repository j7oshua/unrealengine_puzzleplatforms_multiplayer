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
	}

	GlobalStartLocation = GetActorLocation();
	GlobalTargetLocation = GetTransform().TransformPosition(TargetLocation);
	
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HasAuthority())
	{
		FVector ActorLocation = GetActorLocation();
		float JourneyLength = (GlobalTargetLocation - GlobalStartLocation).Size();
		float JourneyTravelled = (ActorLocation - GlobalStartLocation).Size();

		if (JourneyTravelled >= JourneyLength)
		{
			FVector Temp = GlobalTargetLocation;
			GlobalTargetLocation = GlobalStartLocation;
			GlobalStartLocation = Temp;
		}

		FVector Direction = (GlobalTargetLocation - GlobalStartLocation).GetSafeNormal();
		ActorLocation += PlatformMovingSpeed * DeltaTime * Direction;
		SetActorLocation(ActorLocation);


	}

}