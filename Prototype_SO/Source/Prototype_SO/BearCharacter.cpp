// Fill out your copyright notice in the Description page of Project Settings.

#include "BearCharacter.h"
#include "ToddlerCharacter.h"
#include "Components/InputComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SceneComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/SphereComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ABearCharacter::ABearCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//SpringArm
	SpringArmBear = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"), false);
	UCameraComponent* MyCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"), true);	
	MyCamera->AttachToComponent(SpringArmBear, FAttachmentTransformRules::KeepRelativeTransform);
	SpringArmBear->SetRelativeLocation(FVector(CameraPositionX, 0.0f, CameraHeight));
	SpringArmBear->SetRelativeRotation(FRotator(CameraPitch, 0.0f, 0.0f));	

	//Collider
	RadiusCollider = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollider"));
	RadiusCollider->SetSphereRadius(SphereRadius);
	//RadiusCollider->SetGenerateOverlapEvents(true);
	//Cast<UShapeComponent>(RadiusCollider)->OnComponentBeginOverlap.AddDynamic(this, &ABearCharacter::InteractTrue);
	//Cast<UShapeComponent>(RadiusCollider)->OnComponentEndOverlap.AddDynamic(this, &ABearCharacter::InteractFalse);
	
	
}

// Called when the game starts or when spawned
void ABearCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AToddlerCharacter::StaticClass(), Toddlers);
	TheToddler = Cast<AToddlerCharacter>(Toddlers[0]);
	
}

// Called every frame
void ABearCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//UE_LOG(LogTemp, Warning, TEXT("Collision : %d"), CanRide);
	
	if (TheToddler)
	{
		CanBearRide = RadiusCollider->IsOverlappingActor(TheToddler);
		UE_LOG(LogTemp, Warning, TEXT("OverlappingTod : %d"), CanBearRide);
	}
}

// Called to bind functionality to input
void ABearCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAxis("MoveForward", this, &ABearCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ABearCharacter::MoveRight);
}

void ABearCharacter::MoveForward(float AxisValue)
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

void ABearCharacter::MoveRight(float AxisValue)
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

void ABearCharacter::InteractTrue(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
								  UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex,
								  bool bFromSweep, const FHitResult &SweepResult)
{	
	
}

void ABearCharacter::InteractFalse(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	
}

