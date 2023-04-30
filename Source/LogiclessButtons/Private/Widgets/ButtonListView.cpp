// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/ButtonListView.h"

#include "Object/BackButtonCommand.h"
#include "Object/ButtonCommand.h"
#include "Widgets/CommonActivatableWidgetContainer.h"

void UButtonListView::OnWidgetRebuilt()
{
	Super::OnWidgetRebuilt();

	// Is there a better way?
	if (GetWorld()->IsGameWorld())
	{
		SetupStack();
		SpawnButtons();
	}
}

const FText UButtonListView::GetPaletteCategory()
{
	return NSLOCTEXT("MokhaUI", "WidgetPaletteCategory", "Mokha UI Plugin");
}

UCommonActivatableWidgetStack* UButtonListView::SetStackToPushTo(UCommonActivatableWidgetStack* Stack)
{
	StackToPushTo = Stack;

	return StackToPushTo;
}

UCommonActivatableWidgetStack* UButtonListView::SetExternalStack() const
{
	// Start Widget -> Widget Tree 
	UObject* CurrentObject = this->GetOuter();

	UCommonActivatableWidgetStack* FoundWidget = nullptr;

	while (FoundWidget == nullptr)
	{
		// Widget Tree -> Start Parent Widget -> Widget Tree Up 
		CurrentObject = CurrentObject->GetOuter()->GetOuter();

		if (!ExternalStackDisplayName.IsNone())
		{
			FoundWidget = Cast<UWidgetTree>(CurrentObject)->FindWidget<UCommonActivatableWidgetStack>(
				ExternalStackDisplayName);
		}

		else
		{
			Cast<UWidgetTree>(CurrentObject)->ForEachWidget([&](UWidget* Widget)
			{
				if (FoundWidget == nullptr)
				{
					FoundWidget = Cast<UCommonActivatableWidgetStack>(Widget);
				}
			});
		}
	}

	return FoundWidget;
}

void UButtonListView::SpawnButtons()
{
	this->ClearListItems();

	for (TSubclassOf<UButtonCommand> Command : ButtonCommands)
	{
		const UClass* CommandClass = Command;
		if (Command != nullptr)
		{
			UButtonCommand* CurrentCommand = NewObject<UButtonCommand>(this, CommandClass);
			CurrentCommand->OnCommandConstructedFromList(this, this->GetNumItems());
			this->AddItem(CurrentCommand);
		}
	}

	if (bAddBackButton)
	{
		UBackButtonCommand* BackButton = NewObject<UBackButtonCommand>(this, UBackButtonCommand::StaticClass());

		if (!BackButtonLabel.IsEmpty())
			BackButton->ButtonLabel = BackButtonLabel.ToString();

		BackButton->OnCommandConstructedFromList(this, this->GetNumItems());
		this->AddItem(BackButton);
	}
}

void UButtonListView::SetupStack()
{
	if (bPushToInternalStack)
		StackToPushTo = InternalStackToPushTo;

	if (bPushToExternalStack)
		StackToPushTo = SetExternalStack();
}
