// Fill out your copyright notice in the Description page of Project Settings.

#include "RiderCharacter.h"
#include "Components/InputComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SceneComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ARiderCharacter::ARiderCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	SpringArmRider = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"), false);
	UCameraComponent* MyCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"), false);	
	MyCamera->SetupAttachment(SpringArmRider);
	SpringArmRider->SetRelativeLocation(GetActorLocation() + FVector(CameraPositionX, 0.0f, CameraHeight));
	SpringArmRider->SetRelativeRotation(FRotator(CameraPitch, 0.0f, 0.0f));
	
	
}

// Called when the game starts or when spawned
void ARiderCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called every frame
void ARiderCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARiderCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MoveForward", this, &ARiderCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ARiderCharacter::MoveRight);
}

void ARiderCharacter::MoveForward(float AxisValue)
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

void ARiderCharacter::MoveRight(float AxisValue)
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

