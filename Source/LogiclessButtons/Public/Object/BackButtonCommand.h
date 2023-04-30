// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Object/ButtonCommand.h"
#include "BackButtonCommand.generated.h"

/**
 * 
 */
UCLASS()
class LOGICLESSBUTTONS_API UBackButtonCommand : public UButtonCommand
{
	GENERATED_BODY()
	
	UBackButtonCommand()
	{
		bPushToStack = true;
		ButtonLabel = "Back";
	}	

public:
	virtual void OnButtonClicked_Implementation() override;
};