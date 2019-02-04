// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWayPoint.h"
#include "BehaviorTree/BlackboardComponent.h"

EBTNodeResult::Type UChooseNextWayPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{

	auto BlackBoardComp = OwnerComp.GetBlackboardComponent(); //get the blackboard component
	auto Index = BlackBoardComp->GetValueAsInt(IndexKey.SelectedKeyName); //get the name of the variable (key) that is linked
		//to index in the blackboard
	return EBTNodeResult::Succeeded;
}