// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWayPoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrolRoute.h"

EBTNodeResult::Type UChooseNextWayPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//Get Patrol Points
	auto AIController = OwnerComp.GetAIOwner();
	auto ControlledPawn = AIController->GetPawn();
	auto PatrolRoute = ControlledPawn->FindComponentByClass<UPatrolRoute>();

	if (!ensure(PatrolRoute)) {  return EBTNodeResult::Failed;  }

	auto PatrolPoints = PatrolRoute->GetPatrolPoints();
	if (PatrolPoints.Num() == 0) 
	{
		UE_LOG(LogTemp, Warning, TEXT("A guard is missing patrol points"))  
		return EBTNodeResult::Failed;
	}

	//Set next waypoint
	auto BlackBoardComp = OwnerComp.GetBlackboardComponent(); //get the blackboard component
	auto Index = BlackBoardComp->GetValueAsInt(IndexKey.SelectedKeyName); //get the name of the variable (key) that is linked
		//to index in the blackboard and then get its value as int.
	BlackBoardComp->SetValueAsObject(WayPointKey.SelectedKeyName, PatrolPoints[Index]); //the selected name is selected in UE4 blackboard

	//Cycle through Index
	//increment index by 1 get length patrol points (PatrolPoints.num), mod
	auto NextIndex = (Index + 1) % PatrolPoints.Num();
	//set blackboard value as int, key = index
	BlackBoardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);

	return EBTNodeResult::Succeeded;
}