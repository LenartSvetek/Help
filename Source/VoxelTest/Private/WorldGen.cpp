// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldGen.h"

// Sets default values
AWorldGen::AWorldGen()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	
	world = CreateDefaultSubobject<URealtimeMeshSimple>("RMC");
}

// Called when the game starts or when spawned
void AWorldGen::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWorldGen::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

