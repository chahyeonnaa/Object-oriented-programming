/*********************************************************/
/*        HW#10 : ����Լ��� Ŭ������ Ȱ�� �ǽ�          */
/*  �ۼ��� : ������        ��¥ : 2021�� 5�� 21��        */
/*                                                       */
/* ���� ���� : 1. Student class�� SubSearch ����Լ� �߰�*/
/*             2. �����������, const����Լ� �ۼ�       */
/*             3. InputUtil class �߰�                   */
/*             4. �������� ��ü����                      */
/*********************************************************/

#include"Subject.h" // Subject Ŭ������ StudentŬ������ ����ϱ� ���� ��������� ����
#include"Student.h"

#include<iostream>
#include<string> //string Ŭ������ ����ϱ� ���� �������
using namespace std;

void Data(const Student& s) //const��ü������ const��� �Լ��� ȣ�Ⱑ��_ 
							//�������Լ��� ��� const ����Լ��� �����Ͽ���.
{
	cout << s.GetName() << "�� ������ ������ �� " << s.GetSubNum() << "���� ";
	cout << "������ ������ ��������� " << s.GetAveGPA() << "�Դϴ�.\n";
}

int main(void)
{
	/* 1. SubSearch ����Լ� �׽�Ʈ*/
	Student std; // std �л� ��ü
	std.InputData(); // ������ �Է¹ޱ�
	std.PrintData(); // �л����� ���

	Subject* sub = std.SubSearch("������"); // ���� ������ ã��

	if (sub != NULL) // ã������, ������ ���� ���� ���_ ã�� �������� �޼��� ���
	{
		cout << "< ã�� ������ ���� >\n";
		sub->PrintTitle();
		sub->PrintData();
		cout << "\n";
	}

	/*2. ��������Լ��� const ����Լ� �׽�Ʈ*/
	//Subject sub1("��ǻ��", 3, "C0");
	//Subject sub2("����", 2, "A+");

	//Subject::PrintTitle();
	//sub1.PrintData(); // ������ ������ ���� ���� ���
	//sub2.PrintData();

	//Student st1("ȫ�浿", 2020039009, 1, &sub1); // sub1��ü�� ����
	//st1.PrintData();
	//Data(st1); // �����Լ� ȣ��

	/*3. ���� ��ü ������� �׽�Ʈ*/
	//Subject sub1[2] = { Subject("��ǻ��",3,"C+"),Subject("���빫��",2,"A0") };// ��ü�迭
	//Subject* sub2[2] = { new Subject(), new Subject("����",3,"B+") };// �����͹迭_ �ΰ��� ������
	//Student st1; // �Ϲ� ��ü
	//Student st2("ȫ�浿", 2020039009, 2, sub1); // st2�� sub1�� ����_�����ִ� ������
	//Student* st3 = new Student[2]; // ������ü�迭_ �л� �θ�

	//cout << "\n" << "sub2[0] �Է�" << "\n"; // �����Ҵ� ���� ����
	//sub2[0]->InputData();

	//cout << "\n" << "st1 �Է�" << "\n"; // �Ϲݰ�ü
	//st1.InputData();

	//cout << "\n" << "st3 �Է�" << "\n"; // ������ü�迭_�л� �θ�
	//for (int i = 0; i < 2; i++)
	//	(st3 + i)->InputData();

	//cout << "\n" << "sub1 �������(��,��)" << "\n"; // �����Ҵ� ���� ����
	//Subject::PrintTitle();
	//for (int i = 0; i < 2; i++)
	//	sub1[i].PrintData();

	//cout << "\n" << "sub2 �������(�Է�,����)" << "\n"; // �����Ҵ� ���� ����
	//Subject::PrintTitle();
	//for (int i = 0; i < 2; i++)
	//	sub2[i]->PrintData();

	//cout << "\n" << "st1 �������" << "\n"; // �Ϲݰ�ü
	//st1.PrintData();

	//cout << "\n" << "st2 �������" << "\n"; // �����ִ� ������
	//st2.PrintData();

	//cout << "\n" << "st3 �������" << "\n"; // ������ü�迭
	//for (int i = 0; i < 2; i++)
	//	(st3 + i)->PrintData();

}

