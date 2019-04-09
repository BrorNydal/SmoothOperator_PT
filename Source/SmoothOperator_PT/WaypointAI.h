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
		float accuracy = 25.0f; //How close befor it can move on to next waypoint

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
		float speed = 250.0f;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
		float rotSpeed = 0.1;

	int i = 0;

private:
	float ShortDelay = 0.0f;
	bool LastWP = false;
	
};
