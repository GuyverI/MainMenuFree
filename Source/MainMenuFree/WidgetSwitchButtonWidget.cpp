// Fill out your copyright notice in the Description page of Project Settings.


#include "WidgetSwitchButtonWidget.h"

namespace UWidgetSwitchButtonWidgetUtils
{
	void SetWidgetVisibility(UWidget* Widget, const ESlateVisibility Visibility)
	{
		if (IsValid(Widget))
			Widget->SetVisibility(Visibility);
	}
}

void UWidgetSwitchButtonWidget::OnButtonClicked()
{
	UWidgetSwitchButtonWidgetUtils::SetWidgetVisibility(WidgetToHide, ESlateVisibility::Hidden);
	UWidgetSwitchButtonWidgetUtils::SetWidgetVisibility(WidgetToShow, ESlateVisibility::Visible);
}