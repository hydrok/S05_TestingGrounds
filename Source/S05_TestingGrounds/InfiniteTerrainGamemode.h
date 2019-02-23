// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "S05_TestingGroundsGameMode.h"
#include "InfiniteTerrainGamemode.generated.h"

/**
 * 
 */
UCLASS()
class S05_TESTINGGROUNDS_API AInfiniteTerrainGamemode : public AS05_TestingGroundsGameMode
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "BoundsPool")
		void PopulateBoundsVolumePool();

private:
	void AddToPool(class ANavMeshBoundsVolume *VolumeToAdd);
};
