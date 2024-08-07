// Fill out your copyright notice in the Description page of Project Settings.


#include "RBall_Player.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "../../../../../../Program Files/Epic Games/UE_5.3/Engine/Plugins/EnhancedInput/Source/EnhancedInput/Public/EnhancedInputSubsystems.h"
#include "../../../../../../Program Files/Epic Games/UE_5.3/Engine/Plugins/EnhancedInput/Source/EnhancedInput/Public/EnhancedInputComponent.h"

// Sets default values
ARBall_Player::ARBall_Player()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");

	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");

	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");

	// Setting up the root Component
	RootComponent = Mesh;

	SpringArm->SetupAttachment(Mesh);
	Camera->SetupAttachment(SpringArm);

}

// Called when the game starts or when spawned
void ARBall_Player::BeginPlay()
{
	Super::BeginPlay();

	// Add Input Mapping Context
	if (APlayerController* PlayerController = Cast<APlayerController>(Controller))
	{
		// Get Local Player Subsystem
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			// Add input context
			Subsystem->AddMappingContext(InputMapping, 0);
		}
	}
	
}


// Called every frame
void ARBall_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARBall_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* Input = CastChecked<UEnhancedInputComponent>(PlayerInputComponent))
	{
		Input->BindAction(MoveForward, ETriggerEvent::Triggered, this, &ARBall_Player::Move_Forward);
		Input->BindAction(MoveRight, ETriggerEvent::Triggered, this, &ARBall_Player::Move_Right);
	}

}

void ARBall_Player::Move_Forward(const FInputActionValue& value)
{
	//FInputActionValue::Axis1D inputValue = value.Get<FInputActionValue::Axis1D>();

	if (GEngine)
	{
		float directionValue = value.Get<float>();
		//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Emerald, FString::Printf(TEXT("%f"), directionValue));

	}
	
}

void ARBall_Player::Move_Right()
{
	GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Magenta, "Pressed Input Action _ Move Right/Left");
}
