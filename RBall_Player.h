// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "RBall_Player.generated.h"

class USpringArmComponent;
class UCameraComponent;

class UInputMappingContext;
class UInputAction;

UCLASS()
class ROLLABALL_API ARBall_Player : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ARBall_Player();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Components

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UCameraComponent* Camera;

	// Enhanced Input
	UPROPERTY(EditAnywhere, BlueprintReadonly, Category = "EnhancedInput")
	UInputMappingContext* InputMapping;

	UPROPERTY(EditAnywhere, BlueprintReadonly, Category = "EnhancedInput")
	UInputAction* MoveForward;

	UPROPERTY(EditAnywhere, BlueprintReadonly, Category = "EnhancedInput")
	UInputAction* MoveRight;

	// Move Forward Function
	void Move_Forward(const FInputActionValue& value);
	// Move Right Function
	void Move_Right();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


};
