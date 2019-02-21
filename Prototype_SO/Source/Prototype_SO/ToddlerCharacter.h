// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ToddlerCharacter.generated.h"

class USpringArmComponent;
class USphereComponent;
class ABearCharacter;

UCLASS()
class PROTOTYPE_SO_API AToddlerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AToddlerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
		void MoveForward(float AxisValue);

	UFUNCTION()
		void MoveRight(float AxisValue);

	UPROPERTY(EditAnywhere, Category = "Camera")
		float CameraHeight{ 550.0f };

	UPROPERTY(EditAnywhere, Category = "Camera")
		float CameraPositionX{ -120.0f };

	UPROPERTY(EditAnywhere, Category = "Camera")
		float CameraPitch{ -75.0f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool CanToddlerRide{ false }; //Set to true deafault to debug

	UPROPERTY(EditAnywhere)
		UStaticMeshComponent* TheMesh;

	UPROPERTY(EditAnywhere)
		float SphereRadius{ 64.0f };

	USpringArmComponent* SpringArmToddler;

	UPROPERTY(EditAnywhere)
		USphereComponent* RadiusCollider;

	TArray<AActor*> Bears;

	ABearCharacter * TheBear;

private:
	UFUNCTION()
		void InteractTrue(UPrimitiveComponent* OverlappedComponent, AActor *OtherActor,
						  UPrimitiveComponent *OtherComponent, int32 OtherBodyIndex,
						  bool bFromSweep, const FHitResult &SweepResult);
	UFUNCTION()
		void InteractFalse(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
						   UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
