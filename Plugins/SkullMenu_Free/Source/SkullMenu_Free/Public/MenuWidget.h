// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class SKULLMENU_FREE_API USkullMenu_MenuWidget : public UUserWidget
{
	GENERATED_BODY()

protected:
	void AddToScreen(ULocalPlayer* LocalPlayer, int32 ZOrder) override;

	APlayerController* GetPlayerController(ULocalPlayer* LocalPlayer);
};
