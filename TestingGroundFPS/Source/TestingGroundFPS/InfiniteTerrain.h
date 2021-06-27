// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TestingGroundFPSGameMode.h"
#include "InfiniteTerrain.generated.h"

/**
 * 
 */
UCLASS()
class TESTINGGROUNDFPS_API AInfiniteTerrain : public ATestingGroundFPSGameMode
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Bounds Pool")
	void PopulateBoundsVolumePool();

private:
	void AddToPool(class ANavMeshBoundsVolume* VolumeToAdd);
	
};
