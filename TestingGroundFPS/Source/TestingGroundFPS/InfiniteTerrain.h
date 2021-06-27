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
	AInfiniteTerrain();

	UFUNCTION(BlueprintCallable, Category = "Bounds Pool")
	void PopulateBoundsVolumePool();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "NavMeshBoundsVolumePool")
	class UActorPool* NavMeshBoundsVolumePool;

private:
	void AddToPool(class ANavMeshBoundsVolume* VolumeToAdd);
};
