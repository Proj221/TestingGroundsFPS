// Fill out your copyright notice in the Description page of Project Settings.

#include "InfiniteTerrain.h"
#include "NavMesh/NavMeshBoundsVolume.h"
#include "EngineUtils.h"
#include "ActorPool.h"

AInfiniteTerrain::AInfiniteTerrain() {
	NavMeshBoundsVolumePool = CreateDefaultSubobject<UActorPool>(FName("NavNeshBoundsVolumePool"));
}

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