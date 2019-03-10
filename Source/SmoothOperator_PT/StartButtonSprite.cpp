// Fill out your copyright notice in the Description page of Project Settings.

#include "StartButtonSprite.h"

void AStartButtonSprite::RegisterMouseClick()
{
	OnClicked.AddDynamic(this, &AStartButtonSprite::OnMouseClick);
}

void AStartButtonSprite::OnMouseClick(AActor * ActorBeingClicked, FKey KeyPressed)
{
	
}
