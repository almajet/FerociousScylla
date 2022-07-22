// Copyright AlmaJet Game Studio. All rights reserved.


#include "Gameplay/FSVolumeBase.h"
#include "Player/FSCharacterBase.h"

void AFSVolumeBase::OnPlayerEnter(AActor* OverlappedActor, AActor* OtherActor) 
{
	AFSCharacterBase* Character = Cast<AFSCharacterBase>(OtherActor);
	if (Character)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, FString::Printf(TEXT("Entered %s"), *VolumeName.ToString()));
		}
	}

	
}

void AFSVolumeBase::OnPlayerExit(AActor* OverlappedActor, AActor* OtherActor)
{
	AFSCharacterBase* Character = Cast<AFSCharacterBase>(OtherActor);
	if (Character)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 10.0f, FColor::Red, FString::Printf(TEXT("Exited %s"), *VolumeName.ToString()));
		}
	}
}

void AFSVolumeBase::BeginPlay() 
{	
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &AFSVolumeBase::OnPlayerEnter);
	OnActorEndOverlap.AddDynamic(this, &AFSVolumeBase::OnPlayerExit);

}