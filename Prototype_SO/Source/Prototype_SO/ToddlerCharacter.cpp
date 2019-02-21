// Fill out your copyright notice in the Description page of Project Settings.

#include "ToddlerCharacter.h"
#include "BearCharacter.h"
#include "Components/InputComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SceneComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AToddlerCharacter::AToddlerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmToddler = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"), false);
	UCameraComponent* MyCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"), true);
	MyCamera->AttachToComponent(SpringArmToddler, FAttachmentTransformRules::KeepRelativeTransform);
	SpringArmToddler->SetRelativeLocation(FVector(CameraPositionX, 0.0f, CameraHeight));
	SpringArmToddler->SetRelativeRotation(FRotator(CameraPitch, 0.0f, 0.0f));

	RadiusCollider = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollider"));	
	RadiusCollider->SetSphereRadius(SphereRadius);
	//RadiusCollider->SetGenerateOverlapEvents(true);
	//Cast<UShapeComponent>(RadiusCollider)->OnComponentBeginOverlap.AddDynamic(this, &AToddlerCharacter::InteractTrue);
	//Cast<UShapeComponent>(RadiusCollider)->OnComponentEndOverlap.AddDynamic(this, &AToddlerCharacter::InteractFalse);

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

	InputComponent->BindAxis("MoveForward", this, &AToddlerCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AToddlerCharacter::MoveRight);
}

void AToddlerCharacter::MoveForward(float AxisValue)
{
	if ((Controller != NULL) && (AxisValue != 0.0f))
	{
		// find out which way is forward
		FRotator Rotation = Controller->GetControlRotation();
		// Limit pitch when walking or falling
		if (GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling())
		{
			Rotation.Pitch = 0.0f;
		}
		// add movement in that direction
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
		AddMovementInput(Direction, AxisValue);
	}
}

void AToddlerCharacter::MoveRight(float AxisValue)
{
	if ((Controller != NULL) && (AxisValue != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, AxisValue);
	}
}

void AToddlerCharacter::InteractTrue(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
									 UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex,
									 bool bFromSweep, const FHitResult &SweepResult)
{
	
}

void AToddlerCharacter::InteractFalse(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	
}
