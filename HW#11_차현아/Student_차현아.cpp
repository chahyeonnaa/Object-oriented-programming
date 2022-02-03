#include<iostream>
#include<string> //string 클래스를 사용하기 위한 헤더파일
#include"Student.h"
#include"Subject.h"
#include"InputUtil.h"
#include "IOInterface.h"
using namespace std;

Student::Student():IOInterface()//디폴트 생성자_ 생성자 명시적 호출
{
	m_name = "";
	m_hakbun = 0;
	m_subnum = 0;
	m_sub = NULL;
	m_aveGPA = 0.0;
	cout << "* Student 디폴트 생성자 호출 *\n";

}

Student::Student(string name, int hakbun, int subnum, Subject* sub) :IOInterface(name) 
// 초기화 리스트를 사용하여, 부모 클래스의 인자있는 생성자 명시적 호출
{
	m_name = name; // 입력받은 name을 멤버변수 m_name에 넣어줌 
	m_hakbun = hakbun;
	m_subnum = subnum;
	m_data = 300;

	m_sub = new Subject[m_subnum]; // m_sub의 새로운 공간 동적 할당

	for (int i = 0; i < m_subnum; i++) // 입력받은 과목 수만큼
	{
		(m_sub + i)->SetName((sub + i)->GetName()); // sub의 데이터들을 m_sub으로 베껴옴_ 접근자 함수 사용
		(m_sub + i)->SetHakjum((sub + i)->GetHakjum());
		(m_sub + i)->SetGrade((sub + i)->GetGrade());
		(m_sub + i)->SetGPA((sub + i)->GetGPA()); // 
	}


	cout << "* Student 인자있는 생성자 호출 *\n";
}

Student::~Student() // 할당받은 메모리 공간 해제
{
	cout << "Student 소멸자 호출\n";
	delete[]m_sub;
	m_sub = NULL;
}


void Student::InputData() // 사용자로부터 데이터 입력 받기
{
	cout << "*" << "학생 이름과 학번을 입력하세요.\n";
	cout << "이름 : ";
	InputUtil::InputValue(m_name); // 인자가 문자열이므로 문자열 입력 함수 호출
	cout << "학번 : ";
	InputUtil::InputValue(m_hakbun); // 인자가 정수이므로 정수형 입력 함수 호출
	cout << "\n";

	cout << "수강한 과목 수 입력 :";
	InputUtil::InputValue(m_subnum);

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

void Student::Modify()
{
	string Type; // 학생정보 또는 과목정보 문자열 저장용 string
	cout << "수정<학생정보/과목정보/모두>:"; // 수정할 내용 입력
	InputUtil::InputValue(Type);

	if (Type == "학생정보") // 학생정보 수정이면
	{
		cout << "*< " << m_name << "  " << m_hakbun << " >의 정보를 수정하세요\n";
		cout << "이름 : ";
		InputUtil::InputValue(m_name); // 인자가 문자열이므로 문자열 입력 함수 호출
		cout << "학번 : ";
		InputUtil::InputValue(m_hakbun);
		cout << "\n";
	}
	else if (Type == "과목정보") // 과목정보 수정_어떤 과목을 수정할 것인지 과목 찾기
	{
		string subject; // string 문자열 객체
		cout << "검색할 과목 이름 :"; // 교과목이 있는지 검색
		InputUtil::InputValue(subject);
		int i;
		for (i = 0; i < m_subnum; i++) // 수강하는 과목의 수만큼 반복
		{
			if (subject == (m_sub + i)->GetName()) // 입력받은 과목과 수강 과목들을 차례대로 비교
			{
				(m_sub + i)->Modify();
				break;
			}
			else
				continue; // 일치하는 과목을 찾지 못했다면, 계속 다음 반복을 수행
		}
		if (i == m_subnum)
		{
			cout << "일치하는 과목이 없습니다. \n"; // 일치하는 과목이 없을 경우, 메세지 출력
		}

	}
	else if (Type == "모두")
	{
		cout << "*< " << m_name << "  " << m_hakbun << " >의 정보를 수정하세요\n";
		cout << "이름 : ";
		InputUtil::InputValue(m_name); // 인자가 문자열이므로 문자열 입력 함수 호출
		cout << "학번 : ";
		InputUtil::InputValue(m_hakbun);
		cout << "\n";

		string subject; // string 문자열 객체
		cout << "검색할 과목 이름 :"; // 교과목이 있는지 검색
		InputUtil::InputValue(subject);
		int i;
		for (i = 0; i < m_subnum; i++) // 수강하는 과목의 수만큼 반복
		{
			if (subject == (m_sub + i)->GetName()) // 입력받은 과목과 수강 과목들을 차례대로 비교
			{
				(m_sub + i)->Modify();
				break;
			}
			else
				continue; // 일치하는 과목을 찾지 못했다면, 계속 다음 반복을 수행
		}
		if (i == m_subnum)
		{
			cout << "일치하는 과목이 없습니다. \n"; // 일치하는 과목이 없을 경우, 메세지 출력
		}


	}

}
Subject* Student::SubSearch(string subname)const // 과목탐색_ 따로 값을 수정하지않기 때문에 const 멤버함수로 해줌
{
	int i;
	for (i = 0; i < m_subnum; i++) // 수강하는 과목의 수만큼 반복
	{
		if (subname == (m_sub + i)->GetName()) // 입력받은 과목과 수강 과목들을 차례대로 비교
		{
			return m_sub + i;
			break;
		}
		else
			continue; // 일치하는 과목을 찾지 못했다면, 계속 다음 반복을 수행
	}
	if (i == m_subnum)
	{
		cout << "일치하는 과목이 없습니다. \n"; // 일치하는 과목이 없을 경우, 메세지 출력
		return NULL;
	}


}
string Student::GetName()// 접근자함수 : 클래스 밖에서 멤버변수를 읽을 수 있게함					   // 따로 값을 수정하지않기 때문에 const 멤버함수로 해줌
{
	return m_name;
}

int Student::GetHakbun()const
{
	return m_hakbun;
}

int Student::GetSubNum()const
{
	return m_subnum;
}

float Student::GetAveGPA()const
{
	return m_aveGPA;
}