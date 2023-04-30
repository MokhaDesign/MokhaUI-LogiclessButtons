// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ButtonCommand.generated.h"

class UCommonActivatableWidget;
/**
 * 
 */
UCLASS(Blueprintable, Meta = (ShowWorldContextPin))
class LOGICLESSBUTTONS_API UButtonCommand : public UObject
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintCallable, BlueprintPure, meta=(CompactNodeTitle="GameInstance"),
		Category="Mokha UI|Command Button")
	UGameInstance* GetGameInstance();

public:
	UFUNCTION(BlueprintNativeEvent, Category="Mokha UI|Command Button")
	void OnCommandConstructedFromList(UButtonListView* List, int Index);

	UFUNCTION(BlueprintNativeEvent, Category="Mokha UI|Command Button")
	void OnButtonClicked();

	UFUNCTION(BlueprintNativeEvent, Category="Mokha UI|Command Button")
	void OnButtonReleased();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mokha UI|Command Button")
	FString ButtonLabel = "Click Me";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mokha UI|Command Button")
	UTexture2D* ButtonIcon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mokha UI|Command Button")
	bool bPushToStack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Mokha UI|Command Button")
	TSubclassOf<UCommonActivatableWidget> WidgetToPush;
};
