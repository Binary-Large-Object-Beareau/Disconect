// Copyright Epic Games, Inc. All Rights Reserved.

#include "LearnDataAssetGameMode.h"
#include "LearnDataAssetCharacter.h"
#include "UObject/ConstructorHelpers.h"

ALearnDataAssetGameMode::ALearnDataAssetGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
