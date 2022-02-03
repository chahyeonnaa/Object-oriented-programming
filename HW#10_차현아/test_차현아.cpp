/*********************************************************/
/*        HW#10 : 멤버함수와 클래스의 활용 실습          */
/*  작성자 : 차현아        날짜 : 2021년 5월 21일        */
/*                                                       */
/* 문제 정의 : 1. Student class에 SubSearch 멤버함수 추가*/
/*             2. 정적멤버변수, const멤버함수 작성       */
/*             3. InputUtil class 추가                   */
/*             4. 여러가지 객체생성                      */
/*********************************************************/

#include"Subject.h" // Subject 클래스와 Student클래스를 사용하기 위해 헤더파일을 포함
#include"Student.h"

#include<iostream>
#include<string> //string 클래스를 사용하기 위한 헤더파일
using namespace std;

void Data(const Student& s) //const객체에서는 const멤버 함수만 호출가능_ 
							//접근자함수는 모두 const 멤버함수로 설정하였음.
{
	cout << s.GetName() << "이 수강한 과목은 총 " << s.GetSubNum() << "개로 ";
	cout << "수강한 과목의 평균평점은 " << s.GetAveGPA() << "입니다.\n";
}

int main(void)
{
	/* 1. SubSearch 멤버함수 테스트*/
	Student std; // std 학생 객체
	std.InputData(); // 데이터 입력받기
	std.PrintData(); // 학생정보 출력

	Subject* sub = std.SubSearch("사진학"); // 과목 사진학 찾기

	if (sub != NULL) // 찾았으면, 사진학 과목 정보 출력_ 찾지 못했으면 메세지 출력
	{
		cout << "< 찾은 과목의 정보 >\n";
		sub->PrintTitle();
		sub->PrintData();
		cout << "\n";
	}

	/*2. 정적멤버함수와 const 멤버함수 테스트*/
	//Subject sub1("컴퓨터", 3, "C0");
	//Subject sub2("계산기", 2, "A+");

	//Subject::PrintTitle();
	//sub1.PrintData(); // 위에서 정의한 과목 정보 출력
	//sub2.PrintData();

	//Student st1("홍길동", 2020039009, 1, &sub1); // sub1객체를 받음
	//st1.PrintData();
	//Data(st1); // 전역함수 호출

	/*3. 여러 객체 생성방법 테스트*/
	//Subject sub1[2] = { Subject("컴퓨터",3,"C+"),Subject("현대무용",2,"A0") };// 객체배열
	//Subject* sub2[2] = { new Subject(), new Subject("수학",3,"B+") };// 포인터배열_ 두가지 생성자
	//Student st1; // 일반 객체
	//Student st2("홍길동", 2020039009, 2, sub1); // st2가 sub1을 수강_인자있는 생성자
	//Student* st3 = new Student[2]; // 동적객체배열_ 학생 두명

	//cout << "\n" << "sub2[0] 입력" << "\n"; // 동적할당 받은 공간
	//sub2[0]->InputData();

	//cout << "\n" << "st1 입력" << "\n"; // 일반객체
	//st1.InputData();

	//cout << "\n" << "st3 입력" << "\n"; // 동적객체배열_학생 두명
	//for (int i = 0; i < 2; i++)
	//	(st3 + i)->InputData();

	//cout << "\n" << "sub1 정보출력(컴,현)" << "\n"; // 동적할당 받은 공간
	//Subject::PrintTitle();
	//for (int i = 0; i < 2; i++)
	//	sub1[i].PrintData();

	//cout << "\n" << "sub2 정보출력(입력,수학)" << "\n"; // 동적할당 받은 공간
	//Subject::PrintTitle();
	//for (int i = 0; i < 2; i++)
	//	sub2[i]->PrintData();

	//cout << "\n" << "st1 정보출력" << "\n"; // 일반객체
	//st1.PrintData();

	//cout << "\n" << "st2 정보출력" << "\n"; // 인자있는 생성자
	//st2.PrintData();

	//cout << "\n" << "st3 정보출력" << "\n"; // 동적객체배열
	//for (int i = 0; i < 2; i++)
	//	(st3 + i)->PrintData();

}

