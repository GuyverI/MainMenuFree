// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuWidget.h"

#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Framework/Application/SlateApplication.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"


void USkullMenu_MenuWidget::RemoveFromParent()
{
	if (auto* PlayerController = GetPlayerController(GetOwningLocalPlayer()))
	{
		if (InGameInputMode == ESkullMenu_InGameInputMode::GameOnly)
			UWidgetBlueprintLibrary::SetInputMode_GameOnly(PlayerController);
		else
			UWidgetBlueprintLibrary::SetInputMode_GameAndUIEx(PlayerController);

		PlayerController->SetShowMouseCursor(bWasCursorShownBefore);
	}

	Super::RemoveFromParent();
}

void USkullMenu_MenuWidget::AddToScreen(ULocalPlayer* LocalPlayer, int32 ZOrder)
{
	Super::AddToScreen(LocalPlayer, ZOrder);

	if (auto* PlayerController = GetPlayerController(LocalPlayer))
	{
		bWasCursorShownBefore = PlayerController->bShowMouseCursor;
		PlayerController->SetShowMouseCursor(FSlateApplication::Get().IsMouseAttached());

		UWidgetBlueprintLibrary::SetInputMode_UIOnlyEx(PlayerController);
	}
}

APlayerController* USkullMenu_MenuWidget::GetPlayerController(ULocalPlayer* LocalPlayer)
{
	return IsValid(LocalPlayer)
		? LocalPlayer->GetPlayerController(GetWorld())
		: UGameplayStatics::GetPlayerController(GetWorld(), 0);
}