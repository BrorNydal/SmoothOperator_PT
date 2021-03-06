// Fill out your copyright notice in the Description page of Project Settings.

#include "BearCharacter.h"
#include "ToddlerCharacter.h"
#include "CrystalActor.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Components/MeshComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/CapsuleComponent.h"
#include "Engine/World.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Engine/Engine.h"
#include "ButtonTrigger.h"
#include "ConstructorHelpers.h"
#include "GameFramework/Actor.h"


// Sets default values
ABearCharacter::ABearCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	InteractionRadius = CreateDefaultSubobject<USphereComponent>(TEXT("InteractionRadius"));
	InteractionRadius->SetSphereRadius(64.0f);	
	InteractionRadius->SetupAttachment(RootComponent);
	InteractionRadius->OnComponentBeginOverlap.AddDynamic(this, &ABearCharacter::Interactable);
	InteractionRadius->OnComponentEndOverlap.AddDynamic(this, &ABearCharacter::NonInteractable);	

	
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

	if (FoundToddler == false)
	{
		FindToddler();		
	}

	if (PickedUpCrystals == 4)
	{
		AllCrystalsCollected = true;
	}

	if (ShouldPrintMissingCrystals == true) //If it should print missing cristals to the screen, and how long it prints
	{
		TimerMissingCrystals += DeltaTime;
		if (TimerMissingCrystals > 2.0f)
		{
			ShouldPrintMissingCrystals = false;
			TimerMissingCrystals = 0.0f;
		}
	}

	if (CrystalEnergyMax <= 0) //When cristal energy reaches 0, you die
	{
		Dead = true;
	}	
}

// Called to bind functionality to input
void ABearCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAction("Swap", IE_Pressed, this, &ABearCharacter::Swap);
	InputComponent->BindAction("Interact", IE_Pressed, this, &ABearCharacter::Interact);
	InputComponent->BindAction("Launch", IE_Pressed, this, &ABearCharacter::Launch);
	
}


void ABearCharacter::Launch() //Find all toddlers, possess the toddler, set set toddler status, 'Launch'=='jump' in bpBearCharacter
{
	if (TheToddler->IsRiding == true && GetCharacterMovement()->IsMovingOnGround() == true)
	{		
		Controller->Possess(TheToddler); //Possess Toddler
		TheToddler->GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics); //Set 'No Collision' -> 'Normal Collision'
		TheToddler->SetActorLocation(GetActorLocation() + FVector(0.0f, 0.0f, 90.0f)); //Set Initial launch position
		TheToddler->SetActorRotation(GetActorRotation());
		TheToddler->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform); //Keep initial transform		
		TheToddler->SetActorHiddenInGame(false);
		TheToddler->IsRiding = false;	
		TheToddler->Jump(); //Call character pre-built 'jump' function
		TheToddler->Launched = true;
		TheToddler->ToddlerPlaying = true;
		BearPlaying = false;
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), LaunchSound, GetActorLocation());
	}
}




void ABearCharacter::Interactable(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	//GEngine->AddOnScreenDebugMessage(0, 1.0f, FColor::Emerald, TEXT("Hello, Bear Overlapping"));
	DisplayInteractionButton = true;

	if (OtherActor && OtherActor != this && OtherComp)
	{
		//UE_LOG(LogTemp, Warning, TEXT("BeginOverlap"));
		if (OtherActor->IsA(AToddlerCharacter::StaticClass())) //Priority 1
		{
			//UE_LOG(LogTemp, Warning, TEXT("Bear_Begin_Overlap_Toddler"));
			InteractableActor = OtherActor;
			BearCanInteract = true;
		}//Must use else if-statements after this, so bool ToddlerCanInteract works Correctly

		else if (OtherActor->IsA(ACrystalActor::StaticClass()))//Priority 2 ...
		{
			//UE_LOG(LogTemp, Warning, TEXT("Bear_Begin_Overlap_Crystal"));
			InteractableActor = OtherActor;
			BearCanInteract = true;
		}
	}
}


void ABearCharacter::NonInteractable(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	//GEngine->AddOnScreenDebugMessage(0, 1.0f, FColor::Emerald, TEXT("Bye, Bear NOT Overlapping"));
	DisplayInteractionButton = false;

	if (OtherActor && OtherActor != this && OtherComp)
	{
		//UE_LOG(LogTemp, Warning, TEXT("BeginOverlap"));
		if ((OtherActor->IsA(AToddlerCharacter::StaticClass())) && (InteractableActor->IsA(AToddlerCharacter::StaticClass())))
		{
			//UE_LOG(LogTemp, Warning, TEXT("Bear_End_Overlap_Toddler"));
			BearCanInteract = false;
			//InteractableActor->ClearActorLabel();
		}//Must use else if-statements after this, so bool ToddlerCanInteract works Correctly
		
	}
}


void ABearCharacter::Interact() 
{	
	if (GetCharacterMovement()->IsMovingOnGround() == true && BearCanInteract == true) //If Bear is on ground, and has an interactable object in range
	{
		if (InteractableActor->IsA(AToddlerCharacter::StaticClass()) && TheToddler->IsRiding==false) 
		{
			TheToddler->GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision); //Set Collision 'Normal Collision' -> 'No Collision'
			TheToddler->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepWorldTransform); //Keep Bear transform			
			TheToddler->SetActorLocation(GetMesh()->GetSocketLocation(TEXT("MountSocket")) + FVector(0.0f, 0.0f, 50.0f)); 
			TheToddler->SetActorRotation(GetMesh()->GetSocketRotation(TEXT("MountSocket")) + FRotator(-5.0f, 180.0f, 0.0f));								//PlaceOnSocket
			TheToddler->IsRiding = true;	
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), MountSound, GetActorLocation());
			BearPlaying = false;
			TheToddler->ToddlerPlaying = true;
		}

		else if (InteractableActor->IsA(ACrystalActor::StaticClass()))
		{
			InteractableActor->Destroy();
			PickedUpCrystals += 1;
			FString CrystalName = FString("Crystal" + FString::FromInt(PickedUpCrystals));
			Crystals.Add(CrystalName);
			//GEngine->AddOnScreenDebugMessage(0, 1.0f, FColor::Emerald, CrystalName);
			CrystalEnergyMax += 20;
			TheToddler->BlurScreen = true;
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), CollectCrystalSound, GetActorLocation());
			BearCanInteract = false;
		}

		else
		{
			
		}
	}	
}


void ABearCharacter::FindToddler()
{
	if (TheToddler == nullptr) //Game crashes if the player is not in controll of the character while doing this action
	{
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AToddlerCharacter::StaticClass(), AllToddlers);

		if (AllToddlers.Num() > 0)
		{
			if (AllToddlers[0])
			{
				TheToddler = Cast<AToddlerCharacter>(AllToddlers[0]);
				FoundToddler = true;
			}
		}
	}
}

void ABearCharacter::Swap() //Find all toddlers, possess toddler
{
	if ((TheToddler->IsRiding == false) && (GetMovementComponent()->IsMovingOnGround() == true))
	{
		TheToddler->BlurScreen = true;
		//GEngine->AddOnScreenDebugMessage(0, 0.5f, FColor::Blue, TEXT("Swapping . . . "));
		Controller->Possess(TheToddler);
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), SwapSound, GetActorLocation());
		BearPlaying = false;
		TheToddler->ToddlerPlaying = true;
	}
	else if (TheToddler->IsRiding == true && GetCharacterMovement()->IsMovingOnGround() == true) //When riding will throw toddler carefully off
	{
		Controller->Possess(TheToddler); //Possess Toddler
		TheToddler->GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics); //Set 'No Collision' -> 'Normal Collision'
		TheToddler->SetActorLocation(GetActorLocation() + FVector(0.0f, 0.0f, 80.0f)); //Set Initial launch position
		TheToddler->SetActorRotation(GetActorRotation());
		TheToddler->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform); //Keep initial transform		
		TheToddler->SetActorHiddenInGame(false);
		TheToddler->IsRiding = false;
		TheToddler->ToddlerPlaying = true;
		BearPlaying = false;
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), LaunchSound, GetActorLocation());
	}
}