// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SkullContainingButtonWidgetBase.generated.h"

class USkullTextButtonWidget;

/**
 * 
 */
UCLASS(Abstract)
class MAINMENU_FREE_API USkullContainingButtonWidgetBase : public UUserWidget
{
	GENERATED_BODY()

public:
	bool Initialize() override;
	void SynchronizeProperties() override;

protected:
	UPROPERTY(EditAnywhere)
	FText Text;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	USkullTextButtonWidget* Button = nullptr;

private:
	UFUNCTION()
	virtual void OnButtonClicked() PURE_VIRTUAL(USkullContainingButtonWidgetBase::OnButtonClicked());
};
