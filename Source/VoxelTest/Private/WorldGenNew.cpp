// Fill out your copyright notice in the Description page of Project Settings.


#include "WorldGenNew.h"

AWorldGenNew::AWorldGenNew() {
	
}

void AWorldGenNew::BeginPlay() {
	world = GetRealtimeMeshComponent()->InitializeRealtimeMesh<URealtimeMeshSimple>();
	world->SetupMaterialSlot(0, "MyMaterial", ProceduralMaterial);

	TArray<FVector3f> Vertices;
	TArray<uint32> Triangles;
	TArray<FVector2f> UV;

	constexpr int GridSize = 8;
	constexpr float CellSize = 200.0;

	for (int y = 0; y <= GridSize; y++)
	{
		for (int x = 0; x <= GridSize; x++)
		{
			const float XPos = x * CellSize;
			const float YPos = y * CellSize;
			const FVector3f vert = FVector3f(XPos, YPos, 0);
			const int vertIndex = Vertices.Num();
			Vertices.Add(vert);
			UV.Add(FVector2f(static_cast<float>(x) / CellSize, static_cast<float>(y) / CellSize));

			// If we're not on the last row or column, add a quad (two triangles)
			if (x < GridSize && y < GridSize)
			{
				Triangles.Add(vertIndex);
				Triangles.Add(vertIndex + GridSize + 1);
				Triangles.Add(vertIndex + 1);

				Triangles.Add(vertIndex + 1);
				Triangles.Add(vertIndex + GridSize + 1);
				Triangles.Add(vertIndex + GridSize + 2);
			}
		}
	}

	TArray<FVector3f> Tangents;
	Tangents.SetNum(Vertices.Num());
	TArray<FVector3f> Normals;
	Normals.SetNum(Vertices.Num());

	GEngine->AddOnScreenDebugMessage(1, 2, FColor::Green, TEXT("Generating Tangents..."));


	RealtimeMeshAlgo::GenerateTangents(TConstArrayView<uint32>(Triangles), TConstArrayView<FVector3f>(Vertices),
		[&](const int Index) { return UV[Index]; },
		[&](const int Index, const FVector3f Tangent, const FVector3f Normal)
		{
			Tangents[Index] = Tangent;
			Normals[Index] = Normal;
		}, true);

	FRealtimeMeshStreamSet StreamSet;
	TRealtimeMeshBuilderLocal <uint32, FPackedNormal, FVector2DHalf, 1> Builder(StreamSet);
	Builder.EnableColors();
	Builder.EnableTangents();
	Builder.EnablePolyGroups();
	Builder.EnableTexCoords();
	
	

	// I'm sure there's a way to work around this and just dump the existing TArrays in, I just don't know what it would be.
	for (int i = 0; i < Vertices.Num(); i++)
	{
		Builder.AddVertex(Vertices[i]).SetNormalAndTangent(Normals[i], Tangents[i]).SetTexCoords(UV[i]);
	}
	for (int t = 0; t < Triangles.Num(); t += 3)
	{
		Builder.AddTriangle(Triangles[t], Triangles[t + 1], Triangles[t + 2], 0);
	}

	const FRealtimeMeshSectionGroupKey SecGrpKey = FRealtimeMeshSectionGroupKey::Create(0, FName("Patch"));
	FRealtimeMeshSectionConfig SectionConfig = FRealtimeMeshSectionConfig(ERealtimeMeshSectionDrawType::Static, 0);
	SectionConfig.bIsVisible = true;

	world->CreateSectionGroup(SecGrpKey, StreamSet);
	world->UpdateSectionConfig(FRealtimeMeshSectionKey::CreateForPolyGroup(SecGrpKey, 0), SectionConfig, true);
	
}

void AWorldGenNew::Tick(float DeltaTime) {
}
