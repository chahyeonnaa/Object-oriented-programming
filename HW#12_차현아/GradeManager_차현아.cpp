#include "IOInterface.h"
#include"Subject.h"
#include"InputUtil.h"
#include"Student.h"
#include"GradeManager.h"
#include<iostream>
#include<string>
using namespace std;

GradeManager::GradeManager() // 디폴트 생성자
{
	m_std = NULL;
	m_stdnum = 0;
}

GradeManager::GradeManager(int m_stdnum) // 인자있는 생성자
{
	m_std = new Student[m_stdnum]; // 입력받은 학생 수 만큼의 공간을 동적할당
	this->m_stdnum = m_stdnum;
}
int GradeManager::Getstdnum()const // 접근자함수 : m_stdnum을 클래스 밖에서 읽을 수 있게함.
{
	return m_stdnum;
}
GradeManager::~GradeManager() // 소멸자_ 동적할당 받은 공간 해제
{
	delete[] m_std;
	cout << "GradeManager 소멸자 호출\n";
}
Student* GradeManager::StdSearch(string stdname)const // 학생 검색(찾고자하는 학생을 함수의 인자로 받음) 
{
	int i;
	for (i = 0; i < m_stdnum; i++) // 입력받은 학생 수 만큼 돌면서
	{
		if (stdname == (m_std + i)->GetName()) // 입력받은 이름과 등록되어있는 이름을 비교
		{
			return m_std + i; // 일치하는 이름을 찾았으면, 해당 학생정보가 있는 메모리 주소를 리턴
			break;
		}
		else
			continue; // 일치하는 과목을 찾지 못했다면, 계속 다음 반복을 수행
	}
	if (i == m_stdnum) // 일치하는 학생을 찾지 못했을 경우
	{
		cout << "일치하는 학생이 없습니다. \n"; // 메세지 출력
		return NULL;
	}


}

void GradeManager::Printmenu() // 전체 메뉴 출력
{
	cout << endl;
	cout << "========= 메뉴 =========" << endl;
	cout << "1. 학생 성적 입력 " << endl;
	cout << "2. 전체 학생 성적 보기" << endl;
	cout << "3. 학생 이름 검색" << endl;
	cout << "4. 전체 학생 목록 보기" << endl;
	cout << "5. 학생 정보 수정" << endl;
	cout << "6. 프로그램 종료" << endl;
	cout << endl;

	cout << "원하는 기능을 입력하세요(번호입력) :";

}
void GradeManager::PrintAllStdList()const // 전체 학생 리스트 출력
{
	cout << "====================================\n";
	cout.width(15);
	cout << "학번";
	cout.width(15);
	cout << "이름\n";
	cout << "====================================\n";
	for (int i = 0; i < m_stdnum; i++)
	{
		cout.width(15);
		cout << (m_std + i)->GetHakbun(); // m_std가 가리키는 곳의 학번 출력
		cout.width(15);
		cout << (m_std + i)->GetName() << "\n"; // m_std가 가리키는 곳의 이름 출력
	}
	cout << "====================================\n";
	cout << "\n";
}
void GradeManager::Modify() // 원하는 학생의 정보 수정하기
{
	cout << "검색할 학생의 이름:";
	string name;
	InputUtil::InputValue(name);
	Student* std = StdSearch(name); // 수정하고자 하는 학생의 이름이 있는지 검색
	if (std == NULL) // 찾고자 하는 학생이 없으면 리턴
		return;
	else
		std->Modify(); // 일치하는 이름을 발견했다면, 학생정보 수정(Student 클래스의 멤버함수 이용)

}
void GradeManager::Execute() // 학생 성적 관리 함수_ 전체적인 실행을 담당
{
	while (1)
	{
		int num;
		Printmenu();
		InputUtil::InputValue(num); // 메뉴번호 입력받기

		if (num == 1) // 1이면, 학생성적 입력
		{
			for (int i = 0; i < m_stdnum; i++)
			{
				m_std[i].InputData();
			}
		}

		if (num == 2) // 2이면 전체 학생 성적 보기
		{
			for (int i = 0; i < m_stdnum; i++)
			{
				m_std[i].PrintData();
			}
		}
		if (num == 3) // 3이면 학생 검색 -> 검색한 학생의 성적 정보 출력
		{
			string stdname;
			cout << "검색할 학생 이름:";
			InputUtil::InputValue(stdname);
			Student* std = StdSearch(stdname);
			if (std != NULL)
			{
				std->PrintData();
			}
		}
		if (num == 4) // 4이면, 전체학생 목록 출력
		{
			PrintAllStdList();
		}
		if (num == 5) // 학생 정보 수정
		{
			Modify();
		}
		if (num !=1 && num != 2 && num != 3 && num != 4 && num != 5) // 프로그램 종료
		{
			cout << "프로그램을 종료합니다.";
			break;
		}
	}
}
