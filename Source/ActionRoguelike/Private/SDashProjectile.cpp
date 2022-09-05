// Fill out your copyright notice in the Description page of Project Settings.


#include "SDashProjectile.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"


ASDashProjectile::ASDashProjectile()
{
	TeleportDelay = 0.2f;
	DetonateDelay = 0.2f;

	MoveComp->InitialSpeed = 6000.f;
}


void ASDashProjectile::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(TimerHandle_DelayedDetonate, this, &ASDashProjectile::Explode, DetonateDelay);
	
}


void ASDashProjectile::Explode_Implementation()
{
	// 如果我们是通过例如OnActorHit等其他方式调用的函数,取消计时器
	
	GetWorldTimerManager().ClearTimer(TimerHandle_DelayedDetonate);
	UE_LOG(LogTemp,Warning,TEXT("DashProjectile")) ;
	UGameplayStatics::SpawnEmitterAtLocation(this, ImpactVFX, GetActorLocation(), GetActorRotation());

	EffectComp->DeactivateSystem();

	MoveComp->StopMovementImmediately();
	SetActorEnableCollision(false);

	FTimerHandle TimerHandle_DelayedTeleport;
	GetWorldTimerManager().SetTimer(TimerHandle_DelayedTeleport, this, &ASDashProjectile::TeleportInstigator, TeleportDelay);

	// 跳过基础实现,因为他会销毁Actor,而我们需要让投射物保留一段时间来触发第二个计时器
	//Super::Explode_Implementation();
}


void ASDashProjectile::TeleportInstigator()
{
	AActor* ActorToTeleport = GetInstigator();
	if (ensure(ActorToTeleport))
	{
		// 保持玩家的旋转角度否则可能卡住
		ActorToTeleport->TeleportTo(GetActorLocation(), ActorToTeleport->GetActorRotation(), false, false);
	}
}