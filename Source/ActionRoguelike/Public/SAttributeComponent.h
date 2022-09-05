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
	// EditAnywhere - 可以在蓝图编辑器中编辑并且在关卡中每个实例都可以编辑.
	// VisibleAnywhere - 在关卡和编辑器中只读 (用于组件)
	// EditDefaultsOnly - 对于生成的实例属性是隐藏的, 只能在蓝图编辑器中编辑
	// VisibleDefaultsOnly - 对象只在蓝图编辑器中可见且只读 (不常见)
	// EditInstanceOnly - 只能编辑是实例 (例如在关卡中)
	// --
	// BlueprintReadOnly - 在蓝图编程中只读 (不影响蓝图右侧细节面板的数值调整)
	// BlueprintReadWrite - 在蓝图变成中可以读写
	// --
	// Category = "" - 只在细节面板和蓝图的上下文搜索时显示的类别
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attributes")
		float Health;


public:

	UPROPERTY(BlueprintAssignable)
		FOnHealthChanged OnHealthChanged;

	UFUNCTION(BlueprintCallable, Category = "Attributes")
		bool ApplyHealthChange(float Delta);
	

		
};
