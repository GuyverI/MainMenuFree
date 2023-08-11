// Fill out your copyright notice in the Description page of Project Settings.


#include "ContainingButtonWidgetBase.h"

#include "TextButtonWidget.h"

bool UContainingButtonWidgetBase::Initialize()
{
	if (!Super::Initialize())
		return false;
	if (!IsValid(Button))
		return false;

	Button->OnClicked.AddUniqueDynamic(this, &UContainingButtonWidgetBase::OnButtonClicked);

	return true;
}

void UContainingButtonWidgetBase::SynchronizeProperties()
{
	Super::SynchronizeProperties();

	if (IsValid(Button))
		Button->SetText(Text);
}