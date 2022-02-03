#include<iostream>
#include<string> //string Ŭ������ ����ϱ� ���� �������
#include"Student.h"
#include"Subject.h"
#include"InputUtil.h"
#include "IOInterface.h"
using namespace std;

Student::Student()//����Ʈ ������_ ������ ����� ȣ��
{
	m_name = "";
	m_hakbun = 0;
	m_subnum = 0;
	m_sub = NULL;
	m_aveGPA = 0.0;
	cout << "* Student ����Ʈ ������ ȣ�� *\n";

}

Student::Student(string name, int hakbun, int subnum, Subject* sub)
{
	m_name = name; // �Է¹��� name�� ������� m_name�� �־��� 
	m_hakbun = hakbun;
	m_subnum = subnum;

	m_sub = new Subject[m_subnum]; // m_sub�� ���ο� ���� ���� �Ҵ�

	for (int i = 0; i < m_subnum; i++) // �Է¹��� ���� ����ŭ
	{
		(m_sub + i)->SetName((sub + i)->GetName()); // sub�� �����͵��� m_sub���� ������_ ������ �Լ� ���
		(m_sub + i)->SetHakjum((sub + i)->GetHakjum());
		(m_sub + i)->SetGrade((sub + i)->GetGrade());
		(m_sub + i)->SetGPA((sub + i)->GetGPA()); // 
	}


	cout << "* Student �����ִ� ������ ȣ�� *\n";
}

Student::~Student() // �Ҵ���� �޸� ���� ����
{
	cout << "Student �Ҹ��� ȣ��\n";
	delete[]m_sub;
	m_sub = NULL;
}


void Student::InputData() // ����ڷκ��� ������ �Է� �ޱ�
{
	cout << "*" << "�л� �̸��� �й��� �Է��ϼ���.\n";
	cout << "�̸� : ";
	InputUtil::InputValue(m_name); // ���ڰ� ���ڿ��̹Ƿ� ���ڿ� �Է� �Լ� ȣ��
	cout << "�й� : ";
	InputUtil::InputValue(m_hakbun); // ���ڰ� �����̹Ƿ� ������ �Է� �Լ� ȣ��
	cout << "\n";

	cout << "������ ���� �� �Է� :";
	InputUtil::InputValue(m_subnum);

	m_sub = new Subject[m_subnum]; // �Է¹��� ���� �� ��ŭ ���� ���� ������ �����Ҵ�
	float sum = 0; // ��� ������ ���ؼ� ���� ����
	float haksum = 0; // ��ü ���� ���� ���ؼ� ���� ����

	for (int j = 0; j < (m_subnum); j++)
	{
		cout << "* ������ ������" << m_subnum << "���� �� �������, ��������, �������� �Է��ϼ���.\n";
		(m_sub + j)->InputData(); // �Ѱ��� ���� ���� �Է�
	}

	for (int j = 0; j < (m_subnum); j++)
	{
		haksum = haksum + (m_sub + j)->GetHakjum(); // �� ������ �������� ���Ͽ� ������ ���� �Ҵ�_������ �Լ��� ����Ͽ� ���ٰ���
		sum = sum + (m_sub + j)->GetGPA(); // �� ������ ������ ���Ͽ� ������ �Ҵ�_������ �Լ��� ����Ͽ� ���ٰ���
	}
	CalcAveGPA(sum, haksum); // ������� ���

}

void Student::CalcAveGPA(float sum, float haksum) // ��ü ���� ����� ����ϴ� �Լ�
{
	m_aveGPA = sum / haksum; // �������� ��/ �� ���� ��
}

void Student::PrintData() const// ���� ���
{

	cout.width(10);
	cout << "�̸� : " << m_name; // �̸����
	cout.width(10);
	cout << "�й� : " << m_hakbun << "\n" << "\n"; // �й����
	cout.width(20);

	m_sub->PrintTitle(); //Subject Ŭ������ PrintTitle() ȣ��

	for (int p = 0; p < m_subnum; p++) // �Է¹��� ����� ��ŭ �ݺ����� ���鼭
	{
		(m_sub + p)->PrintData(); // �� ���� ���� ���
		
	}
	cout << "--------------------------------------------------------------------\n";
	cout.width(45);
	cout << "��� ���� :" << m_aveGPA << "\n" << "\n";

}


void Student::Modify()
{
	cout << "*< " << m_name << "  " << m_hakbun << " >�� ������ �����ϼ���\n";
	cout << "�̸� : ";
	InputUtil::InputValue(m_name); // ���ڰ� ���ڿ��̹Ƿ� ���ڿ� �Է� �Լ� ȣ��
	cout << "�й� : ";
	InputUtil::InputValue(m_hakbun);
	cout << "\n";
}

Subject* Student::SubSearch(string subname)const // ����Ž��_ ���� ���� ���������ʱ� ������ const ����Լ��� ����
{
	int i;
	for (i = 0; i < m_subnum; i++) // �����ϴ� ������ ����ŭ �ݺ�
	{
		if (subname == (m_sub + i)->GetName()) // �Է¹��� ����� ���� ������� ���ʴ�� ��
		{
			return m_sub + i;
			break;
		}
		else
			continue; // ��ġ�ϴ� ������ ã�� ���ߴٸ�, ��� ���� �ݺ��� ����
	}
	if (i == m_subnum)
	{
		cout << "��ġ�ϴ� ������ �����ϴ�. \n"; // ��ġ�ϴ� ������ ���� ���, �޼��� ���
		return NULL;
	}

}


string Student::GetName()// �������Լ� : Ŭ���� �ۿ��� ��������� ���� �� �ְ���					   // ���� ���� ���������ʱ� ������ const ����Լ��� ����
{
	return m_name;
}

int Student::GetHakbun()const
{
	return m_hakbun;
}

int Student::GetSubNum()const
{
	return m_subnum;
}

float Student::GetAveGPA()const
{
	return m_aveGPA;
}
