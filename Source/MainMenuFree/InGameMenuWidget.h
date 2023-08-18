// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuWidget.h"
#include "InGameMenuWidget.generated.h"

class UTextButtonWidget;

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
	bool Initialize() override;

	void Show() override;

	UFUNCTION(BlueprintCallable)
	void Hide();

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextButtonWidget* ResumeBtn = nullptr;

private:
	UPROPERTY(EditAnywhere)
	EInGameInputMode InGameInputMode = EInGameInputMode::GameOnly;
	
	UPROPERTY(EditAnywhere)
	bool bShouldPauseGame = true;

	bool bWasCursorShownBefore = false;
};
