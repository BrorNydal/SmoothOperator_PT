// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ButtonTrigger.generated.h"

class ATriggerVolume;
class ABearCharacter;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SMOOTHOPERATOR_PT_API UButtonTrigger : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UButtonTrigger();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	
	AActor *ActorOpeningDoor;

	UPROPERTY(EditAnywhere)
		ATriggerVolume *Trigger;

	UPROPERTY(EditAnywhere)
		USoundBase *TriggerSound;

	UPROPERTY(EditAnywhere)
		USoundBase *MissingCrystalsSound;

	UPROPERTY(EditAnywhere)
		int CrystalsNeeded;

	void OpenDoor();

private:
	TArray<AActor*> AllBears;
	ABearCharacter *TheBear;
};
