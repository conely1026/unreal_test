// Fill out your copyright notice in the Description page of Project Settings.


#include "STargetDummy.h"

// Sets default values
ASTargetDummy::ASTargetDummy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
	RootComponent = MeshComp;

	AttributeComp = CreateDefaultSubobject<USAttributeComponent>("AttributeComp");
	AttributeComp->OnHealthChanged.AddDynamic(this,&ASTargetDummy::OnHealthChanged);

}

void ASTargetDummy::OnHealthChanged(AActor* InstigatorActor, USAttributeComponent* OwningComp, float NewHealth, float delta)
{
	if(delta<0.0f)
	{
		MeshComp->SetScalarParameterValueOnMaterials("TimeToHit",GetWorld()->TimeSeconds);
	}
		
	
}


