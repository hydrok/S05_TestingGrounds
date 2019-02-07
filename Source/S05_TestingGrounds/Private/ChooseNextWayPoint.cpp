// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWayPoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "PatrollingGuard.h"

EBTNodeResult::Type UChooseNextWayPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	//Get Patrol Points
	auto AIController = OwnerComp.GetAIOwner();
	auto ControlledPawn = AIController->GetPawn();
	auto PatrollingGuard = Cast<APatrollingGuard>(ControlledPawn);
	auto PatrolPoints = PatrollingGuard->PatrolPointsCPP;

	//Set next wapyoint
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