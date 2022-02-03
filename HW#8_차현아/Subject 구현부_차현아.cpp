#include<iostream>
#include<string> //string Ŭ������ ����ϱ� ���� �������
#include"Subject.h"
using namespace std;

// Ŭ������ ������
void Subject::Initialize() // ��� ���� �ʱ�ȭ
{
	m_name = "";
	m_hakjum = 0;
	m_grade = "";
	m_GPA = 0.0;
}

void Subject::Initialize(string name, int jum, string grade)
// �����͸� ����ڿ��� �Է¹��� ������, ������ �Ű������� �޾Ƽ� �ʱ�ȭ���ִ� �Լ�
{
	m_name = name; // ������� �ڸ��� ������ �Ҵ����ֱ�
	m_hakjum = jum;
	m_grade = grade;
}

inline void Subject::InputValue(string& str) // ���ڿ� �Է½�
{
	getline(cin, str);
}

inline void Subject::InputValue(int& i) // ���� �Է½�
{
	cin >> i;
	cin.ignore(); // ���� ����ֱ�
}


void Subject::CalcGPA() // �� ������ ���� ����ϱ� ex)3���� * 4.5 = 13.5
{
	if (m_grade == "A+") // string  ��ü�� ���ڿ� �񱳸� ���� GPA�� ���� �� �Ҵ�
		m_GPA = 4.5;
	else if (m_grade == "A0")
		m_GPA = 4.0;
	else if (m_grade == "B+")
		m_GPA = 3.5;
	else if (m_grade == "B0")
		m_GPA = 3.0;
	else if (m_grade == "C+")
		m_GPA = 2.5;
	else if (m_grade == "C0")
		m_GPA = 2.0;
	else if (m_grade == "D+")
		m_GPA = 1.5;
	else if (m_grade == "D0")
		m_GPA = 1.0;
	else if (m_grade == "F")
		m_GPA = 0;

	m_GPA = m_GPA * m_hakjum; // ������ ��ȯ�� ����� ���Ͽ� ���� ���

}

void Subject::InputData()// ����ڿ��� ��������� ���� ���� �Է¹���.
{
	cout << "������ ��:";
	InputValue(m_name); // ���ڰ� ���ڿ��̹Ƿ� ���ڿ� �Է� �Լ� ȣ��
	cout << "���� ������:";
	InputValue(m_hakjum); // ���ڰ� �����̹Ƿ� ������ �Է� �Լ� ȣ��
	cout << "������<A+ ~F>:";
	InputValue(m_grade); // ���ڰ� ���ڿ��̹Ƿ� ���ڿ� �Է� �Լ� ȣ��
	cout << "\n";

}

void Subject::PrintTitle() // ��������� ���� title �ؽ�Ʈ�� ȭ�鿡 ���
{
	cout << "====================================================================\n";
	cout.width(15);
	cout << "�������" << "            ������" << "        ��� " << "         ���� " << "\n";
	cout << "====================================================================\n";

}

void Subject::PrintData() // ��� ������ ���� ȭ�鿡 ���
{
	cout.precision(2);
	cout << fixed;
	cout.width(15);
	cout << m_name; // �����̸�
	cout.width(15);
	cout << m_hakjum; // ��������
	cout.width(15);
	cout << m_grade; // ������
	cout.width(15);
	CalcGPA();
	cout << m_GPA << "\n"; // �������

}

string Subject::GetName() // �������Լ� : m_name�� Ŭ���� �ۿ��� ���� �� �ְ���.
{
	return m_name;
}

int Subject::GetHakjum() // �������Լ� : m_hakjum�� Ŭ���� �ۿ��� ���� �� �ְ���.
{
	return m_hakjum;
}

float Subject::GetGPA() // �������Լ� : m_GPA�� Ŭ���� �ۿ��� ���� �� �ְ���.
{
	return m_GPA;
}

string Subject::GetGrade() // �������Լ� : m_grade�� Ŭ���� �ۿ��� ���� �� �ְ���.
{
	return m_grade;
}

