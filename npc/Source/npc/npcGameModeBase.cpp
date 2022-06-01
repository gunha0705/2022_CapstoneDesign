// Copyright Epic Games, Inc. All Rights Reserved.


#include "npcGameModeBase.h"
#include "Mynpc.h"

AnpcGameModeBase::AnpcGameModeBase()
{
	DefaultPawnClass = AMynpc::StaticClass();

	static ConstructorHelpers::FClassFinder<ACharacter> BP_Char(TEXT("Blueprint'/Game/Blueprints/BP_Mynpc.BP_Mynpc_C'"));

	if (BP_Char.Succeeded())
	{
		DefaultPawnClass = BP_Char.Class;
	}
}

