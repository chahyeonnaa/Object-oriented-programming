#pragma once
#include<iostream>
#include<string> //string Ŭ������ ����ϱ� ���� �������
using namespace std;

// Ŭ������ �����
class Subject { 
protected: // Ŭ���� �ڽŰ� ��ӹ��� �ڽ� Ŭ�������� ���
	string m_name; // �����
	int m_hakjum;  // ����
	string m_grade; // ���
	float m_GPA;    // ����

public:
	void Initialize(); // ������� �ʱ�ȭ
	void Initialize(string, int, string);
	void InputValue(string&); // �Է��� ���� �Լ�
	void InputValue(int&);
	void InputData(); // ������� �� �Է�_���������� InputValue() �̿� 
	void PrintTitle(); // ��������� ���� Title Text ���
	void PrintData(); // ������� �� ���
	void CalcGPA(); // �������

	string GetName(); // ������ �Լ�(Ŭ���� ��� ������ ���� ���� ���)
	int GetHakjum();
	string GetGrade();
	float GetGPA();

};

