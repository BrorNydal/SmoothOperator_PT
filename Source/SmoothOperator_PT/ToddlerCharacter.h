// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/Classes/Animation/AnimSequence.h"
#include "ToddlerCharacter.generated.h"

class USphereComponent;
class ABearCharacter;
class ACrystalActor;

UCLASS()
class SMOOTHOPERATOR_PT_API AToddlerCharacter : public ACharacter
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
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		USphereComponent *InteractionRadius; //Radius that will in the future decide what the character can interact with		

	bool Launched = false; //Has Toddler been launched

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsRiding = false; //Is toddler riding bear		

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool BlurScreen = false; 

	

	UFUNCTION()
		void Interactable(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
						UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, 
						bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void NonInteractable(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
							UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

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

	

private:
	//Character Interaction and functions
	void Swap();		//Swapping characters function		
	bool ToddlerCanInteract = false; // Bool that will decide if the character can interact
	void Interact();		

	//Movement
	void MoveForward(float AxisValue);
	void MoveRight(float AxisValue);	
	
	bool IsMovingOnGround;
	bool IsCrawling = false;
	void Crawl();

	//Communication with actors
	AActor *InteractableActor;
	TArray<AActor*> AllActorsOfClass;
	ABearCharacter *TheBear;
	ACrystalActor *Crystal;
	
	//Other Variables
	float Accuracy = 1.0f; //For Velocity comparisons
	float Timer = 0.0f;
	float RotationSpeed = 0.1f;
	float BlurTimer = 0.0f;
};
