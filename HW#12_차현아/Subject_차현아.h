#pragma once
#include "IOInterface.h"
#include<iostream>
#include<string>
using namespace std;

class Subject : public IOInterface {// IOInterface 클래스를 상속 받음
protected: // 클래스 자신과 상속받은 자식 클래스에만 허용
	string m_name;
	int m_hakjum;  // 학점
	string m_grade; // 등급
	float m_GPA;    // 평점

public:
	virtual void InputData(); // 멤버변수 값 입력_내부적으로 InputValue() 이용 
	static void PrintTitle(); // 멤버변수에 대한 Title Text 출력
	virtual void PrintData()const; // 멤버변수 값 출력
	void CalcGPA(); // 평점계산
	virtual void Modify(); // 과목 정보 수정

	Subject(); // 디폴트 생성자
	Subject(string name, int hakjum, string grade); // 인자있는 생성자
	virtual ~Subject(); // 소멸자

	string GetName(); // 접근자 함수(클래스 멤버 변수에 대한 접근 허용)
	int GetHakjum()const;
	string GetGrade()const;
	float GetGPA()const;

	void SetName(string name); // 깊은 복사시 과목정보 데이터를 그대로 복사해서 새로운 공간에
							   // 정의해야 하기 때문에 Set접근자 함수 사용
	void SetHakjum(int num);
	void SetGrade(string gra);
	void SetGPA(float num);


};
