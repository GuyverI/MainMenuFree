// Copyright 2023 Skull Software


#include "Buttons/ContainingButtonWidgetBase.h"

#include "Buttons/TextButtonWidget.h"

bool USkullMenu_ContainingButtonWidgetBase::Initialize()
{
	if (!Super::Initialize())
		return false;
	if (!IsValid(Button))
		return false;

	Button->OnClicked.AddUniqueDynamic(this, &USkullMenu_ContainingButtonWidgetBase::OnButtonClicked);

	return true;
}

void USkullMenu_ContainingButtonWidgetBase::SynchronizeProperties()
{
	Super::SynchronizeProperties();

	if (IsValid(Button))
		Button->SetText(Text);
}