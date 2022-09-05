// Fill out your copyright notice in the Description page of Project Settings.


#include "SExplosiveBarrel.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "Components/StaticMeshComponent.h"
#include"DrawDebugHelpers.h"


ASExplosiveBarrel::ASExplosiveBarrel()
{
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
	MeshComp->SetSimulatePhysics(true);
	RootComponent = MeshComp;

	ForceComp = CreateDefaultSubobject<URadialForceComponent>("ForceComp");
	ForceComp->SetupAttachment(MeshComp);

	// 将这个设置为true的话我们就可以通过Tick函数不断对周围应用冲击力
	ForceComp->SetAutoActivate(false);

	ForceComp->Radius = 750.0f;
	ForceComp->ImpulseStrength = 2500.0f; // Alternative: 200000.0 if bImpulseVelChange = false
	// 可选, 忽略其他物体的质量 (如果为false, 冲击波会需要更大力度来根据其他物体的质量将他们推得更远)
	ForceComp->bImpulseVelChange = true;

	// 可选, 默认构造函数会为我们添加4中应用冲击波的对象类型, 但不包括WorldDynamic
	ForceComp->AddCollisionChannelToAffect(ECC_WorldDynamic);
}


void ASExplosiveBarrel::PostInitializeComponents()
{
	// 不要忘记调用父类的函数
	Super::PostInitializeComponents();

	MeshComp->OnComponentHit.AddDynamic(this, &ASExplosiveBarrel::OnActorHit);
}


void ASExplosiveBarrel::OnActorHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	ForceComp->FireImpulse();

	// 使用日志确保我们触发了这个事件
	UE_LOG(LogTemp, Log, TEXT("OnActorHit reached (ExplosiveBarrel)"));

	FString CombinedString = FString::Printf(TEXT("Hit at location :%s"),*Hit.ImpactPoint.ToString());
	DrawDebugString(GetWorld(), Hit.ImpactPoint, CombinedString, nullptr, FColor::Green, 2.0f, true);
}