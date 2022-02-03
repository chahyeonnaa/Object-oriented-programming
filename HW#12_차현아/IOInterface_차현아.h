#pragma once
#include<iostream>
#include<string>
#include"InputUtil.h"
using namespace std;

class IOInterface { // 부모 클래스
public:

	virtual ~IOInterface() // 가상 소멸자_ 파생클래스의 소멸자 실행 후 기본 클래스의 소멸자 호출
	{
		cout << "IOInterface의 소멸자 호출\n";
	}

	virtual void InputData() = 0;// 순수 가상함수로 변경_파생클래스에서 재정의해서 쓸 수 있도록 원형만 제작
	virtual void PrintData()const = 0;
	virtual void Modify() = 0;


};

