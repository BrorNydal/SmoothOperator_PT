// Fill out your copyright notice in the Description page of Project Settings.

#include "CrystalActor.h"
#include "BearCharacter.h"
#include "Components/ActorComponent.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/World.h"
#include "Engine/Engine.h"

// Sets default values
ACrystalActor::ACrystalActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
}

// Called when the game starts or when spawned
void ACrystalActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACrystalActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

