/*********************************************************/
/*        HW#11 : 상속 실습                              */
/*  작성자 : 차현아        날짜 : 2021년 6월 4일         */
/*                                                       */
/* 문제 정의 : 객체지향방식의 성적처리프로그램 #5 작성   */
/*             1. 오류찾고 IOInterface 수정하기          */
/*             2. 기본클래스와 파생클래스의 관계         */
/*             3. Modify() 멤버함수 수정                 */
/*********************************************************/
#include"Subject.h" // Subject 클래스와 Student클래스를 사용하기 위해 헤더파일을 포함
#include"Student.h"
#include "IOInterface.h"
#include"GradeManager.h"
#include<iostream>
#include<string> //string 클래스를 사용하기 위한 헤더파일
using namespace std;

int main(void)
{
	/* 1. 추상 클래스 확인*/
	Student std; // Student 클래스의 std 객체생성
	std.InputData(); // 학생 정보 입력받기

	IOInterface* IO[2] = { new Subject("사진학",3,"A+"),&std }; // 추상 클래스의 포인터배열 생성
	                                                            // 파생 클래스의 객체를 가리킬 수 있음
	for (int i = 0; i < 2; i++)
	{
		cout << "\n *" << i + 1 << "번째 데이터 :" << "\n";
		IO[i]->PrintData(); // 파생클래스의 멤버함수가 호출되어야함_ 추상 클래스 속 순수 가상함수이기 때문에 가능
	}

	/* 2. GradeManager Class 테스트*/
	//int stdnum; // 학생 수를 받는 변수

	//cout << "입력할 학생 수를 입력 :";
	//InputUtil::InputValue(stdnum); // 학생 수 입력
	//cout << endl;

	//GradeManager GradeMgr(stdnum); // 학생 성적의 모든것을 관리하는 클래스의 객체 생성
	//GradeMgr.Execute(); // 학생 성적을 관리하는 함수 실행
}
