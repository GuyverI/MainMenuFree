// Fill out your copyright notice in the Description page of Project Settings.


#include "Buttons/WidgetSwitchButtonWidget.h"

namespace USkullMenu_WidgetSwitchButtonWidgetUtils
{
	void SetWidgetVisibility(UWidget* Widget, const ESlateVisibility Visibility)
	{
		if (IsValid(Widget))
			Widget->SetVisibility(Visibility);
	}
}

void USkullMenu_WidgetSwitchButtonWidget::OnButtonClicked()
{
	USkullMenu_WidgetSwitchButtonWidgetUtils::SetWidgetVisibility(WidgetToHide, ESlateVisibility::Hidden);
	USkullMenu_WidgetSwitchButtonWidgetUtils::SetWidgetVisibility(WidgetToShow, ESlateVisibility::Visible);
}