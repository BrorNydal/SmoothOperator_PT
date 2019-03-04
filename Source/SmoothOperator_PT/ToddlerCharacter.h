// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
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
	
	
		USphereComponent *InteractionRadius; //Radius that will in the future decide what the character can interact with

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool ToddlerCanInteract = false; // Bool that will decide if the character can interact

	UFUNCTION()
		void Interactable(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
						UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, 
						bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void NonInteractable(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
							UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool RightRotation = false;	//Bool to decide which driection to turn (animation)

	UFUNCTION(BlueprintCallable)
		void Swap();		//Swapping characters function

	UFUNCTION(BlueprintCallable)
		void RideBear();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AActor *InteractableActor;

	TArray<AActor*> AllBears;
	ABearCharacter *TheBear;	

private:
	void Interact();
	
	
};
