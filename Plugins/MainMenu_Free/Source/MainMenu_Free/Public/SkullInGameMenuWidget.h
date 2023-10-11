// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SkullMenuWidget.h"
#include "SkullInGameMenuWidget.generated.h"

class USkullTextButtonWidget;

UENUM(BlueprintType)
enum class ESkullInGameInputMode : uint8
{
	GameOnly,
	GameAndUi
};

UCLASS()
class MAINMENU_FREE_API USkullInGameMenuWidget : public USkullMenuWidget
{
	GENERATED_BODY()
	
public:
	bool Initialize() override;

	void Show() override;

	UFUNCTION(BlueprintCallable)
	void Hide();

protected:
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	USkullTextButtonWidget* ResumeBtn = nullptr;

private:
	UPROPERTY(EditAnywhere)
	ESkullInGameInputMode InGameInputMode = ESkullInGameInputMode::GameOnly;
	
	UPROPERTY(EditAnywhere)
	bool bShouldPauseGame = true;

	bool bWasCursorShownBefore = false;
};
