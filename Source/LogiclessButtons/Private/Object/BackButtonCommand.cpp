// Fill out your copyright notice in the Description page of Project Settings.


#include "Object/BackButtonCommand.h"

#include "Widgets/ButtonListView.h"
#include "Widgets/CommonActivatableWidgetContainer.h"
#include "CommonUI/Public/CommonActivatableWidget.h"

void UBackButtonCommand::OnButtonClicked_Implementation()
{
	if (bPushToStack)
	{
		if (const UButtonListView* ButtonList = Cast<UButtonListView>(this->GetOuter()))
		{
			
			if (
				(ButtonList->bPushToInternalStack || ButtonList->bPushToExternalStack)
				&& ButtonList->StackToPushTo != nullptr)
			{
				ButtonList->StackToPushTo->GetActiveWidget()->DeactivateWidget();
			}
		}
	}
}
