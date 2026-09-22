// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class UEPART1_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
    //생성자
    UMyGameInstance();

	//게임인스턴스 초기화 함수
	virtual void Init() override;

private:
    UPROPERTY()
    FString SchoolName;
};
