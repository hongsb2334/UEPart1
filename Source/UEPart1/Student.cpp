// Fill out your copyright notice in the Description page of Project Settings.


#include "Student.h"
#include "Card.h"

UStudent::UStudent()
{
    Order = -1;
    Name = TEXT("홍길동");
}

void UStudent::Serialize(FArchive& Ar)
{
    Super::Serialize(Ar);

    //직렬화
    Ar << Order;
    Ar << Name;
}


