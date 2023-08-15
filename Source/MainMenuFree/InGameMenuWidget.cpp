// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameMenuWidget.h"

#include "Blueprint/WidgetBlueprintLibrary.h"
#include "GameFramework/PlayerController.h"

void UInGameMenuWidget::Show()
{
	if (auto* PlayerController = GetPlayerController())
	{
		bWasCursorShownBefore = PlayerController->bShowMouseCursor;
		
		if (bShouldPauseGame)
			PlayerController->SetPause(true);
	}

	Super::Show();
}

void UInGameMenuWidget::Hide()
{
	if (auto* PlayerController = GetPlayerController())
	{
		if (InGameInputMode == EInGameInputMode::GameOnly)
			UWidgetBlueprintLibrary::SetInputMode_GameOnly(PlayerController);
		else
			UWidgetBlueprintLibrary::SetInputMode_GameAndUIEx(PlayerController);

		PlayerController->SetShowMouseCursor(bWasCursorShownBefore);

		if (bShouldPauseGame)
			PlayerController->SetPause(false);
	}

	RemoveFromViewport();
}