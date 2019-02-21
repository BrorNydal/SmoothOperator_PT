// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BearCharacter.generated.h"

class USpringArmComponent;
class USphereComponent;
class AToddlerCharacter;

UCLASS()
class PROTOTYPE_SO_API ABearCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABearCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
		void MoveForward(float AxisValue);

	UFUNCTION()
		void MoveRight(float AxisValue);

	UPROPERTY(EditAnywhere, Category = "Camera")
		float CameraHeight{ 550.0f };

	UPROPERTY(EditAnywhere, Category = "Camera")
		float CameraPositionX{ -120.0f };

	UPROPERTY(EditAnywhere, Category = "Camera")
		float CameraPitch{ -75.0f };

	USpringArmComponent* SpringArmBear;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool CanBearRide{ false }; //Set to true deafault to debug

	UPROPERTY(EditAnywhere)
		USphereComponent* RadiusCollider;

	UPROPERTY(EditAnywhere)
		float SphereRadius{ 64.0f };

	TArray<AActor*> Toddlers;
	
	AToddlerCharacter *TheToddler;

private:
	UFUNCTION()
		void InteractTrue(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
						  UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex,
						  bool bFromSweep, const FHitResult &SweepResult);
	UFUNCTION()
		void InteractFalse(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
						   UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	
};
