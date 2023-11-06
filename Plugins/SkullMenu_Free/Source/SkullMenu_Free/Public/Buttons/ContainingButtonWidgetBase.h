// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ContainingButtonWidgetBase.generated.h"

class USkullMenu_TextButtonWidget;

/**
 * 
 */
UCLASS(Abstract)
class SKULLMENU_FREE_API USkullMenu_ContainingButtonWidgetBase : public UUserWidget
{
	GENERATED_BODY()

public:
	bool Initialize() override;
	void SynchronizeProperties() override;

protected:
	UPROPERTY(EditAnywhere, Category="Skull Menu")
	FText Text;

	UPROPERTY(BlueprintReadWrite, Category = "Skull Menu", meta = (BindWidget))
	USkullMenu_TextButtonWidget* Button = nullptr;

private:
	UFUNCTION()
	virtual void OnButtonClicked() PURE_VIRTUAL(USkullMenu_ContainingButtonWidgetBase::OnButtonClicked());
};
