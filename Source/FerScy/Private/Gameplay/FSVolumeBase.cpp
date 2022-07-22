// Copyright AlmaJet Game Studio. All rights reserved.


#include "Gameplay/FSVolumeBase.h"
#include "Player/FSCharacterBase.h"

void AFSVolumeBase::OnPlayerEntered(AFSCharacterBase* Player)
{
}

void AFSVolumeBase::OnPlayerExited(AFSCharacterBase* Player)
{
}

void AFSVolumeBase::OnPlayerEnter(AActor* OverlappedActor, AActor* OtherActor) 
{
	AFSCharacterBase* Character = Cast<AFSCharacterBase>(OtherActor);
	if (Character)
	{
		if (GEngine)
		{
			OnPlayerEntered(Character);
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
			OnPlayerExited(Character);
		}
	}
}

void AFSVolumeBase::BeginPlay() 
{	
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &AFSVolumeBase::OnPlayerEnter);
	OnActorEndOverlap.AddDynamic(this, &AFSVolumeBase::OnPlayerExit);
}