
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Customer.generated.h"

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

	UPROPERTY(EditDefaultsOnly)
	class U

};
