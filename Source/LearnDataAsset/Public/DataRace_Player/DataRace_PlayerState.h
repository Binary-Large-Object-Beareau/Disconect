
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "DataRace_PlayerState.generated.h"

/**
 * Let's start with some defaults
 */
UCLASS()
class LEARNDATAASSET_API ADataRace_PlayerState : public APlayerState
{
	GENERATED_BODY()
	
public:
	ADataRace_PlayerState();
	void BeginPlay();
};
