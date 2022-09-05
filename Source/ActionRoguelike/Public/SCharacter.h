// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SInteractionComponent.h"
#include "GameFramework/Character.h"
#include "SCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class USInteractionComponent;
class UAnimMontage;
class USAttributeComponent;

UCLASS()
class ACTIONROGUELIKE_API ASCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASCharacter();

protected:
	FTimerHandle TimerHandle_PrimaryAttack;
	FTimerHandle TimerHandle_BlackHoleAttack;
	FTimerHandle TimerHandle_DashAttack;

	UPROPERTY(EditAnywhere, Category = "Attack")
		UAnimMontage* AttackAnim;

	UPROPERTY(EditAnywhere, Category = "Attack")
		TSubclassOf<AActor> ProjectileClass ;

	UPROPERTY(EditAnywhere, Category = "Attack")
		TSubclassOf<AActor> BlackHoleProjectileClass;

	UPROPERTY(EditAnywhere, Category = "Attack")
		TSubclassOf<AActor> DashProjectileClass;
	
	UPROPERTY(VisibleAnywhere)
		USpringArmComponent* SpringArmComp;
	
	UPROPERTY(VisibleAnywhere)
		UCameraComponent* CameraComp;

	UPROPERTY(VisibleAnywhere)
		USInteractionComponent* InteractionComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		USAttributeComponent* AttributeComp;

	

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float value);
	void MoveRight(float value);

	void PrimaryInteract();
	void PrimaryAttack();
	void PrimaryAttack_TimeElapsed();
	void SpawnProjectile(TSubclassOf<AActor> ClassToSpawn);

	void BlackHoleAttack();
	void BlackHoleAttack_TimeElapsed();

	void Dash();
	void Dash_TimeElapsed();

	float AttackAnimDelay;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};


