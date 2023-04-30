// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonListView.h"
#include "ButtonListView.generated.h"

class UCommonActivatableWidget;
class UCommonActivatableWidgetStack;
class UButtonCommand;
/**
 * 
 */
UCLASS()
class LOGICLESSBUTTONS_API UButtonListView : public UCommonListView
{
	GENERATED_BODY()

protected:
	virtual void OnWidgetRebuilt() override;

public:
#if WITH_EDITOR
	virtual const FText GetPaletteCategory() override;
#endif

	void SpawnButtons();
	void SetupStack();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Button List")
	TArray<TSubclassOf<UButtonCommand>> ButtonCommands;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="Add Back Button"), Category="Button List|Back Button")
	bool bAddBackButton;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Button List|Back Button")
	FText BackButtonLabel;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(DisplayName="Push to Internal Stack"),
		Category="Button List|Internal Stack Mode")
	bool bPushToInternalStack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(DisplayName="Internal Stack"),
		Category="Button List|Internal Stack Mode")
	UCommonActivatableWidgetStack* InternalStackToPushTo;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta=(DisplayName="Push to External Stack"),
		Category="Button List|External Stack Mode")
	bool bPushToExternalStack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Button List|External Stack Mode")
	FName ExternalStackDisplayName;

	UPROPERTY()
	UCommonActivatableWidgetStack* StackToPushTo;
	
protected:
	UFUNCTION(BlueprintCallable, Category="Mokha UI|Command List View")
	UCommonActivatableWidgetStack* SetStackToPushTo(UCommonActivatableWidgetStack* Stack);

	UFUNCTION(Category="Mokha UI|Command List View")
	UCommonActivatableWidgetStack* SetExternalStack() const;
};