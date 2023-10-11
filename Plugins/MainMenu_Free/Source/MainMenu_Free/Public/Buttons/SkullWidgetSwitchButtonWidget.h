// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SkullContainingButtonWidgetBase.h"
#include "SkullWidgetSwitchButtonWidget.generated.h"

/**
 * 
 */
UCLASS()
class MAINMENU_FREE_API USkullWidgetSwitchButtonWidget : public USkullContainingButtonWidgetBase
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
