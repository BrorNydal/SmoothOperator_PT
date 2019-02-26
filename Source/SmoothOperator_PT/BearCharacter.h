// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BearCharacter.generated.h"

class USphereComponent;
class AToddlerCharacter;
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsRiding = false; //Is toddler riding bear

	UFUNCTION(BlueprintCallable) //Called in bp subclass
		void Interact();

	UFUNCTION(BlueprintCallable) //Launch toddler in the air when IsRiding == true
		void Launch();	

	UPROPERTY(EditAnywhere, BlueprintReadWrite) //For future use when adding animation for turning, this be the bool to decide which turn animation to apply (left/right)
		bool RightRotation = false;

	UFUNCTION(BlueprintCallable)
		void Swap();	//Swap between characters
	
	//TSubclassOf<AToddlerCharacter> bpToddler;

	TArray<AActor*> AllToddlers;
	AToddlerCharacter *TheToddler;

};
