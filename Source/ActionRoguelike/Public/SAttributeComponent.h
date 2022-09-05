// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SAttributeComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnHealthChanged, AActor*, InstigatorActor, USAttributeComponent*, OwningComp, float, NewHealth, float, Delta);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ACTIONROGUELIKE_API USAttributeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USAttributeComponent();

protected:
	// EditAnywhere - ��������ͼ�༭���б༭�����ڹؿ���ÿ��ʵ�������Ա༭.
	// VisibleAnywhere - �ڹؿ��ͱ༭����ֻ�� (�������)
	// EditDefaultsOnly - �������ɵ�ʵ�����������ص�, ֻ������ͼ�༭���б༭
	// VisibleDefaultsOnly - ����ֻ����ͼ�༭���пɼ���ֻ�� (������)
	// EditInstanceOnly - ֻ�ܱ༭��ʵ�� (�����ڹؿ���)
	// --
	// BlueprintReadOnly - ����ͼ�����ֻ�� (��Ӱ����ͼ�Ҳ�ϸ��������ֵ����)
	// BlueprintReadWrite - ����ͼ����п��Զ�д
	// --
	// Category = "" - ֻ��ϸ��������ͼ������������ʱ��ʾ�����
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attributes")
		float Health;


public:

	UPROPERTY(BlueprintAssignable)
		FOnHealthChanged OnHealthChanged;

	UFUNCTION(BlueprintCallable, Category = "Attributes")
		bool ApplyHealthChange(float Delta);
	

		
};
