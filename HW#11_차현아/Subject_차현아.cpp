#include<iostream>
#include<string> //string 클래스를 사용하기 위한 헤더파일
#include"Subject.h"
#include"InputUtil.h"
#include "IOInterface.h"
using namespace std;

Subject::Subject():IOInterface() //디폴트 생성자_ 생성자 명시적 호출
{
	m_name = "";
	m_hakjum = 0;
	m_grade = "";
	m_GPA = 0.0;
	cout << "* Subject() 디폴트 생성자 호출 *\n";
}


Subject::Subject(string name, int hakjum, string grade):IOInterface(name)
// 초기화 리스트를 사용하여, 부모 클래스의 인자있는 생성자 명시적 호출
{
	m_name = name;
	m_hakjum = hakjum;
	m_grade = grade;
	m_data = 100;
	CalcGPA();
	cout << "* Subject 인자있는 생성자 호출 *\n";
}

Subject::~Subject()
{
	cout << "Subject 소멸자 호출\n";
}

void Subject::CalcGPA() // 한 과목의 평점 계산하기 ex)3학점 * 4.5 = 13.5
{
	if (m_grade == "A+") // string  객체의 문자열 비교를 통해 GPA에 숫자 값 할당
		m_GPA = 4.5;
	else if (m_grade == "A0")
		m_GPA = 4.0;
	else if (m_grade == "B+")
		m_GPA = 3.5;
	else if (m_grade == "B0")
		m_GPA = 3.0;
	else if (m_grade == "C+")
		m_GPA = 2.5;
	else if (m_grade == "C0")
		m_GPA = 2.0;
	else if (m_grade == "D+")
		m_GPA = 1.5;
	else if (m_grade == "D0")
		m_GPA = 1.0;
	else if (m_grade == "F")
		m_GPA = 0;

	m_GPA = m_GPA * m_hakjum; // 학점과 변환된 등급을 곱하여 평점 계산

}

void Subject::InputData()// 사용자에게 멤버변수의 값을 직접 입력받음.
{
	cout << "교과목 명:";
	InputUtil::InputValue(m_name); // 인자가 문자열이므로 문자열 입력 함수 호출
	cout << "과목 학점수:";
	InputUtil::InputValue(m_hakjum); // 인자가 정수이므로 정수형 입력 함수 호출
	cout << "과목등급<A+ ~F>:";
	InputUtil::InputValue(m_grade); // 인자가 문자열이므로 문자열 입력 함수 호출
	cout << "\n";

}

void Subject::PrintTitle() // 멤버변수에 대한 title 텍스트를 화면에 출력
{
	cout << "====================================================================\n";
	cout.width(15);
	cout << "교과목명" << "            학점수" << "        등급 " << "         평점 " << "\n";
	cout << "====================================================================\n";

}

void Subject::PrintData() // 멤버 변수의 값을 화면에 출력
{
	cout.precision(2);
	cout << fixed;
	cout.width(15);
	cout << m_name; // 과목이름
	cout.width(15);
	cout << m_hakjum; // 과목학점
	cout.width(15);
	cout << m_grade; // 과목등급
	cout.width(15);
	CalcGPA();
	cout << m_GPA << "\n"; // 평균평점

}

void Subject::Modify()
{
	cout << "*< " << m_name << " >의 정보를 수정하세요\n";
	cout << "교과목명: ";
	InputUtil::InputValue(m_name);
	cout << "과목학점 :";
	InputUtil::InputValue(m_hakjum);
	cout << "과목등급 :";
	InputUtil::InputValue(m_grade);
	cout << "\n";
	CalcGPA();

}
string Subject::GetName() // 접근자함수 : m_name을 클래스 밖에서 읽을 수 있게함.
{
	return m_name;
}

int Subject::GetHakjum()const // 접근자함수 : m_hakjum을 클래스 밖에서 읽을 수 있게함.
{
	return m_hakjum;
}

float Subject::GetGPA()const // 접근자함수 : m_GPA을 클래스 밖에서 읽을 수 있게함.
{
	return m_GPA;
}

string Subject::GetGrade()const // 접근자함수 : m_grade을 클래스 밖에서 읽을 수 있게함.
{
	return m_grade;
}

void Subject::SetName(string name) // 접근자함수: 해당 변수들을 클래스 밖에서 수정가능하게함.
{
	m_name = name;
}
void Subject::SetHakjum(int num)
{
	m_hakjum = num;
}
void Subject::SetGrade(string gra)
{
	m_grade = gra;
}
void Subject::SetGPA(float num)
{
	m_GPA = num;
}
