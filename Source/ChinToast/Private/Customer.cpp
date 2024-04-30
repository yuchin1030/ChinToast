

#include "Customer.h"

ACustomer::ACustomer()
{
	PrimaryActorTick.bCanEverTick = true;



}

void ACustomer::BeginPlay()
{
	Super::BeginPlay();
	
	int32 ranNum = FMath::RandRange(0,2);

	GetMesh()->SetSkeletalMesh(bodys[ranNum]);
}

void ACustomer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	switch (state)
	{
	case ECustomerState::IDLE:
		Idle();
		break;
	case ECustomerState::MOVEIN:
		MoveIn();
		break;
	case ECustomerState::ORDER:
		Order();
		break;
	case ECustomerState::ORDERDELAY:
		Wait();
		break;
	case ECustomerState::CHECK:
		Check();
		break;
	case ECustomerState::PAYMENT:
		Payment();
		break;
	case ECustomerState::MOVEOUT:
		MoveOut();
		break;
	default:
		break;
	}
}

void ACustomer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACustomer::Idle()
{

}

void ACustomer::MoveIn()
{

}

void ACustomer::Order()
{

}

void ACustomer::Wait()
{

}

void ACustomer::Check()
{

}

void ACustomer::Payment()
{

}

void ACustomer::MoveOut()
{

}

