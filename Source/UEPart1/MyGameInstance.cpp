// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"
#include "Student.h"
#include "Teacher.h"
#include "Staff.h"
#include "Card.h"


UMyGameInstance::UMyGameInstance()
{
    //기본값 설정
    //생성자에서 설정하는 기본 값은 CDO 템플릿 객체에 저장
    SchoolName = TEXT("기본 학교");
}

void UMyGameInstance::Init()
{
    Super::Init();

    
    UE_LOG(LogTemp, Log, TEXT("============"));
    TArray<UPerson*> Persons =
    {
        NewObject<UStudent>(),
        NewObject<UTeacher>(),
        NewObject<UStaff>(),
    };

    //범위 기반 루프 활용 이름 출력
    for (const auto Person : Persons)
    {
        UE_LOG(LogTemp, Log, TEXT("구성원 이름 : %s"), *Person->GetName());
    }

    //인터페이스 구현 여부에 따른 수업 참여 구분
    //구현 여부 확인하는 방법 -> 해당 인터페이스로 형변환(다운캐스팅)
    //다운캐스팅 RTTI
    for (const auto Person : Persons)
    {
        ILessonInterface* LessonInterface = Cast<ILessonInterface>(Person);
        
        //형변환 성공하면 구현된 것, 실패하면 구현 안된것
        if (LessonInterface)
        {
            UE_LOG(LogTemp, Log, TEXT("%s님은 수업에 참여할 수 있습니다"), *Person->GetName());
            LessonInterface->DoLesson();
        }
        else
        {
            UE_LOG(LogTemp, Log, TEXT("%s님은 수업에 참여할 수 없습니다"), *Person->GetName());
        }

    }

    //구성원의 카드 타입 출력
    for (const auto Person : Persons)
    {
        const UCard* OwnCard = Person->GetCard();
        ensure(OwnCard);

        //OwnCard->GetCardType();

        const UEnum* CardEnumType = FindObject<UEnum>(nullptr, TEXT("/Script/UEPart1.ECardType"));

        if (CardEnumType)
        {
            //GetDisplayNameTextByValue는 ftext 반환
            //fstring으로 변환할 때는 Tostring 함수 사용
            FString CardMetaData = CardEnumType->GetDisplayNameTextByValue((int64)OwnCard->GetCardType()).ToString();
        
            UE_LOG(LogTemp, Log, TEXT("%s님이 소유한 카드 종류 : %s"), *Person->GetName(), *CardMetaData);
        }
    }

    UE_LOG(LogTemp, Log, TEXT("============"));


}
