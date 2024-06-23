// Copyright 2023 Skull Software

#pragma once

#include "CoreMinimal.h"
#include "ContainingButtonWidgetBase.h"
#include "WidgetSwitchButtonWidget.generated.h"

UENUM(BlueprintType)
enum class ESkullMenu_SwitchMethod : uint8
{
	VisibilitySetting,
	ClientViewContent
};

UCLASS()
class SKULLMENU_FREE_API USkullMenu_WidgetSwitchButtonWidget : public USkullMenu_ContainingButtonWidgetBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Skull Menu")
	UWidget* WidgetToHide = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Skull Menu")
	UWidget* WidgetToShow = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category="Skull Menu")
	ESkullMenu_SwitchMethod SwitchMethod = ESkullMenu_SwitchMethod::ClientViewContent;
	
private:
	void OnButtonClicked() final;
};
