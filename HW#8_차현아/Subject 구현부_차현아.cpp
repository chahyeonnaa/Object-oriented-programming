#include<iostream>
#include<string> //string 클래스를 사용하기 위한 헤더파일
#include"Subject.h"
using namespace std;

// 클래스의 구현부
void Subject::Initialize() // 멤버 변수 초기화
{
	m_name = "";
	m_hakjum = 0;
	m_grade = "";
	m_GPA = 0.0;
}

void Subject::Initialize(string name, int jum, string grade)
// 데이터를 사용자에게 입력받지 않을때, 변수를 매개변수로 받아서 초기화해주는 함수
{
	m_name = name; // 멤버변수 자리에 데이터 할당해주기
	m_hakjum = jum;
	m_grade = grade;
}

inline void Subject::InputValue(string& str) // 문자열 입력시
{
	getline(cin, str);
}

inline void Subject::InputValue(int& i) // 정수 입력시
{
	cin >> i;
	cin.ignore(); // 버퍼 비워주기
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
	InputValue(m_name); // 인자가 문자열이므로 문자열 입력 함수 호출
	cout << "과목 학점수:";
	InputValue(m_hakjum); // 인자가 정수이므로 정수형 입력 함수 호출
	cout << "과목등급<A+ ~F>:";
	InputValue(m_grade); // 인자가 문자열이므로 문자열 입력 함수 호출
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

string Subject::GetName() // 접근자함수 : m_name을 클래스 밖에서 읽을 수 있게함.
{
	return m_name;
}

int Subject::GetHakjum() // 접근자함수 : m_hakjum을 클래스 밖에서 읽을 수 있게함.
{
	return m_hakjum;
}

float Subject::GetGPA() // 접근자함수 : m_GPA을 클래스 밖에서 읽을 수 있게함.
{
	return m_GPA;
}

string Subject::GetGrade() // 접근자함수 : m_grade을 클래스 밖에서 읽을 수 있게함.
{
	return m_grade;
}

