#pragma once
#include "IOInterface.h"
#include<iostream>
#include<string>
using namespace std;

class Subject : public IOInterface {// IOInterface Ŭ������ ��� ����
protected: // Ŭ���� �ڽŰ� ��ӹ��� �ڽ� Ŭ�������� ���
	string m_name;
	int m_hakjum;  // ����
	string m_grade; // ���
	float m_GPA;    // ����

public:
	virtual void InputData(); // ������� �� �Է�_���������� InputValue() �̿� 
	static void PrintTitle(); // ��������� ���� Title Text ���
	virtual void PrintData()const; // ������� �� ���
	void CalcGPA(); // �������
	virtual void Modify(); // ���� ���� ����

	Subject(); // ����Ʈ ������
	Subject(string name, int hakjum, string grade); // �����ִ� ������
	virtual ~Subject(); // �Ҹ���

	string GetName(); // ������ �Լ�(Ŭ���� ��� ������ ���� ���� ���)
	int GetHakjum()const;
	string GetGrade()const;
	float GetGPA()const;

	void SetName(string name); // ���� ����� �������� �����͸� �״�� �����ؼ� ���ο� ������
							   // �����ؾ� �ϱ� ������ Set������ �Լ� ���
	void SetHakjum(int num);
	void SetGrade(string gra);
	void SetGPA(float num);


};
