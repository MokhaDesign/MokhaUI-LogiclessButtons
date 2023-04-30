// Fill out your copyright notice in the Description page of Project Settings.


#include "Object/ButtonCommand.h"

#include "Widgets/ButtonListView.h"
#include "Widgets/CommonActivatableWidgetContainer.h"
#include "CommonUI/Public/CommonActivatableWidget.h"

UGameInstance* UButtonCommand::GetGameInstance()
{
	return GetWorld()->GetGameInstance();
}

void UButtonCommand::OnButtonClicked_Implementation()
{
	if (bPushToStack)
	{
		if (const UButtonListView* ButtonList = Cast<UButtonListView>(this->GetOuter()))
		{
			if (
				(ButtonList->bPushToInternalStack || ButtonList->bPushToExternalStack)
				&& ButtonList->StackToPushTo != nullptr)
			{
				ButtonList->StackToPushTo->AddWidget(WidgetToPush);
			}
		}
	}
}

void UButtonCommand::OnButtonReleased_Implementation()
{
}

void UButtonCommand::OnCommandConstructedFromList_Implementation(UButtonListView* List, int Index)
{
	
}
