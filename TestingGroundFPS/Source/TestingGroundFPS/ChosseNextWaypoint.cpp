// Fill out your copyright notice in the Description page of Project Settings.


#include "ChosseNextWaypoint.h"
#include "AIController.h"
#include "PatrollingGuard.h"
#include "BehaviorTree/BlackboardComponent.h"


EBTNodeResult::Type UChosseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {
	// todo protect empty ptr
	// notice that if a new AI is added, with Patrol Route not set, the system would crash because of PatrolPoints = NULL, and PatrolPoints[Index] would return an unexpected val.

	// get the patrol points
	auto AIControlledPawn = OwnerComp.GetAIOwner()->GetPawn();
	auto PatrollingGuard = Cast<APatrollingGuard>(AIControlledPawn);
	auto PatrolPoints = PatrollingGuard->PatrolPointsCPP;

	// set next waypoints
	auto BlackboardComp = OwnerComp.GetBlackboardComponent();
	auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);
	UE_LOG(LogTemp, Warning, TEXT("NextWaypoint idx is: %i"), Index);

	// cycle the index
	auto NextIndex = (Index + 1) % PatrolPoints.Num();
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);

	return EBTNodeResult::Succeeded;
}
