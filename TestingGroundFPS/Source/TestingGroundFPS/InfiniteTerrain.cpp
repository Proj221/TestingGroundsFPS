// Fill out your copyright notice in the Description page of Project Settings.

#include "InfiniteTerrain.h"
#include "NavMesh/NavMeshBoundsVolume.h"
#include "EngineUtils.h"
#include "ActorPool.h"

AInfiniteTerrain::AInfiniteTerrain() {
	NavMeshBoundsVolumePool = CreateDefaultSubobject<UActorPool>(FName("NavNeshBoundsVolumePool"));
}

void AInfiniteTerrain::PopulateBoundsVolumePool() {
	auto VolumeIterator = TActorIterator<ANavMeshBoundsVolume>(GetWorld());
	while (VolumeIterator) {
		AddToPool(*VolumeIterator);
		++VolumeIterator;
	}
}

void AInfiniteTerrain::AddToPool(ANavMeshBoundsVolume *VolumeToAdd) {
	
	NavMeshBoundsVolumePool->Add(VolumeToAdd);
}