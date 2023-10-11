// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SkullMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class MAINMENU_FREE_API USkullMenuWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	virtual void Show();

protected:
	APlayerController* GetPlayerController();
};
