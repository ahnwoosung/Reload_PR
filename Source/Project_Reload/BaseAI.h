// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "BaseAI.generated.h"

UCLASS()
class PROJECT_RELOAD_API ABaseAI : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABaseAI();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat")
		int32 hp;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat")
		int32 speed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stat")
		float time;

	// �ݴ���ѵ� �������ϰ� x, y �ݴ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ShotSetting")
		float maxX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ShotSetting")
		float maxY;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ShotSetting")
		float curX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ShotSetting")
		float curY;

	// ����ϱ�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ShotSetting")
		bool shot;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	UFUNCTION(BlueprintCallable, Category = "Speed")
	void SetAISpeed();

	UFUNCTION(BlueprintCallable, Category = "Attack")
	void ShotAI();
};
