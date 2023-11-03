// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ContainingButtonWidgetBase.h"
#include "WidgetSwitchButtonWidget.generated.h"

/**
 * 
 */
UCLASS()
class SKULLMENU_FREE_API USkullMenu_WidgetSwitchButtonWidget : public USkullMenu_ContainingButtonWidgetBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	UWidget* WidgetToHide = nullptr;

	UPROPERTY(EditAnywhere)
	UWidget* WidgetToShow = nullptr;
	
private:
	void OnButtonClicked() final;
};
