// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Mynpc.generated.h"

DECLARE_MULTICAST_DELEGATE(FOnAttackEnd);

UCLASS()
class NPC_API AMynpc : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMynpc();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void PostInitializeComponents() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void Attack();
	void AttackCheck();

	FOnAttackEnd OnAttackEnd;

	void UpDown(float Value);
	void LeftRight(float Value);
	void Yaw(float Value);

	UFUNCTION()
	void OnAttackMontageEnded(class UAnimMontage* Montage, bool binterrupted);

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;
private:
	UPROPERTY(VisibleAnywhere)
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
	class UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, Category = Pawn)
	bool IsAttacking = false;

	UPROPERTY()
	class UnpcAnimInstance* AnimInstance;

public:
	UPROPERTY()
	float UpDownValue = 0;

	UPROPERTY()
	float LeftRightValue = 0;

	UPROPERTY(VisibleAnywhere)
	class UMyStatComponent* Stat;
};
