// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "DoorTriggerVolume.generated.h"

/**
 * 
 */
UCLASS()
class SMOOTHOPERATOR_PT_API ADoorTriggerVolume : public ATriggerVolume
{
	GENERATED_BODY()

public:
	FString MissingCrystals;
	
};
