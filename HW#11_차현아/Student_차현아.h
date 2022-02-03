#pragma once
#include "IOInterface.h"
#include<iostream>
#include<string>
#include"Subject.h" // Subject Ŭ������ ������� ����
using namespace std;

class Student : public IOInterface { // IOInterface Ŭ������ ��ӹ���
protected:
	int m_hakbun;  // �й�
	int m_subnum;  // ������ ���� ��
	Subject* m_sub; // ������ �����
	float m_aveGPA; // ������ ������� ��� ����

public:
	void InputData(); // ������� �� �Է�
	void PrintData(); // ������� �� ���
	void CalcAveGPA(float sum, float haksum); // ��� ���� ���
	void Modify(); // �л� ���� ����
	Subject* SubSearch(string subname)const; // ����Ž��_ ���� ���� �����ϴ� �Լ��� �ƴ�

	Student(); // ����Ʈ ������ = �Ű����� ���� ������
	Student(string name, int hakbun, int subnum, Subject* sub); // �����ִ� ������
	~Student(); // �Ҹ���

	string GetName(); // �������Լ� : Ŭ���� �ۿ��� ��������� ���� �� �ְ���_���� ���� �����ϴ� �Լ��� �ƴ�
	int GetHakbun()const;
	int GetSubNum()const;
	float GetAveGPA()const;


};

