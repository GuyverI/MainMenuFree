// Fill out your copyright notice in the Description page of Project Settings.


#include "Buttons/SkullLevelSwitchButtonWidget.h"

#include "Kismet/GameplayStatics.h"

void USkullLevelSwitchButtonWidget::OnButtonClicked()
{
	UGameplayStatics::OpenLevelBySoftObjectPtr(this, Level);
}