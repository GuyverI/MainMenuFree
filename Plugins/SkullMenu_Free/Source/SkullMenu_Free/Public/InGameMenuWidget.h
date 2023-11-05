// Fill out your copyright notice in the Description page of Project Settings.

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
	bool Initialize() override;

	void RemoveFromParent() override;

protected:
	void AddToScreen(ULocalPlayer* LocalPlayer, int32 ZOrder) override;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	USkullMenu_TextButtonWidget* ResumeBtn = nullptr;

private:
	UPROPERTY(EditAnywhere)
	bool bShouldPauseGame = true;
};
