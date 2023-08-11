// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuWidget.h"

#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Framework/Application/SlateApplication.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"

void UMenuWidget::Show()
{
	if (GetParent())
		return;

	AddToViewport();
	
	if (auto* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0))
	{
		PlayerController->SetShowMouseCursor(FSlateApplication::Get().IsMouseAttached());
		UWidgetBlueprintLibrary::SetInputMode_UIOnlyEx(PlayerController);
	}
}