/*********************************************************/
/*        HW#11 : ��� �ǽ�                              */
/*  �ۼ��� : ������        ��¥ : 2021�� 6�� 4��         */
/*                                                       */
/* ���� ���� : ��ü�������� ����ó�����α׷� #5 �ۼ�   */
/*             1. ����ã�� IOInterface �����ϱ�          */
/*             2. �⺻Ŭ������ �Ļ�Ŭ������ ����         */
/*             3. Modify() ����Լ� ����                 */
/*********************************************************/
#include"Subject.h" // Subject Ŭ������ StudentŬ������ ����ϱ� ���� ��������� ����
#include"Student.h"
#include "IOInterface.h"
#include"GradeManager.h"
#include<iostream>
#include<string> //string Ŭ������ ����ϱ� ���� �������
using namespace std;

int main(void)
{
	/* 1. �߻� Ŭ���� Ȯ��*/
	Student std; // Student Ŭ������ std ��ü����
	std.InputData(); // �л� ���� �Է¹ޱ�

	IOInterface* IO[2] = { new Subject("������",3,"A+"),&std }; // �߻� Ŭ������ �����͹迭 ����
	                                                            // �Ļ� Ŭ������ ��ü�� ����ų �� ����
	for (int i = 0; i < 2; i++)
	{
		cout << "\n *" << i + 1 << "��° ������ :" << "\n";
		IO[i]->PrintData(); // �Ļ�Ŭ������ ����Լ��� ȣ��Ǿ����_ �߻� Ŭ���� �� ���� �����Լ��̱� ������ ����
	}

	/* 2. GradeManager Class �׽�Ʈ*/
	//int stdnum; // �л� ���� �޴� ����

	//cout << "�Է��� �л� ���� �Է� :";
	//InputUtil::InputValue(stdnum); // �л� �� �Է�
	//cout << endl;

	//GradeManager GradeMgr(stdnum); // �л� ������ ������ �����ϴ� Ŭ������ ��ü ����
	//GradeMgr.Execute(); // �л� ������ �����ϴ� �Լ� ����
}
