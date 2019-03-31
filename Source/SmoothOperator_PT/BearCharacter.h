// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BearCharacter.generated.h"

class USphereComponent;
class AToddlerCharacter;
class ACrystalActor;
class UCharacterMovementComponent;

UCLASS()
class SMOOTHOPERATOR_PT_API ABearCharacter : public ACharacter
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USphereComponent *InteractionRadius;	

	UPROPERTY(EditAnywhere, BlueprintReadWrite) //For future use when adding animation for turning, this be the bool to decide which turn animation to apply (left/right)
		bool ShouldPrintMissingCrystals = false;		

	UFUNCTION()
		void Interactable(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
			bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void NonInteractable(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);	

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int PickedUpCrystals{ 0 };

	UPROPERTY(BlueprintReadWrite)
		FString PrintMissingCrystals;

	TArray<FString> Crystals;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float CrystalEnergyMax = 100.0f;

	//Sound :

	UPROPERTY(EditAnywhere)
		USoundBase* CollectCrystalSound {
		nullptr
	};

	UPROPERTY(EditAnywhere)
		USoundBase* MountSound {
		nullptr
	};

	UPROPERTY(EditAnywhere)
		USoundBase* SwapSound {
		nullptr
	};

	UPROPERTY(EditAnywhere)
		USoundBase* LaunchSound {
		nullptr
	};

private:

	float RotationSpeed = 0.1f;
	void Swap();	//Swap between characters
	void Interact(); //Interact with Characters and Objects
	bool BearCanInteract = false;	
	void Launch();	//Launch toddler in the air when IsRiding == true
	AActor *InteractableActor;
	TArray<AActor*> AllToddlers;
	AToddlerCharacter *TheToddler;
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);	
	bool AllCrystalsCollected{ false };
	FString DebugName;
	float TimerMissingCrystals = 0.0f;
};
