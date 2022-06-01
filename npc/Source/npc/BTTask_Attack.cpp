// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Attack.h"
#include "MyAIController.h"
#include "Mynpc.h"

UBTTask_Attack::UBTTask_Attack()
{
	bNotifyTick = true;
}

EBTNodeResult::Type UBTTask_Attack::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);

	auto Mynpc = Cast<AMynpc>(OwnerComp.GetAIOwner()->GetPawn());
	if (Mynpc == nullptr)
		return EBTNodeResult::Failed;

	Mynpc->Attack();
	bIsAttacking = true;

	Mynpc->OnAttackEnd.AddLambda([this]()
		{
			bIsAttacking = false;
		});

	return Result;

}

void UBTTask_Attack::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

	if (bIsAttacking == false)
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
}