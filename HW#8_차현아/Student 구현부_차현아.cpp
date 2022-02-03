#include<iostream>
#include<string> //string 클래스를 사용하기 위한 헤더파일
#include"Student.h"
using namespace std;

void Student::Initialize() // 멤버 변수 초기화
{
	m_name = "";
	m_hakbun = 0;
	m_subnum = 0;
	m_sub = NULL;
	m_aveGPA = 0.0;

}

void Student::Initialize(string str, int hak, int sub, Subject* ject)
// 받아온 매개변수들을 멤버변수 값으로 할당_ *배열을 포인터로 받는다.
{
	m_name = str;
	m_hakbun = hak;
	m_subnum = sub;
	m_sub = ject;
}

void Student::InputValue(string& str) // 문자열 입력을 위한 함수
{
	getline(cin, str);
}

void Student::InputValue(int& i) // 정수 입력을 위한 함수
{
	cin >> i;
	cin.ignore(); // 버퍼 비우기
}


void Student::Remove() // 할당받은 메모리 공간 해제
{
	delete[]m_sub;
}

void Student::InputData() // 사용자로부터 데이터 입력 받기
{
	cout << "*" << "학생 이름과 학번을 입력하세요.\n";
	cout << "이름 : ";
	InputValue(m_name); // 인자가 문자열이므로 문자열 입력 함수 호출
	cout << "학번 : ";
	InputValue(m_hakbun);
	cout << "\n"; // 인자가 정수이므로 정수형 입력 함수 호출

	cout << "수강한 과목 수 입력 :";
	InputValue(m_subnum);

	m_sub = new Subject[m_subnum]; // 입력받은 과목 수 만큼 과목 정보 공간을 동적할당


	for (int j = 0; j < (m_subnum); j++)
	{
		cout << "* 수강한 교과목" << m_subnum << "개와 각 교과목명, 과목학점, 과목등급을 입력하세요.\n";
		(m_sub + j)->InputData(); // 한과목씩 과목 정보 입력
	}

}

void Student::CalcAveGPA(float sum, float haksum) // 전체 학점 평균을 계산하는 함수
{
	m_aveGPA = sum / haksum; // 평점들의 합/ 총 학점 수
}

void Student::PrintData() // 정보 출력
{
	float sum = 0; // 평균 평점을 더해서 받을 변수
	float haksum = 0; // 전체 학점 수를 더해서 받을 변수
	cout << "====================================================================\n";
	cout.width(10);
	cout << "이름 : " << m_name; // 이름출력
	cout.width(10);
	cout << "학번 : " << m_hakbun << "\n" << "\n"; // 학번출력
	cout.width(20);

	m_sub->PrintTitle(); //Subject 클래스의 PrintTitle() 호출

	for (int p = 0; p < m_subnum; p++) // 입력받은 과목수 만큼 반복문을 돌면서
	{
		(m_sub + p)->PrintData(); // 각 과목 정보 출력
		haksum = haksum + (m_sub + p)->GetHakjum(); // 각 과목의 학점수를 더하여 변수에 합을 할당_접근자 함수를 사용하여 접근가능
		sum = sum + (m_sub + p)->GetGPA(); // 각 과목의 평점을 더하여 변수에 할당_접근자 함수를 사용하여 접근가능
	}

	cout << "--------------------------------------------------------------------\n";
	cout.width(45);
	CalcAveGPA(sum, haksum); // 평균평점 계산
	cout << "평균 평점 :" << m_aveGPA << "\n" << "\n";

}


string Student::GetName() // 접근자함수 : 클래스 밖에서 멤버변수를 읽을 수 있게함.
{
	return m_name;
}

int Student::GetHakbun()
{
	return m_hakbun;
}

int Student::GetSubNum()
{
	return m_subnum;
}

float Student::GetAveGPA()
{
	return m_aveGPA;
}

