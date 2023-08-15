// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuWidget.h"
#include "InGameMenuWidget.generated.h"

UENUM(BlueprintType)
enum class EInGameInputMode : uint8
{
	GameOnly,
	GameAndUi
};

UCLASS()
class MAINMENUFREE_API UInGameMenuWidget : public UMenuWidget
{
	GENERATED_BODY()
	
public:
	void Show() override;

	UFUNCTION(BlueprintCallable)
	void Hide();

private:
	UPROPERTY(EditAnywhere)
	EInGameInputMode InGameInputMode = EInGameInputMode::GameOnly;
	
	UPROPERTY(EditAnywhere)
	bool bShouldPauseGame = true;

	bool bWasCursorShownBefore = false;
};
