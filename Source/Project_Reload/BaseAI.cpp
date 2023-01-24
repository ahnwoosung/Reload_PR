// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseAI.h"
#include "DrawDebugHelpers.h"

// Sets default values
ABaseAI::ABaseAI() : hp(100), speed(100), time(0), maxX(10), maxY(10), shot(false)
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void ABaseAI::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ABaseAI::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABaseAI::SetAISpeed()
{
	UCharacterMovementComponent* characterMovement = GetCharacterMovement();
	characterMovement->MaxWalkSpeed = speed;
}

void ABaseAI::ShotAI()
{
	FVector loc;
	FRotator rot;
	FHitResult hit;

	GetController()->GetPlayerViewPoint(loc, rot);

	float x = 0, y = 0;

	x = FMath::RandRange(-curX, curX);
	y = FMath::RandRange(-curY, curY);

	FVector start = loc;
	FVector end = start + ((rot + FRotator(x, y, 0)).Vector() * 5000);
	FCollisionQueryParams traceParams;
	GetWorld()->LineTraceSingleByChannel(hit, start, end, ECC_Visibility, traceParams);

	DrawDebugLine(GetWorld(), start, end, FColor::Orange, false, 0.1f);

	if (hit.GetActor() != NULL)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, FString::Printf(TEXT("Name : %s"), *hit.GetComponent()->GetName()));
		if (hit.GetComponent()->GetName() != "CharacterMesh0")
		{
			if (curX > 0)
			{
				curX -= 1;
				curY -= 1;
			}
		}
		else
		{
			curX = maxX;
			curY = maxY;
		}
	}

	shot = true;
}

