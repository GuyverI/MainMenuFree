// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TextButtonWidget.generated.h"

/**
 * 
 */
UCLASS()
class SKULLMENU_FREE_API USkullMenu_TextButtonWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FButtonCallback);

	bool Initialize() override;
	void SynchronizeProperties() override;

	UFUNCTION(BlueprintCallable, Category="Skull Menu")
	void SetText(const FText& InText);

	UPROPERTY(BlueprintAssignable)
	FButtonCallback OnClicked;

protected:
	UPROPERTY(EditAnywhere, Category="Skull Menu")
	FText Text;

	UPROPERTY(BlueprintReadWrite, Category="Skull Menu", meta = (BindWidget))
	class UButton* Button = nullptr;

	UPROPERTY(BlueprintReadWrite, Category="Skull Menu", meta = (BindWidget))
	class UTextBlock* TextBlock = nullptr;

private:
	UFUNCTION()
	void OnButtonClicked();
};
