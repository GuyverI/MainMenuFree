// Copyright 2023 Skull Software


#include "MenuWidget.h"

#include "Blueprint/GameViewportSubsystem.h"
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

void USkullMenu_MenuWidget::NativeConstruct()
{
	Super::NativeConstruct();

	if (UGameViewportSubsystem* Subsystem = UGameViewportSubsystem::Get(GetWorld()))
	{
		if (!Subsystem->OnWidgetAdded.IsBoundToObject(this))
			OnAddedToViewportDelegateHandle = Subsystem->OnWidgetAdded.AddLambda([this](UWidget* Widget, ULocalPlayer* LocalPlayer)
				{ OnAddedToViewport(Widget, LocalPlayer); });
	}
}

void USkullMenu_MenuWidget::NativeDestruct()
{
	if (UGameViewportSubsystem* Subsystem = UGameViewportSubsystem::Get(GetWorld()))
	{
		Subsystem->OnWidgetAdded.Remove(OnAddedToViewportDelegateHandle);
		OnAddedToViewportDelegateHandle.Reset();
	}

	Super::NativeDestruct();
}

void USkullMenu_MenuWidget::OnAddedToViewport(UWidget* Widget, ULocalPlayer* LocalPlayer)
{
	if (Widget != this)
		return;

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