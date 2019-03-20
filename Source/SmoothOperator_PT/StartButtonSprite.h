// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperSpriteActor.h"
#include "PaperSpriteComponent.h"
#include "InputCoreTypes.h"
#include "StartButtonSprite.generated.h"

class UBoxComponent;

UCLASS()
class SMOOTHOPERATOR_PT_API AStartButtonSprite : public APaperSpriteActor
{
	GENERATED_BODY()
	

private:


public:

	void RegisterMouseClick();

	UFUNCTION()
		void OnMouseClick(AActor *ActorBeingClicked, FKey KeyPressed);

	UPROPERTY(EditAnywhere)
		UBoxComponent* HitBox;


};
