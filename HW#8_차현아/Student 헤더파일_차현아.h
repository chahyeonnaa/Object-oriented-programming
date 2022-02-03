#pragma once
#include<iostream>
#include<string>
#include"Subject.h" // Subject Ŭ������ ������� ����
using namespace std;

class Student {
protected:
	string m_name; // �л� �̸�
	int m_hakbun;  // �й�
	int m_subnum;  // ������ ���� ��
	Subject* m_sub; // ������ �����
	float m_aveGPA; // ������ ������� ��� ����

public:
	void Initialize(); // ������� �ʱ�ȭ
	void Initialize(string, int, int, Subject*); // ���ڰ����� ������� �ʱ�ȭ
	void Remove(); // �����޸� ����(m_sub)
	void InputValue(string&);
	void InputValue(int&);
	void InputData(); // ������� �� �Է�
	void PrintData(); // ������� �� ���
	void CalcAveGPA(float sum, float haksum); // ��� ���� ���

	string GetName(); // �������Լ� : Ŭ���� �ۿ��� ��������� ���� �� �ְ���.
	int GetHakbun();
	int GetSubNum();
	float GetAveGPA();

	friend void Showdata(const Student& s); // �����Լ��� friend �Լ��� �����Ͽ� ���� �ӽ� ���

};