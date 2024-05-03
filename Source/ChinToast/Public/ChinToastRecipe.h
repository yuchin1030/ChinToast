// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ChinToastRecipe.generated.h"

UCLASS()
class CHINTOAST_API AChinToastRecipe : public AActor
{
	GENERATED_BODY()
	
public:	
	AChinToastRecipe();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	TMap<FString, UStaticMesh*> ingredients; 

	TArray<FString> makedRecipe;
	TArray<FString> recipe1;
	TArray<FString> recipe2;
	TArray<FString> recipe3;
	TArray<FString> recipe4;
	TArray<FString> recipe5;

	UStaticMesh* GetRecipe(FString metarialname);
	void SetRandomMenu();

	
};
