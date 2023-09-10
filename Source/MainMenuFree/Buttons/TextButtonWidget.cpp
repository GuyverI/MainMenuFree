// Fill out your copyright notice in the Description page of Project Settings.


#include "TextButtonWidget.h"

#include "Components/TextBlock.h"
#include "Components/Button.h"

bool UTextButtonWidget::Initialize()
{
	if (!Super::Initialize())
		return false;
	if (!Button)
		return false;

	Button->OnClicked.AddUniqueDynamic(this, &UTextButtonWidget::OnButtonClicked);

	return true;
}

void UTextButtonWidget::SynchronizeProperties()
{
	Super::SynchronizeProperties();

	if (TextBlock)
		TextBlock->SetText(Text);
}

void UTextButtonWidget::SetText(const FText& InText)
{
	Text = InText;
	SynchronizeProperties();
}

void UTextButtonWidget::OnButtonClicked()
{
	OnClicked.Broadcast();
}