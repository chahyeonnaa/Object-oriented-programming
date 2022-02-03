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
	Student* m_std; // ��ü�л� ������ ����ִ� ��ü
	int m_stdnum; // �����ϰ� �ִ� ��ü �л� ��
public:
	GradeManager(); // ����Ʈ ������
	GradeManager(int m_stdnum); // �����ִ� ������
	~GradeManager(); // �Ҹ���
	void Execute(); // �л� ������ �����ϴ� �Լ�
	int Getstdnum()const;
protected:
	static void Printmenu(); // �޴����
	Student* StdSearch(string stdname)const; // ���ϴ� �л� �˻�
	void PrintAllStdList()const; // ��ü �л� ��� ���
	void Modify(); // ���ϴ� �л��� ���� ����

};
