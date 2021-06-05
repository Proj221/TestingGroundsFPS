// Fill out your copyright notice in the Description page of Project Settings.


#include "ChosseNextWaypoint.h"
#include "AIController.h"
#include "PatrolRoute.h"
#include "BehaviorTree/BlackboardComponent.h"


EBTNodeResult::Type UChosseNextWaypoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) {
	// notice that if a new AI is added, with Patrol Route not set, the system would crash because of PatrolPoints = NULL, and PatrolPoints[Index] would return an unexpected val.

	// get the patrol points
	auto AIControlledPawn = OwnerComp.GetAIOwner()->GetPawn();
	auto PatrolRoute = AIControlledPawn->FindComponentByClass<UPatrolRoute>();

	if (!ensure(PatrolRoute)) {
		return EBTNodeResult::Failed;
	}

	// protect no patrol route component
	auto PatrolPoints = PatrolRoute->GetPatrolPoints();

	if (PatrolPoints.Num() == 0) {
		UE_LOG(LogTemp, Warning, TEXT("The AI has no patrol points"));
		return EBTNodeResult::Failed;
	}

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
