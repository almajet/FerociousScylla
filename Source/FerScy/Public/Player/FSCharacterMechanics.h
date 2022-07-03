#pragma once
#include "CoreMinimal.h"
#include "FSCharacterMechanics.generated.h"

USTRUCT(BlueprintType)
struct FFSDoubleJumpMechanicInfo
{
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Double Jump")
	bool bEnable = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Double Jump", meta = (ClampMin = "1", ClampMax = "16", EditCondition = "bEnable"))
	uint8 OverrideMaxJumpCount = 2;
};

USTRUCT(BlueprintType)
struct FFSCharacterMechanicSetup
{	
	GENERATED_USTRUCT_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Double Jump")
	FFSDoubleJumpMechanicInfo DoubleJump;
};