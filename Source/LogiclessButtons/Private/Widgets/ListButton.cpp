// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/ListButton.h"

#include "CommonLazyImage.h"
#include "CommonTextBlock.h"
#include "Object/ButtonCommand.h"

void UListButton::NativeOnCurrentTextStyleChanged()
{
	Super::NativeOnCurrentTextStyleChanged();
	if (ButtonLabel)
	{
		ButtonLabel->SetStyle(GetCurrentTextStyleClass());
	}
}

void UListButton::NativeOnListItemObjectSet(UObject* ListItemObject)
{
	IUserObjectListEntry::NativeOnListItemObjectSet(ListItemObject);
	
	ButtonCommand = Cast<UButtonCommand>(ListItemObject);
	
	if (ButtonCommand && ButtonRoot.IsValid())
	{
		ButtonRoot->OnClicked.AddUniqueDynamic(ButtonCommand, &UButtonCommand::OnButtonClicked);
		ButtonRoot->OnReleased.AddUniqueDynamic(ButtonCommand, &UButtonCommand::OnButtonReleased);

		if(ButtonLabel)
		{
			const FText ButtonText = FText::FromString(ButtonCommand->ButtonLabel);
			ButtonLabel->SetText(ButtonText);
		}

		if(ButtonIcon && ButtonCommand->ButtonIcon)
			ButtonIcon->SetBrushFromTexture(ButtonCommand->ButtonIcon);
		else if (ButtonIcon)
			ButtonIcon->SetVisibility(ESlateVisibility::Collapsed);

	}
}


void UListButton::NativePreConstruct()
{
	Super::NativePreConstruct();

	ButtonRoot = Cast<UCommonButtonInternalBase>(this->GetRootWidget());
}
