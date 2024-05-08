// Fill out your copyright notice in the Description page of Project Settings.


#include "ChinToastRecipe.h"
#include <../../../../../../../Source/Runtime/Engine/Classes/Kismet/KismetArrayLibrary.h>

// Sets default values
AChinToastRecipe::AChinToastRecipe()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ConstructorHelpers::FObjectFinder<UStaticMesh> Bread(TEXT("/Script/Engine.StaticMesh'/Game/Yuchin/YC_Assets/Sandwich_Pieces/Need/Bread.Bread'"));
	ConstructorHelpers::FObjectFinder<UStaticMesh> Cheese(TEXT("/Script/Engine.StaticMesh'/Game/Yuchin/YC_Assets/Sandwich_Pieces/Need/Cheese.Cheese'"));
	ConstructorHelpers::FObjectFinder<UStaticMesh> BigHam(TEXT("/Script/Engine.StaticMesh'/Game/Yuchin/YC_Assets/Sandwich_Pieces/Need/Ham.Ham'"));
	ConstructorHelpers::FObjectFinder<UStaticMesh> Hams(TEXT("/Script/Engine.StaticMesh'/Game/Yuchin/YC_Assets/Sandwich_Pieces/Need/Ham3.Ham3'"));
	ConstructorHelpers::FObjectFinder<UStaticMesh> Lettuce(TEXT("/Script/Engine.StaticMesh'/Game/Yuchin/YC_Assets/Sandwich_Pieces/Need/Lettuce.Lettuce'"));
	ConstructorHelpers::FObjectFinder<UStaticMesh> Tomato(TEXT("/Script/Engine.StaticMesh'/Game/Yuchin/YC_Assets/Sandwich_Pieces/Need/Tomato.Tomato'"));

	if (Bread.Succeeded())
	{
		ingredients.Add(TEXT("Bread"), Bread.Object);
	}
	if (Cheese.Succeeded())
	{
		ingredients.Add(TEXT("Cheese"), Cheese.Object);
	}
	if (BigHam.Succeeded())
	{
		ingredients.Add(TEXT("BigHam"), BigHam.Object);
	}
	if (Hams.Succeeded())
	{
		ingredients.Add(TEXT("Hams"), Hams.Object);
	}
	if (Lettuce.Succeeded())
	{
		ingredients.Add(TEXT("Lettuce"), Lettuce.Object);
	}
	if (Tomato.Succeeded())
	{
		ingredients.Add(TEXT("Tomato"), Tomato.Object);
	}

	ConstructorHelpers::FObjectFinder<UTexture> Breadimg(TEXT("/Script/Engine.Texture2D'/Game/Yuchin/UI/BreadImg.BreadImg'"));
	ConstructorHelpers::FObjectFinder<UTexture> Cheeseimg(TEXT("/Script/Engine.Texture2D'/Game/Yuchin/UI/CheeseImg.CheeseImg'"));
	ConstructorHelpers::FObjectFinder<UTexture> BigHamimg(TEXT("/Script/Engine.Texture2D'/Game/Yuchin/UI/BreadImg.BreadImg'"));
	ConstructorHelpers::FObjectFinder<UTexture> Hamsimg(TEXT("/Script/Engine.Texture2D'/Game/Yuchin/UI/HamImg.HamImg'"));
	ConstructorHelpers::FObjectFinder<UTexture> Lettuceimg(TEXT("/Script/Engine.Texture2D'/Game/Yuchin/UI/LettuceImg.LettuceImg'"));
	ConstructorHelpers::FObjectFinder<UTexture> Tomatoimg(TEXT("/Script/Engine.Texture2D'/Game/Yuchin/UI/TomatoImg.TomatoImg'"));

	if (Breadimg.Succeeded())
	{
		foodimage.Add(TEXT("Bread Image"), Breadimg.Object);
	}
	if (Cheeseimg.Succeeded())
	{
		foodimage.Add(TEXT("Cheese Image"), Cheeseimg.Object);
	}
	if (BigHamimg.Succeeded())
	{
		foodimage.Add(TEXT("BigHam Image"), BigHamimg.Object);
	}
	if (Hamsimg.Succeeded())
	{
		foodimage.Add(TEXT("Hams Image"), Hamsimg.Object);
	}
	if (Lettuceimg.Succeeded())
	{
		foodimage.Add(TEXT("Lettuce Image"), Lettuceimg.Object);
	}
	if (Tomatoimg.Succeeded())
	{
		foodimage.Add(TEXT("Tomato Image"), Tomatoimg.Object);
	}

	recipe1 = { "ChinToast", "Bread", "Hams", "Cheese", "Lettuce", "Bread"};
	recipe2 = { "TripleHamToast", "Bread", "BigHam", "BigHam", "BigHam", "Bread" };
	recipe3 = { "VeganToast", "Bread", "Lettuce", "Tomato", "Lettuce", "Bread" };
	recipe4 = { "DoubleCheeseToast", "Bread", "Hams", "Cheese", "Cheese", "Bread" };
	recipe5 = { "BLTToast", "Bread", "Hams", "Tomato", "Lettuce", "Bread" };
	recipe6 = { "MinToast", "Bread", "Bread", "Bread", "Bread", "Bread" };

}

// Called when the game starts or when spawned
void AChinToastRecipe::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AChinToastRecipe::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UStaticMesh* AChinToastRecipe::GetRecipe(FString metarialname)
{
	return ingredients[metarialname];
}

void AChinToastRecipe::SetRandomMenu()
{
	makedRecipe.Empty();
	int32 ramNum = FMath::RandRange(1, 5);
	UE_LOG(LogTemp, Warning, TEXT("%d"), ramNum);

	switch (ramNum)
	{
	case 1:
		for (int32 i = 0; i < recipe1.Num(); i++)
		{
			makedRecipe.Add(recipe1[i]);
		}
		break;
	case 2:
		for (int32 i = 0; i < recipe2.Num(); i++)
		{
			makedRecipe.Add(recipe2[i]);
		}
		break;
	case 3:
		for (int32 i = 0; i < recipe3.Num(); i++)
		{
			makedRecipe.Add(recipe3[i]);
		}
		break;
	case 4:
		for (int32 i = 0; i < recipe4.Num(); i++)
		{
			makedRecipe.Add(recipe4[i]);
		}
		break;
	case 5:
		for (int32 i = 0; i < recipe5.Num(); i++)
		{
			makedRecipe.Add(recipe5[i]);
		}
		break;
	default:
		break;
	}
}

