// Fill out your copyright notice in the Description page of Project Settings.


#include "ChosseNextWaypoint.h"

EBTNodeResult::Type UChosseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {
	UE_LOG(LogTemp, Warning, TEXT("NextWaypoint in CPP"));
	return EBTNodeResult::Succeeded;
}
