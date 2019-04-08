// Fill out your copyright notice in the Description page of Project Settings.

#include "WaypointAI.h"
#include "kismet/kismetMathLibrary.h"

// Sets default values
AWaypoint::AWaypoint()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AWaypoint::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AWaypoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Target = waypoints[i]->GetActorLocation();
	FVector Direction = Target - GetActorLocation();

	FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(
		GetActorLocation(),
		waypoints[i]->GetActorLocation()
	);

	FRotator FacingRotation = FQuat::Slerp(
		GetActorRotation().Quaternion(),
		LookAtRotation.Quaternion(),
		0.07f
	).Rotator();

	SetActorRotation(FacingRotation);

	SetActorLocation(
		GetActorLocation() +
		Direction.GetUnsafeNormal() * speed * DeltaTime
	);

	if (GetActorLocation().X <= waypoints[i]->GetActorLocation().X + accuracy &&
		GetActorLocation().Y <= waypoints[i]->GetActorLocation().Y + accuracy)
	{
		i += 1;
		if (i >= waypoints.Num())
		{
			i = 0;
		}
	}
}