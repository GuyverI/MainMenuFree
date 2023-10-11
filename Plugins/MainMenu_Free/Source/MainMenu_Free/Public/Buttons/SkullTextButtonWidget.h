// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SkullTextButtonWidget.generated.h"

/**
 * 
 */
UCLASS()
class MAINMENU_FREE_API USkullTextButtonWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FButtonCallback);

	bool Initialize() override;
	void SynchronizeProperties() override;

	UFUNCTION(BlueprintCallable)
	void SetText(const FText& InText);

	UPROPERTY(BlueprintAssignable)
	FButtonCallback OnClicked;

protected:
	UPROPERTY(EditAnywhere)
	FText Text;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UButton* Button = nullptr;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UTextBlock* TextBlock = nullptr;

private:
	UFUNCTION()
	void OnButtonClicked();
};