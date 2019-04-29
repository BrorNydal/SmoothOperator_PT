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
	
	if (PickedUpCrystals == 4)
	{
		AllCrystalsCollected = true;
		GEngine->AddOnScreenDebugMessage(0, 1.0f, FColor::Emerald, TEXT("All Crystals Collected"));
	}
	if (ShouldPrintMissingCrystals == true)
	{
		TimerMissingCrystals += DeltaTime;
		if (TimerMissingCrystals > 2.0f)
		{
			ShouldPrintMissingCrystals = false;
			TimerMissingCrystals = 0.0f;
		}
	}
	if (CrystalEnergyMax <= 0)
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
	InputComponent->BindAxis("MoveForward", this, &ABearCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ABearCharacter::MoveRight);
}


void ABearCharacter::Launch() //Find all toddlers, possess the toddler, set set toddler status, 'Launch'=='jump' in bpBearCharacter
{
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AToddlerCharacter::StaticClass(), AllToddlers);
	TheToddler = Cast<AToddlerCharacter>(AllToddlers[0]);
	if (TheToddler->IsRiding == true && GetCharacterMovement()->IsMovingOnGround() == true)
	{		
		Controller->Possess(TheToddler); //Possess Toddler
		TheToddler->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform); //Keep initial transform
		TheToddler->GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics); //Set 'No Collision' -> 'Normal Collision'
		TheToddler->SetActorLocation(GetActorLocation() + FVector(0.0f, 0.0f, 30.0f)); //Set Initial launch position
		TheToddler->SetActorHiddenInGame(false);
		TheToddler->IsRiding = false;	
		TheToddler->Jump(); //Call character pre-built 'jump' function
		TheToddler->Launched = true;	
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), LaunchSound, GetActorLocation());
	}
}

void ABearCharacter::MoveForward(float AxisValue)
{	
	FVector Direction = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->GetActorForwardVector().GetUnsafeNormal2D();

	if(Dead == false)
		AddMovementInput(Direction, AxisValue);

	if (GetVelocity() != FVector::ZeroVector && Dead == false)
	{
		FRotator FacingRotation = GetVelocity().ToOrientationRotator();
		FRotator SlerpedRotation = FQuat::Slerp(
			GetActorRotation().Quaternion(),
			FacingRotation.Quaternion(),
			RotationSpeed
		).Rotator();
		SetActorRotation(SlerpedRotation);
	}
}

void ABearCharacter::MoveRight(float AxisValue)
{
	FVector Direction = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->GetActorRightVector().GetUnsafeNormal2D();

	if(Dead == false)
		AddMovementInput(Direction, AxisValue);

	if (GetVelocity() != FVector::ZeroVector && Dead == false)
	{
		FRotator FacingRotation = GetVelocity().ToOrientationRotator();
		FRotator SlerpedRotation = FQuat::Slerp(
			GetActorRotation().Quaternion(),
			FacingRotation.Quaternion(),
			RotationSpeed
		).Rotator();
		SetActorRotation(SlerpedRotation);
	}
}


void ABearCharacter::Interactable(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	//GEngine->AddOnScreenDebugMessage(0, 1.0f, FColor::Emerald, TEXT("Hello, Bear Overlapping"));

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
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AToddlerCharacter::StaticClass(), AllToddlers);
		TheToddler = Cast<AToddlerCharacter>(AllToddlers[0]);

		if (InteractableActor->IsA(AToddlerCharacter::StaticClass())) 
		{
			

			TheToddler->GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision); //Set Collision 'Normal Collision' -> 'No Collision'
			TheToddler->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepWorldTransform); //Keep Bear transform			
			TheToddler->SetActorLocation(GetMesh()->GetSocketLocation(TEXT("MountSocket")) + FVector(0.0f, 0.0f, 50.0f)); 
			TheToddler->SetActorRotation(GetMesh()->GetSocketRotation(TEXT("MountSocket")));								//PlaceOnSocket
			TheToddler->IsRiding = true;	
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), MountSound, GetActorLocation());
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


void ABearCharacter::Swap() //Find all toddlers, possess toddler
{
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AToddlerCharacter::StaticClass(), AllToddlers);
	TheToddler = Cast<AToddlerCharacter>(AllToddlers[0]);

	if ((TheToddler->IsRiding == false) && (GetMovementComponent()->IsMovingOnGround() == true))
	{
		TheToddler->BlurScreen = true;
		//GEngine->AddOnScreenDebugMessage(0, 0.5f, FColor::Blue, TEXT("Swapping . . . "));
		Controller->Possess(TheToddler);
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), SwapSound, GetActorLocation());
	}
}