// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

UMyGameInstance::UMyGameInstance()
{
    //기본값 설정
    //생성자에서 설정하는 기본 값은 CDO 템플릿 객체에 저장
    SchoolName = TEXT("기본 학교");
}

void UMyGameInstance::Init()
{
    Super::Init();


    ////언리얼은 utf16->wchar만 사용
    //// 
    //// 각종 타입으로 변경할 수 있는 헬퍼 함수 제공
    ////UE_LOG(LogTemp, Warning, TEXT("hello unreal"));

    ////TCHAR | FSTRING
    //TCHAR LogCharArray[] = TEXT("Hello Unreal");
    //UE_LOG(LogTemp, Warning, TEXT("%s"), LogCharArray);

    //FString LogCharString = LogCharArray;
    //UE_LOG(LogTemp, Warning, TEXT("%s"), *LogCharString);

    ////문자열 복사
    //TCHAR LogCharArrayWithSize[100] = {};
    //FCString::Strncpy(LogCharArrayWithSize, *LogCharString, LogCharString.Len());

    //UE_LOG(LogTemp, Log, TEXT("%s"), LogCharArrayWithSize);
    //
    ////문자열 자르기
    //if (LogCharString.Contains(TEXT("unreal"), ESearchCase::IgnoreCase))
    //{
    //    //문자열을 검색해 시작 인덱스 얻기
    //    int32 Index = LogCharString.Find(TEXT("unreal"), ESearchCase::IgnoreCase);
    //    FString EndString = LogCharString.Mid(Index);
    //    UE_LOG(LogTemp, Log, TEXT("%s"), *EndString);
    //}


    ////문자열 나누기
    //FString Left, Right;
    //if (LogCharString.Split(TEXT(" "), &Left, &Right))
    //{
    //    UE_LOG(LogTemp, Log, TEXT("Split Test: %s / %s"), *Left, *Right);
    //}

    ////문자열 조합
    //int32 IntValue = 40;
    //float FloatValue = 3.141592f;

    //FString FloatIntString = FString::Printf(TEXT("Int:%d, Float:%f"), IntValue, FloatValue);

    //UE_LOG(LogTemp, Log, TEXT("%s"), *FloatIntString);

    ////FName 특성 살펴보기 - 대소문자 구별 x
    ////문자열을 키로 사용
    //FName key1(TEXT("PELVIS"));
    //FName key2(TEXT("pelvis"));

    //UE_LOG(LogTemp, Log, TEXT("FName 비교 결과: %s"), (key1 == key2 ? TEXT("같음") : TEXT("다름")));

    UE_LOG(LogTemp, Log, TEXT("================"));

    //클래스 정보 가져오기

    UClass* ClassRuntime = GetClass();
    UClass* ClassCompile = UMyGameInstance::StaticClass();

    //두 정보가 같은지 비교(assert)
    //check는 걸리면 에디터를 아예 종료시켜버려서 위험할 수 있음
    ensure(ClassRuntime == ClassCompile);
    //check(ClassRuntime == ClassCompile);

    UE_LOG(LogTemp, Log, TEXT("학교를 담당하는 클래스 이름 : %s"), *ClassRuntime->GetName());

    SchoolName = TEXT("포텐업");

    //FString이랑 uelog랑 안맞아서 역참조 연산자 넣어서 string으로 컨버트
    UE_LOG(LogTemp, Log, TEXT("학교 이름: %s"), *SchoolName);
    UE_LOG(LogTemp, Log, TEXT("학교 이름 기본값: %s"), *GetClass()->GetDefaultObject<UMyGameInstance>()->SchoolName);

    UE_LOG(LogTemp, Log, TEXT("============"));
}
