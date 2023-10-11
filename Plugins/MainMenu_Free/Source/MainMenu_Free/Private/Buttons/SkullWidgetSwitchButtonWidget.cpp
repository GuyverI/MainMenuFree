// Fill out your copyright notice in the Description page of Project Settings.


#include "Buttons/SkullWidgetSwitchButtonWidget.h"

namespace USkullWidgetSwitchButtonWidgetUtils
{
	void SetWidgetVisibility(UWidget* Widget, const ESlateVisibility Visibility)
	{
		if (IsValid(Widget))
			Widget->SetVisibility(Visibility);
	}
}

void USkullWidgetSwitchButtonWidget::OnButtonClicked()
{
	USkullWidgetSwitchButtonWidgetUtils::SetWidgetVisibility(WidgetToHide, ESlateVisibility::Hidden);
	USkullWidgetSwitchButtonWidgetUtils::SetWidgetVisibility(WidgetToShow, ESlateVisibility::Visible);
}