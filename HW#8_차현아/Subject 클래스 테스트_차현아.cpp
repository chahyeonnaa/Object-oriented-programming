/*****************************************************/
/*             HW#8 : Ŭ���� ���� �ǽ�               */
/*  �ۼ��� : ������        ��¥ : 2021�� 5�� 7��     */
/*                                                   */
/* ���� ���� :��ü�������� ����ó�� ���α׷�#1 �ۼ�*/
/*            1. Subject Class �׽�Ʈ(������������)   */
/******************************************************/

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
// Ŭ������ ������_��� �Լ� ����
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

int main()
{
	Subject sub1, sub2, sub3[2], * sub4; // �Ϲݰ�ü, ��ü�迭, ��ü ������ ����
	int i;

	sub1.Initialize(); // sub1�� ��������� �ʱ�ȭ
	sub2.Initialize("������", 3, "A+"); //sub2�� ������ ���� ���������� �־���.
	for (int i = 0; i < 2; i++)
		sub3[i].Initialize("��ǻ��", 3, "C0"); //sub3�� ������ ���� ������������ ���ʴ�� �־���.

	sub4 = new Subject[2]; // �ΰ����� ���� �� �ִ� ���� �Ҵ��Ͽ� sub4 �� ����Ű����.

	sub1.InputData(); //sub1�� ���� ���� �Է¹ޱ�
	cout << "\n" << "sub1 ����" << "\n";
	sub1.PrintTitle();
	sub1.PrintData(); //sub1�� ���� ���� ���

	cout << "\n" << "sub2 ����" << "\n";
	sub2.PrintTitle();
	sub2.PrintData(); //sub2�� ���� ���� ���

	cout << "\n" << "sub3 ����" << "\n";
	sub3[0].PrintTitle();
	for (i = 0; i < 2; i++)
		sub3[i].PrintData(); //sub3�� �������� ���

	for (i = 0; i < 2; i++)
		(sub4 + i)->InputData(); // sub4�� �������� ���� �Է¹ޱ�
	cout << "\n" << "sub4 ����" << "\n";
	sub4->PrintTitle();
	for (i = 0; i < 2; i++)
		(sub4 + i)->PrintData(); // sub4�� �������� ���

	delete[]sub4; // ������ �Ҵ���� sub4�� �޸� ���� ����

}


