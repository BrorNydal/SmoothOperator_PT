// Fill out your copyright notice in the Description page of Project Settings.

#include "MyCharacterBasic.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"
#include "Engine/World.h"

// Sets default values
AMyCharacterBasic::AMyCharacterBasic()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCharacterBasic::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacterBasic::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	IsMovingOnGround = GetCharacterMovement()->IsMovingOnGround();
}

// Called to bind functionality to input
void AMyCharacterBasic::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MoveForward", this, &AMyCharacterBasic::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMyCharacterBasic::MoveRight);
}

void AMyCharacterBasic::MoveForward(float AxisValue)
{
	FVector Direction = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->GetActorForwardVector().GetUnsafeNormal2D();

	if (Dead == false)
		AddMovementInput(Direction, AxisValue);

	if (GetVelocity() != FVector::ZeroVector && IsMovingOnGround == true && Dead == false)
	{
		FRotator FacingRotation = GetVelocity().ToOrientationRotator();
		FRotator SlerpedRotation = FQuat::Slerp(
			GetActorRotation().Quaternion(),
			FacingRotation.Quaternion(),
			RotationSpeed
		).Rotator();
		SetActorRotation(SlerpedRotation);
	} //Slerp rotation
}

void AMyCharacterBasic::MoveRight(float AxisValue)
{
	FVector Direction = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->GetActorRightVector().GetUnsafeNormal2D();

	if (Dead == false)
		AddMovementInput(Direction, AxisValue);

	if (GetVelocity() != FVector::ZeroVector && IsMovingOnGround == true && Dead == false)
	{
		FRotator FacingRotation = GetVelocity().ToOrientationRotator();
		FRotator SlerpedRotation = FQuat::Slerp(
			GetActorRotation().Quaternion(),
			FacingRotation.Quaternion(),
			RotationSpeed
		).Rotator();
		SetActorRotation(SlerpedRotation);
	} //Slerp rotation
}

