// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameInstance.h"

void UMyGameInstance::Init()
{
	Super::Init();


    //언리얼은 utf16->wchar만 사용
    // 
    // 각종 타입으로 변경할 수 있는 헬퍼 함수 제공
    //UE_LOG(LogTemp, Warning, TEXT("hello unreal"));

    //TCHAR | FSTRING
    TCHAR LogCharArray[] = TEXT("Hello Unreal");
    UE_LOG(LogTemp, Warning, TEXT("%s"), LogCharArray);

    FString LogCharString = LogCharArray;
    UE_LOG(LogTemp, Warning, TEXT("%s"), *LogCharString);
}
