// Fill out your copyright notice in the Description page of Project Settings.


#include "Buttons/LevelSwitchButtonWidget.h"

#include "Kismet/GameplayStatics.h"

void USkullMenu_LevelSwitchButtonWidget::OnButtonClicked()
{
	UGameplayStatics::OpenLevelBySoftObjectPtr(this, Level);
}