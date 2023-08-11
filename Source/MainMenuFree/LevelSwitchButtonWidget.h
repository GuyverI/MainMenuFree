// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ContainingButtonWidgetBase.h"
#include "LevelSwitchButtonWidget.generated.h"

/**
 * 
 */
UCLASS()
class MAINMENUFREE_API ULevelSwitchButtonWidget : public UContainingButtonWidgetBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere)
	TSoftObjectPtr<UWorld> Level;

private:
	void OnButtonClicked() final;
};
