// Fill out your copyright notice in the Description page of Project Settings.

#include "MenuManager.h"
#include "StartButtonSprite.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"
#include "ConstructorHelpers.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"

// Sets default values
AMenuManager::AMenuManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UClass> bpItem(TEXT("Blueprint'/Game/Blueprints/bpStartButtonSprite.bpStartButtonSprite_C'"));

	if (bpItem.Object)
	{
		bpStartButton = bpItem.Object;
	}
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
	if (bpStartButton)
	{
		FActorSpawnParameters SpawnInfo;
		AStartButtonSprite *StartButton =
			GetWorld()->SpawnActor<AStartButtonSprite>(bpStartButton, FVector(-1385.0f, 155.0f, 5.0f), FRotator(0.0f, 90.0f, 0.0f), SpawnInfo);
		StartButton;
		StartButton->RegisterMouseClick();
	}
}

// Called every frame
void AMenuManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

