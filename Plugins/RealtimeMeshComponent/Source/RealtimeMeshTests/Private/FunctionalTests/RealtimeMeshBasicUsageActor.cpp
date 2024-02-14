﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "FunctionalTests/RealtimeMeshBasicUsageActor.h"

#include "RealtimeMeshLibrary.h"
#include "RealtimeMeshSimple.h"
#include "Mesh/RealtimeMeshBasicShapeTools.h"
#include "Mesh/RealtimeMeshBuilder.h"
#include "Mesh/RealtimeMeshSimpleData.h"

static constexpr float BlendTime = 0.5f;

ARealtimeMeshBasicUsageActor::ARealtimeMeshBasicUsageActor()
	: LastColor(FLinearColor::Red)
	, CurrentColor(FLinearColor::Blue)
	, TimeRemaining(BlendTime)
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}


static void AppendBox(TRealtimeMeshBuilderLocal<uint16, FPackedNormal, FVector2DHalf, 1>& Builder, const FVector3f& BoxRadius, uint16 PolyGroup)
{	
	// Generate verts
	FVector3f BoxVerts[8];
	BoxVerts[0] = FVector3f(-BoxRadius.X, BoxRadius.Y, BoxRadius.Z);
	BoxVerts[1] = FVector3f(BoxRadius.X, BoxRadius.Y, BoxRadius.Z);
	BoxVerts[2] = FVector3f(BoxRadius.X, -BoxRadius.Y, BoxRadius.Z);
	BoxVerts[3] = FVector3f(-BoxRadius.X, -BoxRadius.Y, BoxRadius.Z);

	BoxVerts[4] = FVector3f(-BoxRadius.X, BoxRadius.Y, -BoxRadius.Z);
	BoxVerts[5] = FVector3f(BoxRadius.X, BoxRadius.Y, -BoxRadius.Z);
	BoxVerts[6] = FVector3f(BoxRadius.X, -BoxRadius.Y, -BoxRadius.Z);
	BoxVerts[7] = FVector3f(-BoxRadius.X, -BoxRadius.Y, -BoxRadius.Z);
	
	{ // Positive Z
		int32 V0 = Builder.AddVertex(BoxVerts[0])
			.SetNormalAndTangent(FVector3f(0.0f, 0.0f, 1.0f), FVector3f(0.0f, -1.0f, 0.0f))
			.SetTexCoords(FVector2f(0.0f, 0.0f))
			.GetIndex();

		int32 V1 = Builder.AddVertex(BoxVerts[1])
			.SetNormalAndTangent(FVector3f(0.0f, 0.0f, 1.0f), FVector3f(0.0f, -1.0f, 0.0f))
			.SetTexCoords(FVector2f(0.0f, 1.0f))
			.GetIndex();

		int32 V2 = Builder.AddVertex(BoxVerts[2])
			.SetNormalAndTangent(FVector3f(0.0f, 0.0f, 1.0f), FVector3f(0.0f, -1.0f, 0.0f))
			.SetTexCoords(FVector2f(1.0f, 1.0f))
			.GetIndex();

		int32 V3 = Builder.AddVertex(BoxVerts[3])
			.SetNormalAndTangent(FVector3f(0.0f, 0.0f, 1.0f), FVector3f(0.0f, -1.0f, 0.0f))
			.SetTexCoords(FVector2f(1.0f, 0.0f))
			.GetIndex();

		Builder.AddTriangle(V0, V1, V3, PolyGroup);
		Builder.AddTriangle(V1, V2, V3, PolyGroup);		
	}

	{ // Negative X
		int32 V0 = Builder.AddVertex(BoxVerts[4])
			.SetNormalAndTangent(FVector3f(-1.0f, 0.0f, 0.0f), FVector3f(0.0f, -1.0f, 0.0f))
			.SetTexCoords(FVector2f(0.0f, 0.0f))
			.GetIndex();

		int32 V1 = Builder.AddVertex(BoxVerts[0])
			.SetNormalAndTangent(FVector3f(-1.0f, 0.0f, 0.0f), FVector3f(0.0f, -1.0f, 0.0f))
			.SetTexCoords(FVector2f(0.0f, 1.0f))
			.GetIndex();

		int32 V2 = Builder.AddVertex(BoxVerts[3])
			.SetNormalAndTangent(FVector3f(-1.0f, 0.0f, 0.0f), FVector3f(0.0f, -1.0f, 0.0f))
			.SetTexCoords(FVector2f(1.0f, 1.0f))
			.GetIndex();

		int32 V3 = Builder.AddVertex(BoxVerts[7])
			.SetNormalAndTangent(FVector3f(-1.0f, 0.0f, 0.0f), FVector3f(0.0f, -1.0f, 0.0f))
			.SetTexCoords(FVector2f(1.0f, 0.0f))
			.GetIndex();

		Builder.AddTriangle(V0, V1, V3, PolyGroup);
		Builder.AddTriangle(V1, V2, V3, PolyGroup);		
	}

	{ // Positive Y
		int32 V0 = Builder.AddVertex(BoxVerts[5])
			.SetNormalAndTangent(FVector3f(0.0f, 1.0f, 0.0f), FVector3f(-1.0f, 0.0f, 0.0f))
			.SetTexCoords(FVector2f(0.0f, 0.0f))
			.GetIndex();

		int32 V1 = Builder.AddVertex(BoxVerts[1])
			.SetNormalAndTangent(FVector3f(0.0f, 1.0f, 0.0f), FVector3f(-1.0f, 0.0f, 0.0f))
			.SetTexCoords(FVector2f(0.0f, 1.0f))
			.GetIndex();

		int32 V2 = Builder.AddVertex(BoxVerts[0])
			.SetNormalAndTangent(FVector3f(0.0f, 1.0f, 0.0f), FVector3f(-1.0f, 0.0f, 0.0f))
			.SetTexCoords(FVector2f(1.0f, 1.0f))
			.GetIndex();

		int32 V3 = Builder.AddVertex(BoxVerts[4])
			.SetNormalAndTangent(FVector3f(0.0f, 1.0f, 0.0f), FVector3f(-1.0f, 0.0f, 0.0f))
			.SetTexCoords(FVector2f(1.0f, 0.0f))
			.GetIndex();

		Builder.AddTriangle(V0, V1, V3, PolyGroup);
		Builder.AddTriangle(V1, V2, V3, PolyGroup);		
	}

	{ // Positive X
		int32 V0 = Builder.AddVertex(BoxVerts[6])
			.SetNormalAndTangent(FVector3f(1.0f, 0.0f, 0.0f), FVector3f(0.0f, 1.0f, 0.0f))
			.SetTexCoords(FVector2f(0.0f, 0.0f))
			.GetIndex();

		int32 V1 = Builder.AddVertex(BoxVerts[2])
			.SetNormalAndTangent(FVector3f(1.0f, 0.0f, 0.0f), FVector3f(0.0f, 1.0f, 0.0f))
			.SetTexCoords(FVector2f(0.0f, 1.0f))
			.GetIndex();

		int32 V2 = Builder.AddVertex(BoxVerts[1])
			.SetNormalAndTangent(FVector3f(1.0f, 0.0f, 0.0f), FVector3f(0.0f, 1.0f, 0.0f))
			.SetTexCoords(FVector2f(1.0f, 1.0f))
			.GetIndex();

		int32 V3 = Builder.AddVertex(BoxVerts[5])
			.SetNormalAndTangent(FVector3f(1.0f, 0.0f, 0.0f), FVector3f(0.0f, 1.0f, 0.0f))
			.SetTexCoords(FVector2f(1.0f, 0.0f))
			.GetIndex();

		Builder.AddTriangle(V0, V1, V3, PolyGroup);
		Builder.AddTriangle(V1, V2, V3, PolyGroup);		
	}

	{ // Negative Y
		int32 V0 = Builder.AddVertex(BoxVerts[7])
			.SetNormalAndTangent(FVector3f(0.0f, -1.0f, 0.0f), FVector3f(1.0f, 0.0f, 0.0f))
			.SetTexCoords(FVector2f(0.0f, 0.0f))
			.GetIndex();

		int32 V1 = Builder.AddVertex(BoxVerts[3])
			.SetNormalAndTangent(FVector3f(0.0f, -1.0f, 0.0f), FVector3f(1.0f, 0.0f, 0.0f))
			.SetTexCoords(FVector2f(0.0f, 1.0f))
			.GetIndex();

		int32 V2 = Builder.AddVertex(BoxVerts[2])
			.SetNormalAndTangent(FVector3f(0.0f, -1.0f, 0.0f), FVector3f(1.0f, 0.0f, 0.0f))
			.SetTexCoords(FVector2f(1.0f, 1.0f))
			.GetIndex();

		int32 V3 = Builder.AddVertex(BoxVerts[6])
			.SetNormalAndTangent(FVector3f(0.0f, -1.0f, 0.0f), FVector3f(1.0f, 0.0f, 0.0f))
			.SetTexCoords(FVector2f(1.0f, 0.0f))
			.GetIndex();

		Builder.AddTriangle(V0, V1, V3, PolyGroup);
		Builder.AddTriangle(V1, V2, V3, PolyGroup);		
	}

	{ // Negative Z
		int32 V0 = Builder.AddVertex(BoxVerts[7])
			.SetNormalAndTangent(FVector3f(0.0f, 0.0f, -1.0f), FVector3f(0.0f, 1.0f, 0.0f))
			.SetTexCoords(FVector2f(0.0f, 0.0f))
			.GetIndex();

		int32 V1 = Builder.AddVertex(BoxVerts[6])
			.SetNormalAndTangent(FVector3f(0.0f, 0.0f, -1.0f), FVector3f(0.0f, 1.0f, 0.0f))
			.SetTexCoords(FVector2f(0.0f, 1.0f))
			.GetIndex();

		int32 V2 = Builder.AddVertex(BoxVerts[5])
			.SetNormalAndTangent(FVector3f(0.0f, 0.0f, -1.0f), FVector3f(0.0f, 1.0f, 0.0f))
			.SetTexCoords(FVector2f(1.0f, 1.0f))
			.GetIndex();

		int32 V3 = Builder.AddVertex(BoxVerts[4])
			.SetNormalAndTangent(FVector3f(0.0f, 0.0f, -1.0f), FVector3f(0.0f, 1.0f, 0.0f))
			.SetTexCoords(FVector2f(1.0f, 0.0f))
			.GetIndex();

		Builder.AddTriangle(V0, V1, V3, PolyGroup);
		Builder.AddTriangle(V1, V2, V3, PolyGroup);		
	}
}


void ARealtimeMeshBasicUsageActor::OnGenerateMesh_Implementation()
{
	Super::OnGenerateMesh_Implementation();

	// Initialize the simple mesh
	URealtimeMeshSimple* RealtimeMesh = GetRealtimeMeshComponent()->InitializeRealtimeMesh<URealtimeMeshSimple>();

	FRealtimeMeshStreamSet StreamSet;
	TRealtimeMeshBuilderLocal<uint16, FPackedNormal, FVector2DHalf, 1> Builder(StreamSet);
	Builder.EnableTangents();
	Builder.EnableTexCoords();
	Builder.EnablePolyGroups();
	Builder.EnableColors();
	
	// This example create 3 rectangular prisms, one on each axis, with all
	// of them sharing a single set of buffers, but using separate sections for separate materials
	AppendBox(Builder, FVector3f(100, 100, 200), 0);
	AppendBox(Builder, FVector3f(200, 100, 100), 1);
	AppendBox(Builder, FVector3f(100, 200, 100), 2);	

	// Setup the two material slots
	RealtimeMesh->SetupMaterialSlot(0, "PrimaryMaterial");
	RealtimeMesh->SetupMaterialSlot(1, "SecondaryMaterial");

	const FRealtimeMeshSectionGroupKey GroupKey = FRealtimeMeshSectionGroupKey::Create(0, FName("TestBox"));
	
	// This will create a new section group named "TestBox" at LOD 0, with the created stream data above. This will create the sections associated with the polygroup
	RealtimeMesh->CreateSectionGroup(GroupKey, StreamSet);

	// By default the sections created by the poly group id can be referenced through a key setup this way
	const FRealtimeMeshSectionKey PolyGroup0Key = FRealtimeMeshSectionKey::CreateForPolyGroup(GroupKey, 0);
	const FRealtimeMeshSectionKey PolyGroup1Key = FRealtimeMeshSectionKey::CreateForPolyGroup(GroupKey, 1);
	const FRealtimeMeshSectionKey PolyGroup2Key = FRealtimeMeshSectionKey::CreateForPolyGroup(GroupKey, 2);

	// So you can adjust the config of a section through that key, so here we'll move PolyGroup 0 to point at MaterialSlot 0 as we don't have a material slot 3 setup here.

	RealtimeMesh->UpdateSectionConfig(PolyGroup0Key, RealtimeMesh->GetSectionConfig(PolyGroup0Key), true);
	RealtimeMesh->UpdateSectionConfig(PolyGroup1Key, RealtimeMesh->GetSectionConfig(PolyGroup1Key), true);
	RealtimeMesh->UpdateSectionConfig(PolyGroup2Key, FRealtimeMeshSectionConfig(ERealtimeMeshSectionDrawType::Static, 0), true);

	// Setup simple collision shape for this mesh
	FRealtimeMeshSimpleGeometry SimpleGeometry = RealtimeMesh->GetSimpleGeometry();
	SimpleGeometry.AddBox(FRealtimeMeshCollisionBox(FVector(200, 200, 400)));
	SimpleGeometry.AddBox(FRealtimeMeshCollisionBox(FVector(400, 200, 200)));
	SimpleGeometry.AddBox(FRealtimeMeshCollisionBox(FVector(200, 400, 200)));
	RealtimeMesh->SetSimpleGeometry(SimpleGeometry);
	
	FRealtimeMeshCollisionConfiguration CollisionConfig;
	CollisionConfig.bUseComplexAsSimpleCollision = false;
	RealtimeMesh->SetCollisionConfig(CollisionConfig);
	
}

void ARealtimeMeshBasicUsageActor::TickActor(float DeltaTime, ELevelTick TickType, FActorTickFunction& ThisTickFunction)
{
	if (URealtimeMeshSimple* RealtimeMesh = GetRealtimeMeshComponent()->GetRealtimeMeshAs<URealtimeMeshSimple>())
	{
		// By default the sections created by the poly group id can be referenced through a key setup this way
		const FRealtimeMeshSectionGroupKey GroupKey = FRealtimeMeshSectionGroupKey::Create(0, FName("TestBox"));

		// Update current color
		TimeRemaining -= DeltaTime;
		if (TimeRemaining < 0.0f)
		{
			TimeRemaining = BlendTime;
			LastColor = CurrentColor;
			CurrentColor = FLinearColor(FMath::FRand(), FMath::FRand(), FMath::FRand());
		}

		const FColor ThisFrameColor = FMath::Lerp(LastColor, CurrentColor, 1.0f - (TimeRemaining / BlendTime)).ToFColor(false);
		
		// Option one, We can update the color stream directly on the mesh	
		RealtimeMesh->EditMeshInPlace(GroupKey, [ThisFrameColor](FRealtimeMeshStreamSet& StreamSet)
		{
			TRealtimeMeshStreamBuilder<FColor> Colors(StreamSet.FindChecked(FRealtimeMeshStreams::Color));

			constexpr int32 TotalNumVertices = 24 * 3; // 3 boxes with 24 verts each
			
			for (int32 Index = 0; Index < TotalNumVertices; Index++)
			{
				Colors[Index] = ThisFrameColor;
			}

			return TSet { FRealtimeMeshStreams::Color };
		});

		
		// Option two, we create a new stream set, initialize a new color stream, set the data and pass that into the RMC to replace the existing.
		/*
		FRealtimeMeshStreamSet StreamSet;
		TRealtimeMeshStreamBuilder<FColor> Colors(*StreamSet.AddStream(FRealtimeMeshStreams::Color, GetRealtimeMeshBufferLayout<FColor>()));
		
		constexpr int32 TotalNumVertices = 24 * 3; // 3 boxes with 24 verts each
		Colors.SetNumUninitialized(TotalNumVertices);
		for (int32 Index = 0; Index < TotalNumVertices; Index++)
		{
			Colors[Index] = ThisFrameColor;
		}

		// Pass it the update stream set. You can pass by r-value or l-value so you either give it your data, or it copies your data.
		RealtimeMesh->UpdateSectionGroup(GroupKey, MoveTemp(StreamSet));
		*/

		
		
		Super::TickActor(DeltaTime, TickType, ThisTickFunction);
	}
}

