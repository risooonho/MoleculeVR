// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "RuntimeMeshComponent.h"
#include "MeshImporter.h"
#include "NormalCalculator.h"
#include "MeshActorBase.generated.h"

UCLASS()
class MESHGENERATOR_API AMeshActorBase : public AActor
{
	GENERATED_BODY()
	
public:	
	UPROPERTY(EditAnywhere)
	URuntimeMeshComponent* RuntimeMesh;
	
	// Sets default values for this actor's properties
	AMeshActorBase();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Main creation method
	void CreateMesh(const char* path);

private:
	// Import Mesh from ply file
	void ImportMesh(const char* path);

	// Set Material to VertexColor to display vertex colors
	void SetVertexColorMaterial();

	TArray<FRuntimeMeshVertexSimple> Vertices;
	TArray<int32> Triangles;
};
