// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SkullContainingButtonWidgetBase.h"
#include "SkullLevelSwitchButtonWidget.generated.h"

/**
 * 
 */
UCLASS()
class MAINMENU_FREE_API USkullLevelSwitchButtonWidget : public USkullContainingButtonWidgetBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UWorld> Level;

private:
	void OnButtonClicked() final;
};
