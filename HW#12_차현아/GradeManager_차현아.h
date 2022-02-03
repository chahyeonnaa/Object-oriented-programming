#pragma once
#include "IOInterface.h"
#include"Subject.h"
#include"InputUtil.h"
#include"Student.h"
#include<iostream>
#include<string>
using namespace std;

class GradeManager { 
protected:
	Student* m_std; // 전체학생 정보를 담고있는 객체
	int m_stdnum; // 관리하고 있는 전체 학생 수
public:
	GradeManager(); // 디폴트 생성자
	GradeManager(int m_stdnum); // 인자있는 생성자
	~GradeManager(); // 소멸자
	void Execute(); // 학생 성적을 관리하는 함수
	int Getstdnum()const;
protected:
	static void Printmenu(); // 메뉴출력
	Student* StdSearch(string stdname)const; // 원하는 학생 검색
	void PrintAllStdList()const; // 전체 학생 목록 출력
	void Modify(); // 원하는 학생의 정보 수정

};
