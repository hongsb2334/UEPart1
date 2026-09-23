// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Person.generated.h"

//전방 선언
class UCard;

UCLASS()
class UEPART1_API UPerson : public UObject
{
	GENERATED_BODY()
	
public:
    UPerson();


    inline const FString& GetName() const { return Name; }
    inline void SetName(const FString& InName) { Name = InName; }

    UCard* GetCard() const { return Card; }
    void SetCard(UCard* InCard) { Card = InCard; }

protected:

    UPROPERTY()
    FString Name;
  

    
    //카드 객체
    UPROPERTY()
    TObjectPtr<UCard> Card;
};
