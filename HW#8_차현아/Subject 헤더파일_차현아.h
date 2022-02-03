#pragma once
#include<iostream>
#include<string> //string 클래스를 사용하기 위한 헤더파일
using namespace std;

// 클래스의 선언부
class Subject { 
protected: // 클래스 자신과 상속받은 자식 클래스에만 허용
	string m_name; // 과목명
	int m_hakjum;  // 학점
	string m_grade; // 등급
	float m_GPA;    // 평점

public:
	void Initialize(); // 멤버변수 초기화
	void Initialize(string, int, string);
	void InputValue(string&); // 입력을 위한 함수
	void InputValue(int&);
	void InputData(); // 멤버변수 값 입력_내부적으로 InputValue() 이용 
	void PrintTitle(); // 멤버변수에 대한 Title Text 출력
	void PrintData(); // 멤버변수 값 출력
	void CalcGPA(); // 평점계산

	string GetName(); // 접근자 함수(클래스 멤버 변수에 대한 접근 허용)
	int GetHakjum();
	string GetGrade();
	float GetGPA();

};

