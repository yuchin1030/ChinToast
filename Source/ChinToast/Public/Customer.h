
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
	UPROPERTY(EditDefaultsOnly, Category = "Setting")
	TArray <USkeletalMesh*> bodys;

	// �� ������ ���� �ٲ� ABP �����
	UPROPERTY(EditDefaultsOnly, Category = "Setting")
	TArray <UClass*> customerMoves;

	// �տ� ��� ������ġ �Ž�
	UPROPERTY(EditDefaultsOnly, Category = "Setting")
	class UStaticMeshComponent* sandwich;

	// ����Ȯ�� �� �λ� �ִϸ�Ÿ��
	UPROPERTY(EditDefaultsOnly, Category = "Setting")
	TArray <UAnimMontage*> thanks;

	// FSM ���º���
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Setting")
	ECustomerState state = ECustomerState::IDLE;

	// �ֹ��� ������ġ ������ ��� ����
	class AChinToastRecipe* recipe;

	UPROPERTY(EditAnywhere, Category = "Setting")
	TArray<FString> currentrecipe;

	// �� ����(�Ž� Ÿ��)
	UPROPERTY(EditAnywhere, Category = "Setting")
	int32 customerType = 0;

	// �̵��� ��ǥ
	UPROPERTY(EditAnywhere, Category = "Setting")
	FVector moveLoc = FVector::ZeroVector;

	// ȸ�� ���
	UPROPERTY(EditAnywhere, Category = "Setting")
	FRotator moveRot = FRotator::ZeroRotator;

	// ������ ���
	UPROPERTY(EditAnywhere, Category = "Setting")
	FVector endLoc = FVector::ZeroVector;

	// ȸ�� ���
	UPROPERTY(EditAnywhere, Category = "Setting")
	FRotator endRot = FRotator::ZeroRotator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Setting")
	bool orderSuccess = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	FString menu;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	FString material1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	FString material2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	FString material3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	FString material4;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	FString material5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	class UDataTable* foodData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	bool getfood = false;

private:

	FVector startLoc;
	FRotator startRot;
	float ticktime = 0.0f;
	
	void RandomCustomerSet();

	void Idle();
	void MoveIn();
	void Order();
	void Wait();
	void Check();
	void Payment();
	void MoveOut();
};
