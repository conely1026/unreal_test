// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SProjectileBase.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class UParticleSystemComponent;

UCLASS(ABSTRACT) // 'ABSTRACT' 将这个类标记为未完成,使用这个标记可以让这个类不在虚幻编辑器的类如SpawnActor的下拉窗口中出现
class ACTIONROGUELIKE_API ASProjectileBase : public AActor
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditDefaultsOnly, Category = "Effects")
		UParticleSystem* ImpactVFX;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		USphereComponent* SphereComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		UProjectileMovementComponent* MoveComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
		UParticleSystemComponent* EffectComp;

	UFUNCTION()
		virtual void OnActorHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	// BlueprintNativeEvent = C++基础实现，在蓝图中可以拓展
	// 使用BlueprintCallable允许蓝图子类调用函数来触发爆炸
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
		void Explode();

	virtual void PostInitializeComponents() override;

public:

	ASProjectileBase();

};