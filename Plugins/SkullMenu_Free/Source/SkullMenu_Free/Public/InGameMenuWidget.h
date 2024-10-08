// Copyright 2023 Skull Software

#pragma once

#include "CoreMinimal.h"
#include "MenuWidget.h"
#include "InGameMenuWidget.generated.h"

class USkullMenu_TextButtonWidget;

UCLASS()
class SKULLMENU_FREE_API USkullMenu_InGameMenuWidget : public USkullMenu_MenuWidget
{
	GENERATED_BODY()
	
public:
	void RemoveFromParent() override;

protected:
	void NativeConstruct() override;

	void OnAddedToViewport(UWidget* Widget, ULocalPlayer* LocalPlayer) override;

	UPROPERTY(BlueprintReadWrite, Category="Skull Menu", meta = (BindWidget))
	USkullMenu_TextButtonWidget* ResumeBtn = nullptr;


private:
	UPROPERTY(EditAnywhere, Category="Skull Menu")
	bool bShouldPauseGame = true;
};
