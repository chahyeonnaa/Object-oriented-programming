#include "IOInterface.h"
#include"Subject.h"
#include"InputUtil.h"
#include"Student.h"
#include"GradeManager.h"
#include<iostream>
#include<string>
using namespace std;

GradeManager::GradeManager() // ����Ʈ ������
{
	m_std = NULL;
	m_stdnum = 0;
}

GradeManager::GradeManager(int m_stdnum) // �����ִ� ������
{
	m_std = new Student[m_stdnum]; // �Է¹��� �л� �� ��ŭ�� ������ �����Ҵ�
	this->m_stdnum = m_stdnum;
}
int GradeManager::Getstdnum()const // �������Լ� : m_stdnum�� Ŭ���� �ۿ��� ���� �� �ְ���.
{
	return m_stdnum;
}
GradeManager::~GradeManager() // �Ҹ���_ �����Ҵ� ���� ���� ����
{
	delete[] m_std;
	cout << "GradeManager �Ҹ��� ȣ��\n";
}
Student* GradeManager::StdSearch(string stdname)const // �л� �˻�(ã�����ϴ� �л��� �Լ��� ���ڷ� ����) 
{
	int i;
	for (i = 0; i < m_stdnum; i++) // �Է¹��� �л� �� ��ŭ ���鼭
	{
		if (stdname == (m_std + i)->GetName()) // �Է¹��� �̸��� ��ϵǾ��ִ� �̸��� ��
		{
			return m_std + i; // ��ġ�ϴ� �̸��� ã������, �ش� �л������� �ִ� �޸� �ּҸ� ����
			break;
		}
		else
			continue; // ��ġ�ϴ� ������ ã�� ���ߴٸ�, ��� ���� �ݺ��� ����
	}
	if (i == m_stdnum) // ��ġ�ϴ� �л��� ã�� ������ ���
	{
		cout << "��ġ�ϴ� �л��� �����ϴ�. \n"; // �޼��� ���
		return NULL;
	}


}

void GradeManager::Printmenu() // ��ü �޴� ���
{
	cout << endl;
	cout << "========= �޴� =========" << endl;
	cout << "1. �л� ���� �Է� " << endl;
	cout << "2. ��ü �л� ���� ����" << endl;
	cout << "3. �л� �̸� �˻�" << endl;
	cout << "4. ��ü �л� ��� ����" << endl;
	cout << "5. �л� ���� ����" << endl;
	cout << "6. ���α׷� ����" << endl;
	cout << endl;

	cout << "���ϴ� ����� �Է��ϼ���(��ȣ�Է�) :";

}
void GradeManager::PrintAllStdList()const // ��ü �л� ����Ʈ ���
{
	cout << "====================================\n";
	cout.width(15);
	cout << "�й�";
	cout.width(15);
	cout << "�̸�\n";
	cout << "====================================\n";
	for (int i = 0; i < m_stdnum; i++)
	{
		cout.width(15);
		cout << (m_std + i)->GetHakbun(); // m_std�� ����Ű�� ���� �й� ���
		cout.width(15);
		cout << (m_std + i)->GetName() << "\n"; // m_std�� ����Ű�� ���� �̸� ���
	}
	cout << "====================================\n";
	cout << "\n";
}
void GradeManager::Modify() // ���ϴ� �л��� ���� �����ϱ�
{
	cout << "�˻��� �л��� �̸�:";
	string name;
	InputUtil::InputValue(name);
	Student* std = StdSearch(name); // �����ϰ��� �ϴ� �л��� �̸��� �ִ��� �˻�
	if (std == NULL) // ã���� �ϴ� �л��� ������ ����
		return;
	else
		std->Modify(); // ��ġ�ϴ� �̸��� �߰��ߴٸ�, �л����� ����(Student Ŭ������ ����Լ� �̿�)

}
void GradeManager::Execute() // �л� ���� ���� �Լ�_ ��ü���� ������ ���
{
	while (1)
	{
		int num;
		Printmenu();
		InputUtil::InputValue(num); // �޴���ȣ �Է¹ޱ�

		if (num == 1) // 1�̸�, �л����� �Է�
		{
			for (int i = 0; i < m_stdnum; i++)
			{
				m_std[i].InputData();
			}
		}

		if (num == 2) // 2�̸� ��ü �л� ���� ����
		{
			for (int i = 0; i < m_stdnum; i++)
			{
				m_std[i].PrintData();
			}
		}
		if (num == 3) // 3�̸� �л� �˻� -> �˻��� �л��� ���� ���� ���
		{
			string stdname;
			cout << "�˻��� �л� �̸�:";
			InputUtil::InputValue(stdname);
			Student* std = StdSearch(stdname);
			if (std != NULL)
			{
				std->PrintData();
			}
		}
		if (num == 4) // 4�̸�, ��ü�л� ��� ���
		{
			PrintAllStdList();
		}
		if (num == 5) // �л� ���� ����
		{
			Modify();
		}
		if (num !=1 && num != 2 && num != 3 && num != 4 && num != 5) // ���α׷� ����
		{
			cout << "���α׷��� �����մϴ�.";
			break;
		}
	}
}
