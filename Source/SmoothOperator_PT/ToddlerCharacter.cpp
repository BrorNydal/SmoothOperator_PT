// Fill out your copyright notice in the Description page of Project Settings.

#include "ToddlerCharacter.h"
#include "ButtonTrigger.h"
#include "DoorTriggerVolume.h"
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
#include "Kismet/KismetMathLibrary.h"
#include "UObject/ConstructorHelpers.h"
#include "Math/Vector.h"


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
	
	IsMovingOnGround = GetCharacterMovement()->IsMovingOnGround();
	IsCrawling = GetCharacterMovement()->bWantsToCrouch;	

	if (IsMovingOnGround == true)
	{		
		SetActorRotation(FRotator(0.0f, GetActorRotation().Yaw, 0.0f)); //Bug-Fix for character walking in unnatural angle	
	}
	else
	{
		Timer += DeltaTime;

		
		FRotator AirRotationLookAt = UKismetMathLibrary::FindLookAtRotation(
			GetActorLocation(),
			GetVelocity() + GetActorLocation()
		);
		FRotator AirRotation = FQuat::Slerp(
			GetActorRotation().Quaternion(),
			AirRotationLookAt.Quaternion(),
			0.08f
		).Rotator();
		SetActorRotation(AirRotation);
					
	}

	if (BlurScreen == true)
	{
		BlurTimer += DeltaTime;
		if (BlurTimer >= 1.0f)
		{
			BlurScreen = false;
			BlurTimer = 0.0f;
		}
	}

	if (Launched == true) //If Toddler has been launched
	{
		if (IsMovingOnGround == true) //Check if toddler has landed
		{
			Launched = false;
		}		
		AddMovementInput(TheBear->GetActorForwardVector(), 3000.0f);
	}	
}

// Called to bind functionality to input
void AToddlerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAction("Swap", IE_Pressed, this, &AToddlerCharacter::Swap);
	InputComponent->BindAction("Interact", IE_Pressed, this, &AToddlerCharacter::Interact);	
	InputComponent->BindAction("Crawl", IE_Pressed, this, &AToddlerCharacter::Crawl);
	InputComponent->BindAxis("MoveForward", this, &AToddlerCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AToddlerCharacter::MoveRight);
}

void AToddlerCharacter::MoveForward(float AxisValue)
{
	AddMovementInput(FVector(1.0f, 0.0f, 0.0f), AxisValue);	

	if (GetVelocity() != FVector::ZeroVector && IsMovingOnGround == true)
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

void AToddlerCharacter::MoveRight(float AxisValue)
{
	AddMovementInput(FVector(0.0f, 1.0f, 0.0f), AxisValue);

	if (GetVelocity() != FVector::ZeroVector && IsMovingOnGround == true)
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
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABearCharacter::StaticClass(), AllActorsOfClass); //Get all bears
		TheBear = Cast<ABearCharacter>(AllActorsOfClass[0]);
		GEngine->AddOnScreenDebugMessage(0, 0.5f, FColor::Blue, TEXT("Swapping . . . "));		
		BlurScreen = true;
		Controller->Possess(TheBear);	
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), SwapSound, GetActorLocation());
	}	
}

void AToddlerCharacter::Interact() //Trying to replicate the blueprint
{
	if (IsMovingOnGround == true && ToddlerCanInteract == true)
	{		
		if (InteractableActor->IsA(ABearCharacter::StaticClass()))
		{
			UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABearCharacter::StaticClass(), AllActorsOfClass); //Get all bears
			TheBear = Cast<ABearCharacter>(AllActorsOfClass[0]);

			GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
			AttachToComponent(TheBear->GetMesh(), FAttachmentTransformRules::KeepWorldTransform);
			SetActorLocation(TheBear->GetMesh()->GetSocketLocation(TEXT("MountSocket")) + FVector(0.0f, 0.0f, 50.0f));
			SetActorRotation(TheBear->GetMesh()->GetSocketRotation(TEXT("MountSocket")));			
			IsRiding = true;	
			if(Controller)
				Controller->Possess(TheBear);

			UGameplayStatics::PlaySoundAtLocation(GetWorld(), MountSound, GetActorLocation());
		}
		else if (InteractableActor->IsA(ACrystalActor::StaticClass()))
		{	
			UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABearCharacter::StaticClass(), AllActorsOfClass); //Get all bears
			TheBear = Cast<ABearCharacter>(AllActorsOfClass[0]);	
			
			InteractableActor->Destroy();
			TheBear->PickedUpCrystals += 1;
			FString CrystalName = FString("Crystal" + FString::FromInt(TheBear->PickedUpCrystals)); //Create a Crystal name, for array
			TheBear->Crystals.Add(CrystalName);
			TheBear->CrystalEnergyMax += 20;
			BlurScreen = true;
			UGameplayStatics::PlaySoundAtLocation(GetWorld(), CollectCrystalSound, GetActorLocation());
			ToddlerCanInteract = false;
		}
	}
}

void AToddlerCharacter::Crawl()
{
	if (IsMovingOnGround == true && IsCrawling == false)
	{
		GetCharacterMovement()->bWantsToCrouch = true;
	}
	else if (IsMovingOnGround == true && IsCrawling == true)
	{
		GetCharacterMovement()->bWantsToCrouch = false;
	}
}


