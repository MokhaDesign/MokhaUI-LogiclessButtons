// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonButtonBase.h"
#include "Blueprint/IUserObjectListEntry.h"
#include "ListButton.generated.h"

class UCommonLazyImage;
class UButtonCommand;
class UCommonButtonInternalBase;
class UCommonTextBlock;
/**
 * 
 */
UCLASS()
class LOGICLESSBUTTONS_API UListButton : public UCommonButtonBase, public IUserObjectListEntry
{
	GENERATED_BODY()

protected:
	virtual void NativeOnCurrentTextStyleChanged() override;

	UPROPERTY(meta = (BindWidget, OptionalWidget))
	UCommonTextBlock* ButtonLabel;

	UPROPERTY(meta = (BindWidget, OptionalWidget))
	UCommonLazyImage* ButtonIcon;

	virtual void NativeOnListItemObjectSet(UObject* ListItemObject) override;

private:
	UPROPERTY()
	UButtonCommand* ButtonCommand;

	TWeakObjectPtr<UCommonButtonInternalBase> ButtonRoot;

protected:
	virtual void NativePreConstruct() override;
};
