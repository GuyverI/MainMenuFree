// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MenuWidget.generated.h"


UENUM(BlueprintType)
enum class ESkullMenu_InGameInputMode : uint8
{
	GameOnly,
	GameAndUi
};

UCLASS()
class SKULLMENU_FREE_API USkullMenu_MenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	void RemoveFromParent() override;

	UPROPERTY(EditAnywhere)
	ESkullMenu_InGameInputMode InGameInputMode = ESkullMenu_InGameInputMode::GameOnly;

protected:
	void AddToScreen(ULocalPlayer* LocalPlayer, int32 ZOrder) override;

	APlayerController* GetPlayerController(ULocalPlayer* LocalPlayer);

private:
	bool bWasCursorShownBefore = false;
};
