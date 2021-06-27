// Fill out your copyright notice in the Description page of Project Settings.

#include "InfiniteTerrain.h"
#include "NavMesh/NavMeshBoundsVolume.h"
#include "EngineUtils.h"

void AInfiniteTerrain::PopulateBoundsVolumePool() {
	TActorIterator<ANavMeshBoundsVolume> VolumeIterator = TActorIterator<ANavMeshBoundsVolume>(GetWorld());
	while (VolumeIterator) {
		AddToPool(*VolumeIterator);
		++VolumeIterator;
	}
}

void AInfiniteTerrain::AddToPool(ANavMeshBoundsVolume* VolumeToAdd) {
	UE_LOG(LogTemp, Warning, TEXT("Found Actor: %s"), *VolumeToAdd->GetName());
}