// Copyright 2023 Skull Software


#include "Buttons/WidgetSwitchButtonWidget.h"
#include "Blueprint/GameViewportSubsystem.h"

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
	if (SwitchMethod == ESkullMenu_SwitchMethod::ClientViewContent)
	{
		if (IsValid(WidgetToHide))
			WidgetToHide->RemoveFromParent();

		if (IsValid(WidgetToShow))
		{
			if (UGameViewportSubsystem* Subsystem = UGameViewportSubsystem::Get(GetWorld()))
			{
				const auto WidgetSlot = Subsystem->GetWidgetSlot(WidgetToShow);
				Subsystem->AddWidget(WidgetToShow, WidgetSlot);
			}
		}
	}
	else
	{
		USkullMenu_WidgetSwitchButtonWidgetUtils::SetWidgetVisibility(WidgetToHide, ESlateVisibility::Hidden);
		USkullMenu_WidgetSwitchButtonWidgetUtils::SetWidgetVisibility(WidgetToShow, ESlateVisibility::Visible);
	}
}