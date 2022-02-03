/*****************************************************/
/*             HW#8 : 클래스 기초 실습               */
/*  작성자 : 차현아        날짜 : 2021년 5월 7일     */
/*                                                   */
/* 문제 정의 :객체지향방식의 성적처리 프로그램#1 작성*/
/*            3. 분할 컴파일, friend 함수 지정       */
/******************************************************/
#include"Subject.h" // Subject 클래스의 선언부가 저장된 헤더파일
#include"Student.h" // Student 클래스의 선언부가 저장된 헤더파일

#include<iostream>
#include<string> //string 클래스를 사용하기 위한 헤더파일
using namespace std;

void Showdata(const Student& s) // 전역함수이지만, friend 함수로 지정되어 멤버 변수에 임시로 접근허용
{
	cout.width(3);
	cout << "* " << s.m_name << "학생이 수강한 과목은 총" << s.m_subnum << "개로 ";
	cout << "수강한 과목의 평균평점은 " << s.m_aveGPA << "입니다 *\n";
	cout << "\n";
	cout << "\n";
}

int main(void)
{
	Subject sub[2]; // 객체 배열
	sub[0].Initialize("컴퓨터", 3, "C0"); // 과목정보 넣기 
	sub[1].Initialize("현대무용", 2, "A0");

	Student st1, st2; // Student 클래스의 일반 객체 생성

	st1.Initialize(); // st1을 빈공간으로 초기화
	st2.Initialize("홍길동", 2020039099, 2, sub); // 위에서 초기화한 과목 배열을 인자로 넘긴다.

	st1.InputData(); // 사용자로부터 직접 정보를 입력받음
	cout << "\n" << "st1 정보" << "\n";
	st1.PrintData(); // 정보 출력
	Showdata(st1); // 전체 정보를 문장 하나로 출력

	cout << "\n" << "st2 정보" << "\n";
	st2.PrintData(); // 정보출력
	Showdata(st2); // 전체 정보를 문장 하나로 출력

	st1.Remove(); //st1에서 과목정보를 할당한 메모리 공간해제
}
