/*****************************************************/
/*             HW#8 : 클래스 기초 실습               */
/*  작성자 : 차현아        날짜 : 2021년 5월 7일     */
/*                                                   */
/* 문제 정의 :객체지향방식의 성적처리 프로그램#1 작성*/
/*            1. Subject Class 테스트(분할컴파일전)   */
/******************************************************/

#include<iostream>
#include<string> //string 클래스를 사용하기 위한 헤더파일
using namespace std;

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
// 클래스의 구현부_멤버 함수 정의
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

int main()
{
	Subject sub1, sub2, sub3[2], * sub4; // 일반객체, 객체배열, 객체 포인터 생성
	int i;

	sub1.Initialize(); // sub1을 빈공간으로 초기화
	sub2.Initialize("사진학", 3, "A+"); //sub2에 다음과 같은 과목정보를 넣어줌.
	for (int i = 0; i < 2; i++)
		sub3[i].Initialize("컴퓨터", 3, "C0"); //sub3에 다음과 같은 과목정보들을 차례대로 넣어줌.

	sub4 = new Subject[2]; // 두과목을 넣을 수 있는 공간 할당하여 sub4 가 가리키게함.

	sub1.InputData(); //sub1의 정보 직접 입력받기
	cout << "\n" << "sub1 정보" << "\n";
	sub1.PrintTitle();
	sub1.PrintData(); //sub1의 과목 정보 출력

	cout << "\n" << "sub2 정보" << "\n";
	sub2.PrintTitle();
	sub2.PrintData(); //sub2의 과목 정보 출력

	cout << "\n" << "sub3 정보" << "\n";
	sub3[0].PrintTitle();
	for (i = 0; i < 2; i++)
		sub3[i].PrintData(); //sub3의 과목정보 출력

	for (i = 0; i < 2; i++)
		(sub4 + i)->InputData(); // sub4의 과목정보 직접 입력받기
	cout << "\n" << "sub4 정보" << "\n";
	sub4->PrintTitle();
	for (i = 0; i < 2; i++)
		(sub4 + i)->PrintData(); // sub4의 과목정보 출력

	delete[]sub4; // 위에서 할당받은 sub4의 메모리 공간 해제

}


