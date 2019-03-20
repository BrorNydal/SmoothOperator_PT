// Fill out your copyright notice in the Description page of Project Settings.

#include "StartButtonSprite.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/Engine.h"

void AStartButtonSprite::RegisterMouseClick()
{
	OnClicked.AddDynamic(this, &AStartButtonSprite::OnMouseClick);
}

void AStartButtonSprite::OnMouseClick(AActor * ActorBeingClicked, FKey KeyPressed)
{
	GEngine->AddOnScreenDebugMessage(0, 1.0f, FColor::Emerald, TEXT("Clicked"));
	UGameplayStatics::OpenLevel(GetWorld(), "TutorialMap");
}
