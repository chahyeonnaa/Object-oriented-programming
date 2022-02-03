#pragma once
#include "IOInterface.h"
#include<iostream>
#include<string>
#include"Subject.h" // Subject Ŭ������ ������� ����
using namespace std;

class Student : public IOInterface { // IOInterface Ŭ������ ��ӹ���
protected:
	string m_name;
	int m_hakbun;  // �й�
	int m_subnum;  // ������ ���� ��
	Subject* m_sub; // ������ �����
	float m_aveGPA; // ������ ������� ��� ����

public:
	virtual void InputData(); // ������� �� �Է�
	virtual void PrintData()const; // ������� �� ���
	void CalcAveGPA(float sum, float haksum); // ��� ���� ���
	virtual void Modify(); // �л� ���� ����
	Subject* SubSearch(string subname)const; // ����Ž��_ ���� ���� �����ϴ� �Լ��� �ƴ�

	Student(); // ����Ʈ ������ = �Ű����� ���� ������
	Student(string name, int hakbun, int subnum, Subject* sub); // �����ִ� ������
	virtual ~Student(); // �Ҹ���

	string GetName(); // �������Լ� : Ŭ���� �ۿ��� ��������� ���� �� �ְ���_���� ���� �����ϴ� �Լ��� �ƴ�
	int GetHakbun()const;
	int GetSubNum()const;
	float GetAveGPA()const;


};
