// Fill out your copyright notice in the Description page of Project Settings.

#include "BearCharacter.h"
#include "ToddlerCharacter.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/MeshComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Engine/World.h"
#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
ABearCharacter::ABearCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	InteractionRadius = CreateDefaultSubobject<USphereComponent>(TEXT("InteractionRadius"));
	InteractionRadius->SetSphereRadius(64.0f);
	
}

// Called when the game starts or when spawned
void ABearCharacter::BeginPlay()
{
	Super::BeginPlay();	
	
}

// Called every frame
void ABearCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	

	
}

// Called to bind functionality to input
void ABearCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAction("Swap", IE_Pressed, this, &ABearCharacter::Swap);
}

void ABearCharacter::Interact() //Find all toddlers, set toddler status
{
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AToddlerCharacter::StaticClass(), AllToddlers);
	TheToddler = Cast<AToddlerCharacter>(AllToddlers[0]);	
	
	TheToddler->SetActorHiddenInGame(true);
	TheToddler->GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	IsRiding = true;
}

void ABearCharacter::Launch() //Find all toddlers, possess the toddler, set set toddler status, 'jump' in bpBearCharacter
{	
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AToddlerCharacter::StaticClass(), AllToddlers);
	TheToddler = Cast<AToddlerCharacter>(AllToddlers[0]);

	TheToddler->SetActorLocation(GetActorLocation() + FVector(0.0f, 0.0f, 30.0f));	
	TheToddler->SetActorHiddenInGame(false);	
	TheToddler->GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Controller->Possess(TheToddler);
	IsRiding = false;
}



void ABearCharacter::Swap() //Find all toddlers, possess toddler
{	
	if ((IsRiding == false) && (GetMovementComponent()->IsMovingOnGround() == true))
	{
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AToddlerCharacter::StaticClass(), AllToddlers);
		TheToddler = Cast<AToddlerCharacter>(AllToddlers[0]);
		UE_LOG(LogTemp, Warning, TEXT("Trying to Swap"));
		Controller->Possess(TheToddler);
	}
}

