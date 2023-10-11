// Fill out your copyright notice in the Description page of Project Settings.


#include "SkullInGameMenuWidget.h"

#include "Blueprint/WidgetBlueprintLibrary.h"
#include "GameFramework/PlayerController.h"

#include "Buttons/SkullTextButtonWidget.h"

bool USkullInGameMenuWidget::Initialize()
{
	if (!Super::Initialize())
		return false;

	if (!IsValid(ResumeBtn))
		return false;

	ResumeBtn->OnClicked.AddUniqueDynamic(this, &USkullInGameMenuWidget::Hide);

	return true;
}

void USkullInGameMenuWidget::Show()
{
	if (auto* PlayerController = GetPlayerController())
	{
		bWasCursorShownBefore = PlayerController->bShowMouseCursor;
		
		if (bShouldPauseGame)
			PlayerController->SetPause(true);
	}

	Super::Show();
}

void USkullInGameMenuWidget::Hide()
{
	if (auto* PlayerController = GetPlayerController())
	{
		if (InGameInputMode == ESkullInGameInputMode::GameOnly)
			UWidgetBlueprintLibrary::SetInputMode_GameOnly(PlayerController);
		else
			UWidgetBlueprintLibrary::SetInputMode_GameAndUIEx(PlayerController);

		PlayerController->SetShowMouseCursor(bWasCursorShownBefore);

		if (bShouldPauseGame)
			PlayerController->SetPause(false);
	}

	RemoveFromViewport();
}