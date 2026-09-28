// Fill out your copyright notice in the Description page of Project Settings.


#include "CourseInfo.h"

UCourseInfo::UCourseInfo()
{
    //기본 값 설정
    Contents = TEXT("기존 학사 정보");
}

void UCourseInfo::ChangeCourseInfo(const FString& InSchoolName, const FString& InNewContents)
{
    //변경된 학사 정보 설정
    Contents = InNewContents;

    UE_LOG(LogTemp, Log, TEXT("[CourseInfo] 학사 정보가 변경되어 알림을 전송합니다."));
    
    //델리게이트 호출(브로드캐스트 -> 여러 대상에게 알림)
    OnChanged.Broadcast(InSchoolName, InNewContents);


}
