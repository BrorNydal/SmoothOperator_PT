// Fill out your copyright notice in the Description page of Project Settings.

#include "ToddlerCharacter.h"
#include "BearCharacter.h"
#include "CrystalActor.h"
#include "Components/InputComponent.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/ShapeComponent.h"
#include "Engine/Engine.h"
#include "GameFramework/Character.h"
#include "Components/SkeletalMeshComponent.h"
#include "UObject/Object.h"


// Sets default values
AToddlerCharacter::AToddlerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	InteractionRadius = CreateDefaultSubobject<USphereComponent>(TEXT("InteractionRadius")); 
	InteractionRadius->SetupAttachment(RootComponent);
	InteractionRadius->SetSphereRadius(64.0f);		
	InteractionRadius->OnComponentBeginOverlap.AddDynamic(this, &AToddlerCharacter::Interactable);
	InteractionRadius->OnComponentEndOverlap.AddDynamic(this, &AToddlerCharacter::NonInteractable);
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
	
	if (Launched == true) //If Toddler has been launched
	{
		if (GetCharacterMovement()->IsMovingOnGround() == true) //Check if toddler is on ground, if he is, then he has landed
		{
			Launched = false;
		}
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABearCharacter::StaticClass(), AllBears); //Get all bears
		TheBear = Cast<ABearCharacter>(AllBears[0]);
		
		AddMovementInput(TheBear->GetActorForwardVector(), 2000.0f);
	}

}

// Called to bind functionality to input
void AToddlerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAction("Swap", IE_Pressed, this, &AToddlerCharacter::Swap);
	InputComponent->BindAction("Interact", IE_Pressed, this, &AToddlerCharacter::Interact);	
}

void AToddlerCharacter::Interactable(UPrimitiveComponent *OverlappedComp, AActor *OtherActor,
								UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, 
								bool bFromSweep, const FHitResult& SweepResult) //BeginOverlap
{	
	GEngine->AddOnScreenDebugMessage(0, 1.0f, FColor::Emerald, TEXT("Hello, Toddler Overlapping"));

	if (OtherActor && OtherActor != this && OtherComp)
	{
		//UE_LOG(LogTemp, Warning, TEXT("BeginOverlap"));
		if (OtherActor->IsA(ABearCharacter::StaticClass()))
		{
			//UE_LOG(LogTemp, Warning, TEXT("Toddler_Begin_Overlap_Bear"));
			InteractableActor = OtherActor;
			ToddlerCanInteract = true;
		}//Must use else if-statements after this, so bool ToddlerCanInteract works Correctly
		else if (OtherActor->IsA(ACrystalActor::StaticClass()))
		{
			//UE_LOG(LogTemp, Warning, TEXT("Toddler_Begin_Overlap_Crystal"));
			InteractableActor = OtherActor;
			ToddlerCanInteract = true;
		}
		
	}
}

void AToddlerCharacter::NonInteractable(UPrimitiveComponent *OverlappedComp, AActor *OtherActor,
										UPrimitiveComponent *OtherComp, int32 OtherBodyIndex) //EndOverlap
{
	GEngine->AddOnScreenDebugMessage(0, 1.0f, FColor::Emerald, TEXT("Bye, Toddler NOT Overlapping"));

	if (OtherActor && OtherActor != this && OtherComp)
	{
		//UE_LOG(LogTemp, Warning, TEXT("BeginOverlap"));
		if (OtherActor == InteractableActor)
		{
			UE_LOG(LogTemp, Warning, TEXT("Toddler_End_Overlap_InteractableActor"));
			ToddlerCanInteract = false;		
			//InteractableActor->ClearActorLabel();
		}//Must use else if-statements after this, so bool ToddlerCanInteract works Correctly		
	}
}

void AToddlerCharacter::Swap() //Get all bears, possess bear
{	
	if (GetMovementComponent()->IsMovingOnGround() == true)
	{
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABearCharacter::StaticClass(), AllBears); //Get all bears
		TheBear = Cast<ABearCharacter>(AllBears[0]);
		GEngine->AddOnScreenDebugMessage(0, 0.5f, FColor::Blue, TEXT("Swapping . . . "));
		Controller->Possess(TheBear);		
	}	
}

void AToddlerCharacter::Interact() //Trying to replicate the blueprint
{
	if (GetCharacterMovement()->IsMovingOnGround() == true && ToddlerCanInteract == true)
	{		
		if (InteractableActor->IsA(ABearCharacter::StaticClass()))
		{
			UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABearCharacter::StaticClass(), AllBears); //Get all bears
			TheBear = Cast<ABearCharacter>(AllBears[0]);

			GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
			AttachToComponent(TheBear->GetMesh(), FAttachmentTransformRules::KeepWorldTransform);
			SetActorLocation(TheBear->GetMesh()->GetSocketLocation(TEXT("MountSocket")) + FVector(0.0f, 0.0f, 50.0f));
			SetActorRotation(TheBear->GetMesh()->GetSocketRotation(TEXT("MountSocket")));			
			IsRiding = true;	
			if(Controller)
				Controller->Possess(TheBear);
		}
		else if (InteractableActor->IsA(ACrystalActor::StaticClass()))
		{	
			UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABearCharacter::StaticClass(), AllBears); //Get all bears
			TheBear = Cast<ABearCharacter>(AllBears[0]);

			InteractableActor->Destroy();
			TheBear->PickedUpCrystals += 1;
			FString CrystalName = FString("Crystal" + FString::FromInt(TheBear->PickedUpCrystals));
			TheBear->Crystals.Add(CrystalName);
			GEngine->AddOnScreenDebugMessage(0, 1.0f, FColor::Emerald, CrystalName);
		}
		
	}
}


