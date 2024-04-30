

#include "Customer.h"

ACustomer::ACustomer()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ACustomer::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACustomer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACustomer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

