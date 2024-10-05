// Copyright 2023 Skull Software


#include "InGameMenuWidget.h"

#include "Blueprint/GameViewportSubsystem.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "GameFramework/PlayerController.h"

#include "Buttons/TextButtonWidget.h"


void USkullMenu_InGameMenuWidget::RemoveFromParent()
{
	if (auto* PlayerController = GetPlayerController(GetOwningLocalPlayer()))
	{
		if (bShouldPauseGame)
			PlayerController->SetPause(false);
	}

	Super::RemoveFromParent();
}

void USkullMenu_InGameMenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (!IsValid(ResumeBtn))
		return;

	ResumeBtn->OnClicked.AddUniqueDynamic(this, &USkullMenu_InGameMenuWidget::RemoveFromParent);
}

void USkullMenu_InGameMenuWidget::OnAddedToViewport(UWidget* Widget, ULocalPlayer* LocalPlayer)
{
	Super::OnAddedToViewport(Widget, LocalPlayer);

	if (Widget != this)
		return;

	if (auto* PlayerController = GetPlayerController(LocalPlayer))
	{
		if (bShouldPauseGame)
			PlayerController->SetPause(true);
	}
}