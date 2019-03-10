// Fill out your copyright notice in the Description page of Project Settings.

#include "MenuManager.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"
#include "GameFramework/PlayerController.h"

// Sets default values
AMenuManager::AMenuManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMenuManager::BeginPlay()
{
	Super::BeginPlay();
	
	APlayerController *PC = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (PC)
	{
		PC->bShowMouseCursor = true;
		PC->bEnableClickEvents = true;
		PC->bEnableMouseOverEvents = true;
	}
}

// Called every frame
void AMenuManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

