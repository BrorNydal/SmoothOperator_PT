// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacterBasic.generated.h"

UCLASS()
class SMOOTHOPERATOR_PT_API AMyCharacterBasic : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacterBasic();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(BlueprintReadWrite)
		bool Dead = false;

	bool IsMovingOnGround;

	UPROPERTY(BlueprintReadWrite)
		bool DisplayInteractionButton = false;

private:
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);	
	float RotationSpeed = 0.1f;
};
