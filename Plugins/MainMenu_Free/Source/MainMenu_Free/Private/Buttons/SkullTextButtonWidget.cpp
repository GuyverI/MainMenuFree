// Fill out your copyright notice in the Description page of Project Settings.


#include "Buttons/SkullTextButtonWidget.h"

#include "Components/TextBlock.h"
#include "Components/Button.h"

bool USkullTextButtonWidget::Initialize()
{
	if (!Super::Initialize())
		return false;
	if (!Button)
		return false;

	Button->OnClicked.AddUniqueDynamic(this, &USkullTextButtonWidget::OnButtonClicked);

	return true;
}

void USkullTextButtonWidget::SynchronizeProperties()
{
	Super::SynchronizeProperties();

	if (TextBlock)
		TextBlock->SetText(Text);
}

void USkullTextButtonWidget::SetText(const FText& InText)
{
	Text = InText;
	SynchronizeProperties();
}

void USkullTextButtonWidget::OnButtonClicked()
{
	OnClicked.Broadcast();
}