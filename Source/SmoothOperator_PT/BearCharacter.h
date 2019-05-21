// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyCharacterBasic.h"
#include "BearCharacter.generated.h"

class USphereComponent;
class AToddlerCharacter;
class ACrystalActor;
class UCharacterMovementComponent;

UCLASS()
class SMOOTHOPERATOR_PT_API ABearCharacter : public AMyCharacterBasic
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

	//Interaction :

	UPROPERTY(EditAnywhere, BlueprintReadWrite)	//Radius that decides what the character can interact with / what is in his reach
		USphereComponent *InteractionRadius;	

	UFUNCTION() //On begin overlap
			void Interactable(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
				UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
				bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION() //On end overlap
		void NonInteractable(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);	
	
	//Cristals :

	UPROPERTY(EditAnywhere, BlueprintReadWrite) //If we should print missing cristals to screen
		bool ShouldPrintMissingCrystals = false;

	UPROPERTY(BlueprintReadWrite) //What to print
			FString PrintMissingCrystals;

	UPROPERTY(EditAnywhere, BlueprintReadWrite) //How many cristals we currently have
		int PickedUpCrystals{ 0 };

	TArray<FString> Crystals; //An array with the collected cristals, for debugging purposes	

	UPROPERTY(EditAnywhere, BlueprintReadWrite)//The timer for the world, the bears energy, when this reaches zero the bear dies and the player lose
		float CrystalEnergyMax = 140.0f; 
	
	UPROPERTY(BlueprintReadWrite)
		bool AllCrystalsCollected{ false };

	//Controll :
	UPROPERTY(BlueprintReadWrite)
		bool BearPlaying = false;

	//Sound :

	UPROPERTY(EditAnywhere) //Sound when picking up a cristal
		USoundBase* CollectCrystalSound {
		nullptr
	};

	UPROPERTY(EditAnywhere)//Sound when mounting, currently not in use
		USoundBase* MountSound {
		nullptr
	};

	UPROPERTY(EditAnywhere) //Sound when swapping, currently not in use
		USoundBase* SwapSound {
		nullptr
	};

	UPROPERTY(EditAnywhere) //Sound when launching, currently not in use
		USoundBase* LaunchSound {
		nullptr
	};

	
	void FindToddler(); //Casts the TheToddler to array of all toddlers in the world

private:
	//Character interaction and functions :
	void Swap();	//Swap between characters
	void Launch();	//Launch toddler in the air when IsRiding == true
	void Interact(); //Interact with Characters and Objects
	
	//Communication with other actors :
	AActor *InteractableActor;
	TArray<AActor*> AllToddlers;
	AToddlerCharacter *TheToddler;	
	bool BearCanInteract = false;	
	bool FoundToddler = false;

	//Other :
	FString DebugName;
	float TimerMissingCrystals = 0.0f;
};
