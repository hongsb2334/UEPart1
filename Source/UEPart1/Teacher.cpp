// Fill out your copyright notice in the Description page of Project Settings.


#include "Teacher.h"
#include "Card.h"
UTeacher::UTeacher()
{
    Name = TEXT("선생님");
    Card->SetCardType(ECardType::Teacher);
}

void UTeacher::DoLesson()
{
    //Super로 호출하면 인터페이스가 아니라 UPerson의 Dolesson을 호출하려고 해서 함수 없다고 뜬다.
    ILessonInterface::DoLesson();
    UE_LOG(LogTemp, Log, TEXT("%s님이 강의합니다."), *Name);
}

