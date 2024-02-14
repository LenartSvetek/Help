// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RealtimeMeshActor.h"

#include "RealtimeMeshSimple.h"

#include "WorldGenNew.generated.h"

/**
 * 
 */
UCLASS()
class VOXELTEST_API AWorldGenNew : public ARealtimeMeshActor
{
	GENERATED_BODY()
private: 
	URealtimeMeshSimple* world;
	TObjectPtr<UMaterialInterface> ProceduralMaterial;

public:
	// Sets default values for this actor's properties
	AWorldGenNew();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
