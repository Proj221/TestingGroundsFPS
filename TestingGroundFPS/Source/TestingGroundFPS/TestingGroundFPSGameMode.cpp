// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestingGroundFPSGameMode.h"
#include "TestingGroundFPSHUD.h"
#include "Player/FirstPersonCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATestingGroundFPSGameMode::ATestingGroundFPSGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Dynamic/a1_Character/Behavior/BP_Character"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = ATestingGroundFPSHUD::StaticClass();
}
