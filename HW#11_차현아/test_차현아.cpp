/*********************************************************/
/*        HW#11 : 상속 실습                              */
/*  작성자 : 차현아        날짜 : 2021년 5월 28일        */
/*                                                       */
/* 문제 정의 : 객체지향방식의 성적처리프로그램 #4 작성   */
/*             1. 오류찾고 IOInterface 수정하기          */
/*             2. 기본클래스와 파생클래스의 관계         */
/*             3. Modify() 멤버함수 수정                 */
/*********************************************************/
#include"Subject.h" // Subject 클래스와 Student클래스를 사용하기 위해 헤더파일을 포함
#include"Student.h"
#include "IOInterface.h"
#include<iostream>
#include<string> //string 클래스를 사용하기 위한 헤더파일
using namespace std;

int main(void)
{
	/* 1. 오류찾고 IOInterface 수정하기*/
	Student std; // 디폴트 생성자 호출_ 부모 클래스의 디폴트 생성자를 사용자가 직접 만들어야함
	cout << std.GetData() << "\n"; // 부모클래스에서 상속받은 멤버함수 호출

	/* 2. 기본클래스와 파생클래스의 관계*/
	//Subject sub("컴퓨터", 3, "B+"); // 부모클래스의 생성자가 먼저 호출되고 나면 파생클래스의 생성자가 호출됨.
	//cout << "---------------------------------\n";
	//cout << "m_data : " << sub.GetData(); // IOInterface 에서 상속받은 GetData()호출
	//cout << "\n";
	//cout << "교과목 이름 : " << sub.GetName(); // Subject 클래스에서 재정의된 GetName() 호출
	//cout << "\n";
	//cout << "부모 클래스의 이름 : " << sub.IOInterface::GetName(); // IOInterface의 GetName() 호출
	//cout << "\n";
	//cout << "---------------------------------\n";

	//Student std2("홍길동", 2020039009, 1, &sub); // 부모클래스 생성자 먼저 호출-> sub 때문에 부모 디폴트 생성자 호출
	//cout << "---------------------------------\n";
	//cout << "m_data : " << std2.GetData(); // IOInterface 에서 상속받은 GetData()호출
	//cout << "\n";
	//cout << "학생 이름 : " << std2.GetName(); // Subject 클래스에서 재정의된 GetName() 호출
	//cout << "\n";
	//cout << "부모 클래스의 이름 : " << std2.IOInterface::GetName(); // IOInterface의 GetName() 호출
	//cout << "\n";
	//cout << "---------------------------------\n";

	/* 3. Modify() 멤버함수 수정 */
	//Subject sub("컴퓨터", 3, "C0");
	//Student std("홍길동", 2020039009, 1, &sub);

	//std.PrintData(); // 수정 전 결과 출력
	//std.Modify();
	//std.PrintData(); // 수정 후 결과 출력

}