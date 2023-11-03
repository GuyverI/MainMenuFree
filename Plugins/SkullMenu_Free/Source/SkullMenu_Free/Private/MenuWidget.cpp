// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuWidget.h"

#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Framework/Application/SlateApplication.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"

void USkullMenu_MenuWidget::Show()
{
	AddToViewport();
	
	if (auto* PlayerController = GetPlayerController())
	{
		PlayerController->SetShowMouseCursor(FSlateApplication::Get().IsMouseAttached());
		UWidgetBlueprintLibrary::SetInputMode_UIOnlyEx(PlayerController);
	}
}

APlayerController* USkullMenu_MenuWidget::GetPlayerController()
{
	return UGameplayStatics::GetPlayerController(GetWorld(), 0);
}