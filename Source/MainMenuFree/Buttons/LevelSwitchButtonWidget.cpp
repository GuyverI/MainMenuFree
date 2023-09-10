// Fill out your copyright notice in the Description page of Project Settings.


#include "LevelSwitchButtonWidget.h"

#include "Kismet/GameplayStatics.h"

void ULevelSwitchButtonWidget::OnButtonClicked()
{
	UGameplayStatics::OpenLevelBySoftObjectPtr(this, Level);
}