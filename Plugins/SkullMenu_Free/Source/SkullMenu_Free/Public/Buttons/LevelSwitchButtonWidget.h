// Copyright 2023 Skull Software

#pragma once

#include "CoreMinimal.h"
#include "ContainingButtonWidgetBase.h"
#include "LevelSwitchButtonWidget.generated.h"

/**
 * 
 */
UCLASS()
class SKULLMENU_FREE_API USkullMenu_LevelSwitchButtonWidget : public USkullMenu_ContainingButtonWidgetBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, Category="Skull Menu")
	TSoftObjectPtr<UWorld> Level;

private:
	void OnButtonClicked() final;
};
