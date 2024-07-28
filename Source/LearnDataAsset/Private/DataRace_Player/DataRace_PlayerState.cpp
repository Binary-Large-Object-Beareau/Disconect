
#include "DataRace_Player/DataRace_PlayerState.h"


ADataRace_PlayerState::ADataRace_PlayerState()
{
	
}

void ADataRace_PlayerState::BeginPlay()
{
	Super::BeginPlay();

	UE_LOG(LogTemp,Warning,TEXT("I'm a player state!"));
}

