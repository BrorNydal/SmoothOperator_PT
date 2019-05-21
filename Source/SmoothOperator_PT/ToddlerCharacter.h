// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyCharacterBasic.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/Classes/Animation/AnimSequence.h"
#include "ToddlerCharacter.generated.h"

class USphereComponent;
class ABearCharacter;
class ACrystalActor;

UCLASS()
class SMOOTHOPERATOR_PT_API AToddlerCharacter : public AMyCharacterBasic
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AToddlerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)//Radius that decides what the character can interact with / what is in his reach
		USphereComponent *InteractionRadius; 		

	bool Launched = false; //Has Toddler been launched and is he still in air after being launched

	UPROPERTY(BlueprintReadWrite)//Is toddler riding bear	
		bool IsRiding = false; 	

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool BlurScreen = false;

	UPROPERTY(BlueprintReadWrite) //If the player is in controll of the toddler
		bool ToddlerPlaying = true;

	UPROPERTY(BlueprintReadWrite)
		bool Walking = false;

	UFUNCTION() //On begin overlap
		void Interactable(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
						UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, 
						bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION() //On end overlap
		void NonInteractable(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
							UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	//Sound :

	UPROPERTY(EditAnywhere) //Sound when picking up a cristal
		USoundBase* CollectCrystalSound {
		nullptr
	};

	UPROPERTY(EditAnywhere) //Sound when mounting, currently not in use
		USoundBase* MountSound {
		nullptr
	};

	UPROPERTY(EditAnywhere) //Sound when swapping, currently not in use
		USoundBase* SwapSound {
		nullptr
	};

	

private:
	//Character Interaction and functions
	void Swap();					//Swapping characters		
	bool ToddlerCanInteract = false; // Bool that decides if the character can interact
	void Interact();		

	//Some code that has not been utilized in our game
	bool IsCrawling = false;
	void Crawl(); //Crouch

	//Communication with actors
	AActor *InteractableActor; //An actor pointer that holds the actor we can intract with, if there is any
	TArray<AActor*> AllBears; //An array of all bears in the world, we can use this to find the specific bear in this case only because its just one of it
	ABearCharacter *TheBear; //We cast this into the array of bears above to get the bear
	bool FoundBear = false; //If we have found the bear / if we have cast our variable TheBear into the array and fetched the bear
	
	//Other Variables
	float Accuracy = 1.0f; //For Velocity comparisons
	float BlurTimer = 0.0f; //When we pick up a crystal, how long it will blur our screen
	
};
