/*********************************************************/
/*        HW#11 : ��� �ǽ�                              */
/*  �ۼ��� : ������        ��¥ : 2021�� 5�� 28��        */
/*                                                       */
/* ���� ���� : ��ü�������� ����ó�����α׷� #4 �ۼ�   */
/*             1. ����ã�� IOInterface �����ϱ�          */
/*             2. �⺻Ŭ������ �Ļ�Ŭ������ ����         */
/*             3. Modify() ����Լ� ����                 */
/*********************************************************/
#include"Subject.h" // Subject Ŭ������ StudentŬ������ ����ϱ� ���� ��������� ����
#include"Student.h"
#include "IOInterface.h"
#include<iostream>
#include<string> //string Ŭ������ ����ϱ� ���� �������
using namespace std;

int main(void)
{
	/* 1. ����ã�� IOInterface �����ϱ�*/
	Student std; // ����Ʈ ������ ȣ��_ �θ� Ŭ������ ����Ʈ �����ڸ� ����ڰ� ���� ��������
	cout << std.GetData() << "\n"; // �θ�Ŭ�������� ��ӹ��� ����Լ� ȣ��

	/* 2. �⺻Ŭ������ �Ļ�Ŭ������ ����*/
	//Subject sub("��ǻ��", 3, "B+"); // �θ�Ŭ������ �����ڰ� ���� ȣ��ǰ� ���� �Ļ�Ŭ������ �����ڰ� ȣ���.
	//cout << "---------------------------------\n";
	//cout << "m_data : " << sub.GetData(); // IOInterface ���� ��ӹ��� GetData()ȣ��
	//cout << "\n";
	//cout << "������ �̸� : " << sub.GetName(); // Subject Ŭ�������� �����ǵ� GetName() ȣ��
	//cout << "\n";
	//cout << "�θ� Ŭ������ �̸� : " << sub.IOInterface::GetName(); // IOInterface�� GetName() ȣ��
	//cout << "\n";
	//cout << "---------------------------------\n";

	//Student std2("ȫ�浿", 2020039009, 1, &sub); // �θ�Ŭ���� ������ ���� ȣ��-> sub ������ �θ� ����Ʈ ������ ȣ��
	//cout << "---------------------------------\n";
	//cout << "m_data : " << std2.GetData(); // IOInterface ���� ��ӹ��� GetData()ȣ��
	//cout << "\n";
	//cout << "�л� �̸� : " << std2.GetName(); // Subject Ŭ�������� �����ǵ� GetName() ȣ��
	//cout << "\n";
	//cout << "�θ� Ŭ������ �̸� : " << std2.IOInterface::GetName(); // IOInterface�� GetName() ȣ��
	//cout << "\n";
	//cout << "---------------------------------\n";

	/* 3. Modify() ����Լ� ���� */
	//Subject sub("��ǻ��", 3, "C0");
	//Student std("ȫ�浿", 2020039009, 1, &sub);

	//std.PrintData(); // ���� �� ��� ���
	//std.Modify();
	//std.PrintData(); // ���� �� ��� ���

}