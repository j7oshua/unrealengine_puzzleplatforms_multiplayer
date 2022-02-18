// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzlePlatformsGameInstance.h"

UPuzzlePlatformsGameInstance::UPuzzlePlatformsGameInstance(const FObjectInitializer& ObjectInitializer)
{
	UE_LOG(LogTemp, Warning, TEXT("Hello from the Constructor!"));
}

void UPuzzlePlatformsGameInstance::Init()
{
	UE_LOG(LogTemp, Warning, TEXT("Hello from Init!"));
}

void UPuzzlePlatformsGameInstance::Host()
{
	if (!ensure(GEngine != nullptr)) return;
	GEngine->AddOnScreenDebugMessage(0, 2.f, FColor::Green, TEXT("Hosting!"));
}

void UPuzzlePlatformsGameInstance::Join(const FString& IpAddress)
{
	if (!ensure(GEngine != nullptr)) return;
	GEngine->AddOnScreenDebugMessage(0, 2.f, FColor::Green, FString::Printf(TEXT("The IP address is %s"), *IpAddress));
}