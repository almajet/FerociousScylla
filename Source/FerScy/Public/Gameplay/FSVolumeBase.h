// Copyright AlmaJet Game Studio. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Volume.h"
#include "FSVolumeBase.generated.h"

class AFSCharacterBase;

/**
 * 
 */
UCLASS()
class FERSCY_API AFSVolumeBase : public AVolume
{
	GENERATED_BODY()
public: 
	virtual void OnPlayerEntered(AFSCharacterBase* Player);
	virtual void OnPlayerExited(AFSCharacterBase* Player)

private:
	UFUNCTION()
	void OnPlayerEnter(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
	void OnPlayerExit(AActor* OverlappedActor, AActor* OtherActor);

	UPROPERTY(EditInstanceOnly, Category = "FSVolume")
	FName VolumeName = "TestVolumeLevoePpc";

	
protected:
	virtual void BeginPlay() override;
};
