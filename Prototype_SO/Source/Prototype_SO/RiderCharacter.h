// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "RiderCharacter.generated.h"

class USpringArmComponent;

UCLASS()
class PROTOTYPE_SO_API ARiderCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARiderCharacter();

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

	USpringArmComponent* SpringArmRider;

private:
	void SetCollision();
};
