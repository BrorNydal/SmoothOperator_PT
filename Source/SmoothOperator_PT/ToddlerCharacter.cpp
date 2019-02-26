// Fill out your copyright notice in the Description page of Project Settings.

#include "ToddlerCharacter.h"
#include "BearCharacter.h"
#include "Components/InputComponent.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"

// Sets default values
AToddlerCharacter::AToddlerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	InteractionRadius = CreateDefaultSubobject<USphereComponent>(TEXT("InteractionRadius"));
	InteractionRadius->SetSphereRadius(64.0f);
}

// Called when the game starts or when spawned
void AToddlerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AToddlerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

// Called to bind functionality to input
void AToddlerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAction("Swap", IE_Pressed, this, &AToddlerCharacter::Swap);
}

void AToddlerCharacter::Interact()
{
	
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABearCharacter::StaticClass(), AllBears);
		TheBear = Cast<ABearCharacter>(AllBears[0]);

		SetActorHiddenInGame(true);
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		TheBear->IsRiding = true;
		Controller->Possess(TheBear);
	
}

void AToddlerCharacter::Swap()
{
	//Does Not Possess
	if (GetMovementComponent()->IsMovingOnGround() == true)
	{
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABearCharacter::StaticClass(), AllBears);
		TheBear = Cast<ABearCharacter>(AllBears[0]);
		UE_LOG(LogTemp, Warning, TEXT("Trying to Swap"));
		Controller->Possess(TheBear);
	}
	
}


