// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

class ABearCharacter;

#include "CrystalActor.generated.h"

UCLASS()
class SMOOTHOPERATOR_PT_API ACrystalActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACrystalActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	int CrystalsLeft{ 4 };
	float CrystalEnergy = 5.0f; //The amount of "Cristal"energy the bear will gain when this is picked up

private:
	
};
