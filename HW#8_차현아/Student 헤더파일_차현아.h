#pragma once
#include<iostream>
#include<string>
#include"Subject.h" // Subject 클래스의 헤더파일 포함
using namespace std;

class Student {
protected:
	string m_name; // 학생 이름
	int m_hakbun;  // 학번
	int m_subnum;  // 수강한 과목 수
	Subject* m_sub; // 수강한 과목들
	float m_aveGPA; // 수강한 과목들의 평균 평점

public:
	void Initialize(); // 멤버변수 초기화
	void Initialize(string, int, int, Subject*); // 인자값으로 멤버변수 초기화
	void Remove(); // 동적메모리 해제(m_sub)
	void InputValue(string&);
	void InputValue(int&);
	void InputData(); // 멤버변수 값 입력
	void PrintData(); // 멤버변수 값 출력
	void CalcAveGPA(float sum, float haksum); // 평균 평점 계산

	string GetName(); // 접근자함수 : 클래스 밖에서 멤버변수를 읽을 수 있게함.
	int GetHakbun();
	int GetSubNum();
	float GetAveGPA();

	friend void Showdata(const Student& s); // 전역함수를 friend 함수로 지정하여 접근 임시 허용

};