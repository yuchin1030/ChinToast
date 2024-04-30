
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Customer.generated.h"

UENUM(BlueprintType)
enum class ECustomerState : uint8
{
	IDLE		UMETA(DisplayName = "Idle State"),
	MOVEIN		UMETA(DisplayName = "Move In State"),
	ORDER		UMETA(DisplayName = "Order State"),
	ORDERDELAY	UMETA(DisplayName = "Order Delay State"),
	CHECK		UMETA(DisplayName = "Check State"),
	PAYMENT		UMETA(DisplayName = "Pay State"),
	MOVEOUT		UMETA(DisplayName = "Move Out State"),
};
UCLASS()
class CHINTOAST_API ACustomer : public ACharacter
{
	GENERATED_BODY()

public:
	ACustomer();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// 고객 종류에 따라 바뀔 메쉬 저장용
	UPROPERTY(EditDefaultsOnly)
	TArray <USkeletalMesh*> bodys;

	// 손에 들고갈 샌드위치 매쉬
	UPROPERTY(EditDefaultsOnly)
	class UStaticMeshComponent* sandwich;

	// 수령확인 후 인사 애니몽타주
	UPROPERTY(EditDefaultsOnly)
	TArray <UAnimMontage*> thanks;

	// FSM 상태변수
	UPROPERTY(EditDefaultsOnly)
	ECustomerState state = ECustomerState::IDLE;

	// 주문할 샌드위치 레시피 재료 순서
	UPROPERTY(EditAnywhere)
	TArray<UStaticMesh*> recipe;

	// 고객 종류(매쉬 타입)
	UPROPERTY(EditAnywhere)
	int32 customerType = 0;

private:

	float ticktime = 0.0f;
	
	void Idle();
	void MoveIn();
	void Order();
	void Wait();
	void Check();
	void Payment();
	void MoveOut();
};
