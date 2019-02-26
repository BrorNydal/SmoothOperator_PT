// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ToddlerCharacter.generated.h"

class USphereComponent;
class ABearCharacter;

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool ToddlerCanInteract = false; // Bool that will decide if the character can interact

	UFUNCTION(BlueprintCallable)
		void Interact();	

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool RightRotation = false;	//Bool to decide which driection to turn (animation)

	UFUNCTION(BlueprintCallable)
		void Swap();		//Swapping characters function

	TArray<AActor*> AllBears;
	ABearCharacter *TheBear;
};
