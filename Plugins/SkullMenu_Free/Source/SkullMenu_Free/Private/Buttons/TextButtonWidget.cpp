// Copyright 2023 Skull Software


#include "Buttons/TextButtonWidget.h"

#include "Components/TextBlock.h"
#include "Components/Button.h"

bool USkullMenu_TextButtonWidget::Initialize()
{
	if (!Super::Initialize())
		return false;
	if (!Button)
		return false;

	Button->OnClicked.AddUniqueDynamic(this, &USkullMenu_TextButtonWidget::OnButtonClicked);

	return true;
}

void USkullMenu_TextButtonWidget::SynchronizeProperties()
{
	Super::SynchronizeProperties();

	if (TextBlock)
		TextBlock->SetText(Text);
}

void USkullMenu_TextButtonWidget::SetText(const FText& InText)
{
	Text = InText;
	SynchronizeProperties();
}

void USkullMenu_TextButtonWidget::OnButtonClicked()
{
	OnClicked.Broadcast();
}