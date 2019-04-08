// Fill out your copyright notice in the Description page of Project Settings.

#include "Door.h"
#include "components/SkeletalMeshComponent.h"
#include "ConstructorHelpers.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	DoorMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("DoorMesh"));
	DoorMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	DoorMesh->SetCollisionObjectType(ECollisionChannel::ECC_WorldStatic);
	DoorMesh->SetupAttachment(RootComponent);
	
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Open == true)
	{
		OpenDelay += DeltaTime;
		if (OpenDelay > 0.8f)
			DoorMesh->bPauseAnims = true;
	}
}

void ADoor::OpenDoor()
{
	
}

