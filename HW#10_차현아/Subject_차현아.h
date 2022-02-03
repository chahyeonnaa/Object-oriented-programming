#pragma once
#include<iostream>
#include<string> //string Ŭ������ ����ϱ� ���� �������
using namespace std;

class Subject {
protected: // Ŭ���� �ڽŰ� ��ӹ��� �ڽ� Ŭ�������� ���
	string m_name; // �����
	int m_hakjum;  // ����
	string m_grade; // ���
	float m_GPA;    // ����

public:
	void InputData(); // ������� �� �Է�_���������� InputValue() �̿� 
	static void PrintTitle(); // ��������� ���� Title Text ���
	void PrintData(); // ������� �� ���
	void CalcGPA(); // �������
	void Modify(); // ���� ���� ����

	Subject(); // ����Ʈ ������
	Subject(string name, int hakjum, string grade); // �����ִ� ������
	Subject(const Subject& sub); // ���������
	~Subject(); // �Ҹ���

	string GetName()const; // ������ �Լ�(Ŭ���� ��� ������ ���� ���� ���)
	int GetHakjum()const;
	string GetGrade()const;
	float GetGPA()const;

	void SetName(string name); // ���� ����� �������� �����͸� �״�� �����ؼ� ���ο� ������
							   // �����ؾ� �ϱ� ������ Set������ �Լ� ���
	void SetHakjum(int num);
	void SetGrade(string gra);
	void SetGPA(float num);


};
