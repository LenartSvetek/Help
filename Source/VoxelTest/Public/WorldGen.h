// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "RealtimeMeshSimple.h"

#include "WorldGen.generated.h"


UCLASS()
class VOXELTEST_API AWorldGen : public AActor
{
	GENERATED_BODY()
	
	URealtimeMeshSimple* world;
	
public:	
	// Sets default values for this actor's properties
	AWorldGen();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
