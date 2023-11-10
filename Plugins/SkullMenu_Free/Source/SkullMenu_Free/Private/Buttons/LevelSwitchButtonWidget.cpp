// Copyright 2023 Skull Software


#include "Buttons/LevelSwitchButtonWidget.h"

#include "Kismet/GameplayStatics.h"

void USkullMenu_LevelSwitchButtonWidget::OnButtonClicked()
{
	UGameplayStatics::OpenLevelBySoftObjectPtr(this, Level);
}