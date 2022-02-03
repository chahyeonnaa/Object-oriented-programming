#include<iostream>
#include<string> //string Ŭ������ ����ϱ� ���� �������
#include"Student.h"
using namespace std;

void Student::Initialize() // ��� ���� �ʱ�ȭ
{
	m_name = "";
	m_hakbun = 0;
	m_subnum = 0;
	m_sub = NULL;
	m_aveGPA = 0.0;

}

void Student::Initialize(string str, int hak, int sub, Subject* ject)
// �޾ƿ� �Ű��������� ������� ������ �Ҵ�_ *�迭�� �����ͷ� �޴´�.
{
	m_name = str;
	m_hakbun = hak;
	m_subnum = sub;
	m_sub = ject;
}

void Student::InputValue(string& str) // ���ڿ� �Է��� ���� �Լ�
{
	getline(cin, str);
}

void Student::InputValue(int& i) // ���� �Է��� ���� �Լ�
{
	cin >> i;
	cin.ignore(); // ���� ����
}


void Student::Remove() // �Ҵ���� �޸� ���� ����
{
	delete[]m_sub;
}

void Student::InputData() // ����ڷκ��� ������ �Է� �ޱ�
{
	cout << "*" << "�л� �̸��� �й��� �Է��ϼ���.\n";
	cout << "�̸� : ";
	InputValue(m_name); // ���ڰ� ���ڿ��̹Ƿ� ���ڿ� �Է� �Լ� ȣ��
	cout << "�й� : ";
	InputValue(m_hakbun);
	cout << "\n"; // ���ڰ� �����̹Ƿ� ������ �Է� �Լ� ȣ��

	cout << "������ ���� �� �Է� :";
	InputValue(m_subnum);

	m_sub = new Subject[m_subnum]; // �Է¹��� ���� �� ��ŭ ���� ���� ������ �����Ҵ�


	for (int j = 0; j < (m_subnum); j++)
	{
		cout << "* ������ ������" << m_subnum << "���� �� �������, ��������, �������� �Է��ϼ���.\n";
		(m_sub + j)->InputData(); // �Ѱ��� ���� ���� �Է�
	}

}

void Student::CalcAveGPA(float sum, float haksum) // ��ü ���� ����� ����ϴ� �Լ�
{
	m_aveGPA = sum / haksum; // �������� ��/ �� ���� ��
}

void Student::PrintData() // ���� ���
{
	float sum = 0; // ��� ������ ���ؼ� ���� ����
	float haksum = 0; // ��ü ���� ���� ���ؼ� ���� ����
	cout << "====================================================================\n";
	cout.width(10);
	cout << "�̸� : " << m_name; // �̸����
	cout.width(10);
	cout << "�й� : " << m_hakbun << "\n" << "\n"; // �й����
	cout.width(20);

	m_sub->PrintTitle(); //Subject Ŭ������ PrintTitle() ȣ��

	for (int p = 0; p < m_subnum; p++) // �Է¹��� ����� ��ŭ �ݺ����� ���鼭
	{
		(m_sub + p)->PrintData(); // �� ���� ���� ���
		haksum = haksum + (m_sub + p)->GetHakjum(); // �� ������ �������� ���Ͽ� ������ ���� �Ҵ�_������ �Լ��� ����Ͽ� ���ٰ���
		sum = sum + (m_sub + p)->GetGPA(); // �� ������ ������ ���Ͽ� ������ �Ҵ�_������ �Լ��� ����Ͽ� ���ٰ���
	}

	cout << "--------------------------------------------------------------------\n";
	cout.width(45);
	CalcAveGPA(sum, haksum); // ������� ���
	cout << "��� ���� :" << m_aveGPA << "\n" << "\n";

}


string Student::GetName() // �������Լ� : Ŭ���� �ۿ��� ��������� ���� �� �ְ���.
{
	return m_name;
}

int Student::GetHakbun()
{
	return m_hakbun;
}

int Student::GetSubNum()
{
	return m_subnum;
}

float Student::GetAveGPA()
{
	return m_aveGPA;
}

