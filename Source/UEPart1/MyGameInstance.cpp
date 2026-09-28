// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "Student.h"
#include "Teacher.h"
#include "Staff.h"
#include "Card.h"
#include "CourseInfo.h"

UMyGameInstance::UMyGameInstance()
{
    //기본값 설정
    //생성자에서 설정하는 기본 값은 CDO 템플릿 객체에 저장
    SchoolName = TEXT("기본 학교");
}

void UMyGameInstance::Init()
{
    Super::Init();

    //학사정보 객체 생성
    CourseInfo = NewObject<UCourseInfo>(this);

    UE_LOG(LogTemp, Log, TEXT("============"));
    
    //3개의 학생 객체 생성, newobject안에 비어있으면 임시객체로 생성됨
    UStudent* Student1 = NewObject<UStudent>();
    Student1->SetName(TEXT("학생 1"));
    
    UStudent* Student2 = NewObject<UStudent>();
    Student2->SetName(TEXT("학생 2"));
    
    UStudent* Student3 = NewObject<UStudent>();
    Student3->SetName(TEXT("학생 3"));
    
    UStaff* Staff1 = NewObject<UStaff>();
    Staff1->SetName(TEXT("스태프 1"));

    //학사 정보 객체와 학생 객체의 연결
    //발행 주체와 구독 주체의 연결(여기서는 의존성을 피할 수 없음)
    //MyGameInstance는 일종의 관리자(매니저) 성격의 객체
    //지금은 GameInstance에서 코드를 처리하고 있지만 액터에서도 가능

    //구독 처리
    CourseInfo->OnChanged.AddUObject(Student1, &UStudent::GetNotification);
    CourseInfo->OnChanged.AddUObject(Student2, &UStudent::GetNotification);
    CourseInfo->OnChanged.AddUObject(Student3, &UStudent::GetNotification);

    CourseInfo->OnChanged.AddUObject(Staff1, &UStaff::GetNotification);

    CourseInfo->ChangeCourseInfo(SchoolName, TEXT("변경된 학사 정보"));

    UE_LOG(LogTemp, Log, TEXT("============"));


}
