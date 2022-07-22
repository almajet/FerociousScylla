// Copyright AlmaJet Game Studio. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "FSVolumeBase.generated.h"

/**
 * 
 */
UCLASS()
class FERSCY_API AFSVolumeBase : public AVolume
{
	GENERATED_BODY()
public: 
	UFUNCTION()
	void OnPlayerEnter(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
	void OnPlayerExit(AActor* OverlappedActor, AActor* OtherActor);

	UPROPERTY(EditInstanceOnly, Category = "FSVolume")
	FName VolumeName = "TestVolumeLevoe";

protected:
	virtual void BeginPlay() override;
};
