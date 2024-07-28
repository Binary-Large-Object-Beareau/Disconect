// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DataRace_GameMode.generated.h"

/**
 * 
 */
UCLASS()
class LEARNDATAASSET_API ADataRace_GameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "Network")
	static bool TestServerConnection(const FString& ServerAddress, int32 TimeoutInMs);

};
