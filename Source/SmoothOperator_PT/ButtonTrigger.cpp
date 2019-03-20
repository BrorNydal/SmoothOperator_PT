// Fill out your copyright notice in the Description page of Project Settings.

#include "ButtonTrigger.h"
#include "BearCharacter.h"
#include "GameFramework/Actor.h"
#include "Engine/TriggerVolume.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"

// Sets default values for this component's properties
UButtonTrigger::UButtonTrigger()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UButtonTrigger::BeginPlay()
{
	Super::BeginPlay();
	
	ActorOpeningDoor = GetWorld()->GetFirstPlayerController()->GetPawn();
	
}


// Called every frame
void UButtonTrigger::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (Trigger->IsOverlappingActor(ActorOpeningDoor))
	{
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABearCharacter::StaticClass(), AllBears); //Get all bears
		TheBear = Cast<ABearCharacter>(AllBears[0]);

		if (TheBear->PickedUpCrystals >= CrystalsNeeded)
		{
			OpenDoor();
		}
		else
		{
			int AmountOfCrystalsNeeded = CrystalsNeeded - TheBear->PickedUpCrystals;
			FString PrintCrystalsLeft = FString("Need ") + FString::FromInt(AmountOfCrystalsNeeded) + FString(" More Crystals");
			GEngine->AddOnScreenDebugMessage(0, 1.0f, FColor::Emerald, PrintCrystalsLeft);
		}
	}
}

void UButtonTrigger::OpenDoor()
{
	AActor *Owner = GetOwner();

	if (Owner)
			Owner->Destroy(true, true);
	
}

