// Fill out your copyright notice in the Description page of Project Settings.


#include "Buttons/SkullContainingButtonWidgetBase.h"

#include "Buttons/SkullTextButtonWidget.h"

bool USkullContainingButtonWidgetBase::Initialize()
{
	if (!Super::Initialize())
		return false;
	if (!IsValid(Button))
		return false;

	Button->OnClicked.AddUniqueDynamic(this, &USkullContainingButtonWidgetBase::OnButtonClicked);

	return true;
}

void USkullContainingButtonWidgetBase::SynchronizeProperties()
{
	Super::SynchronizeProperties();

	if (IsValid(Button))
		Button->SetText(Text);
}