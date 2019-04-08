// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "WaypointAI.generated.h"


UCLASS()
class SMOOTHOPERATOR_PT_API AWaypoint : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AWaypoint();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
		TArray<AActor *> waypoints;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
		float accuracy;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
		float speed = 500;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
		float rotSpeed;

	int i = 0;
};
