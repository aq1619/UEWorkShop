// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PlayerCharacter.generated.h"

//forward declaration, declare without defining. tells compiler type exists, but dosent provide details
class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

UCLASS()
class WORKSHOP_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

	

public:
	// Sets default values for this character's properties
	APlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Callbacks for input
	void Move(const FInputActionValue& value);
	void Look(const FInputActionValue& value);

	UPROPERTY(EditAnywhere,  Category = "Health")
	float HP{};

	UFUNCTION(BlueprintCallable)
	void PrintHealth();

	UPROPERTY(VisibleAnywhere, Category = "Camera");

	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, Category = "Camera");

	UCameraComponent* FollowCamera;

	//Input Actions
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* MovementAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* JumpAction;
};
