// Fill out your copyright notice in the Description page of Project Settings.


#include "Person.h"
#include "Card.h"

UPerson::UPerson()
{
    Name = TEXT("홍길동");

    //시작할 때 카드가 생성되도록 객체 생성(CDO에서 관리됨)
    Card = CreateDefaultSubobject<UCard>(TEXT("Name_Card"));
}