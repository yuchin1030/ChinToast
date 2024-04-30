
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

	// �� ������ ���� �ٲ� �޽� �����
	UPROPERTY(EditDefaultsOnly)
	TArray <USkeletalMesh*> bodys;

	// �տ� ��� ������ġ �Ž�
	UPROPERTY(EditDefaultsOnly)
	class UStaticMeshComponent* sandwich;

	// ����Ȯ�� �� �λ� �ִϸ�Ÿ��
	UPROPERTY(EditDefaultsOnly)
	TArray <UAnimMontage*> thanks;

	// FSM ���º���
	UPROPERTY(EditDefaultsOnly)
	ECustomerState state = ECustomerState::IDLE;

	// �ֹ��� ������ġ ������ ��� ����
	UPROPERTY(EditAnywhere)
	TArray<UStaticMesh*> recipe;

	// �� ����(�Ž� Ÿ��)
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
