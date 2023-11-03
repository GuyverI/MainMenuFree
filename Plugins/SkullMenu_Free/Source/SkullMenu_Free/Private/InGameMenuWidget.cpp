// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameMenuWidget.h"

#include "Blueprint/WidgetBlueprintLibrary.h"
#include "GameFramework/PlayerController.h"

#include "Buttons/TextButtonWidget.h"

bool USkullMenu_InGameMenuWidget::Initialize()
{
	if (!Super::Initialize())
		return false;

	if (!IsValid(ResumeBtn))
		return false;

	ResumeBtn->OnClicked.AddUniqueDynamic(this, &USkullMenu_InGameMenuWidget::Hide);

	return true;
}

void USkullMenu_InGameMenuWidget::Show()
{
	if (auto* PlayerController = GetPlayerController())
	{
		bWasCursorShownBefore = PlayerController->bShowMouseCursor;
		
		if (bShouldPauseGame)
			PlayerController->SetPause(true);
	}

	Super::Show();
}

void USkullMenu_InGameMenuWidget::Hide()
{
	if (auto* PlayerController = GetPlayerController())
	{
		if (InGameInputMode == ESkullMenu_InGameInputMode::GameOnly)
			UWidgetBlueprintLibrary::SetInputMode_GameOnly(PlayerController);
		else
			UWidgetBlueprintLibrary::SetInputMode_GameAndUIEx(PlayerController);

		PlayerController->SetShowMouseCursor(bWasCursorShownBefore);

		if (bShouldPauseGame)
			PlayerController->SetPause(false);
	}

	RemoveFromViewport();
}