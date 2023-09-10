// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ContainingButtonWidgetBase.generated.h"

class UTextButtonWidget;

/**
 * 
 */
UCLASS(Abstract)
class MAINMENUFREE_API UContainingButtonWidgetBase : public UUserWidget
{
	GENERATED_BODY()

public:
	bool Initialize() override;
	void SynchronizeProperties() override;

protected:
	UPROPERTY(EditAnywhere)
	FText Text;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UTextButtonWidget* Button = nullptr;

private:
	UFUNCTION()
	virtual void OnButtonClicked() PURE_VIRTUAL(UContainingButtonWidgetBase::OnButtonClicked());
};
