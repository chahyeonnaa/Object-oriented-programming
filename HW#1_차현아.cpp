/**************************************************/
/*             HW#1 : C++ �����ϱ�                */
/*  �ۼ��� : ������        ��¥ : 2021�� 3�� 14�� */
/*                                                */
/* ���� ���� : ����ó�����α׷�                   */
/* �л� ����, ������ ���õ� ������ �Է� �ް� �� ���������� �л��� ��� ������ ���Ͽ� ��� ���� ����ϴ� ���α׷��Դϴ�. */
/*************************************************/
#include<iostream>
#include<cstring>
using namespace std;

int num; // �޴���ȣ�� �޴� ����
double er = 0; // �� ���������� ���� ���� ���� ���� ���� (�ݺ����� �̿�)
int haksum=0; // ������ ������ ���� ���� ����- �� ���� ��꿡 ����.

struct Subject { /*���� ����*/
	char SubName[30]; // �����̸�
	int Hakjumm;      // ��������
	char Grade[10];   // ������
	float GPA;        // ��������
};
struct Student { /*�л� ����*/
	char StdName[30]; // �л��̸�
	int Hakbun;       // �й�
	Subject Sub[3];   // ����
	float AveGPA;     //������ ��� ����
};

struct Student st[2]; // 2���� �л� ������ �Է¹��� ����

void pri_Menu() // �޴��� ����ϰ�, �޴���ȣ�� �Է¹޴� �Լ�
{
	cout << "===== �޴� =====\n";
	cout << "1. �л� ���� �Է�\n" << "2. ��ü �л� ���� ����\n" << "3. ���α׷� ����\n";
	cout << "���ϴ� ����� �Է��ϼ��� :";
	cin >> num;
}

void convert_number(int i, int j) // ������ ������������ �ٲ��ִ� �Լ�
{
	if (st[i].Sub[j].Grade[0] == 'A') // [0]���� ���� ���� �ԷµǴ� ���ĺ��� �������� ��ġȭ
		st[i].Sub[j].GPA = 4.0;
	else if (st[i].Sub[j].Grade[0] == 'B')
		st[i].Sub[j].GPA = 3.0;
	else if (st[i].Sub[j].Grade[0] == 'C')
		st[i].Sub[j].GPA = 2.0;
	else if (st[i].Sub[j].Grade[0] == 'D')
		st[i].Sub[j].GPA = 1.0;
	else if (st[i].Sub[j].Grade[0] == 'F')
		st[i].Sub[j].GPA = 0;

	if (st[i].Sub[j].Grade[1] == '+') //[1]���� +�� �ԷµǸ�, ������ ��Ҵ� ���ذ����� 
		st[i].Sub[j].GPA += 0.5;      // ���

}

void info_hak(int i, int j) // ������ ���� ���� �Է� �ޱ� 
{
	cout << "* ������ ������ 3���� �� �������, ��������, �������� �Է��ϼ���.\n";
	cout << "������ ��:"; cin >> st[i].Sub[j].SubName;
	cout << "���� ������:"; cin >> st[i].Sub[j].Hakjumm;
	cout << "������<A+ ~F>:"; cin >> st[i].Sub[j].Grade;
	switch (st[i].Sub[j].Grade[0]) // st[i].Sub[j].Grade[0]���� �� �� �Է��� ��Ȳ�� ��� 
	{
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F': // ����� �Է������� 
		break; // ����ġ�� Ż��
	default: // �� �� �Է��ߴٸ�, 
		while (1)
		{
			cout << "������<A+ ~F>:"; cin >> st[i].Sub[j].Grade; // ����� �� ���� �Էµ� ������ ��� �Է¹ޱ�
			if (st[i].Sub[j].Grade[0] == 'A' || st[i].Sub[j].Grade[0] == 'B' || st[i].Sub[j].Grade[0] == 'C' || st[i].Sub[j].Grade[0] == 'D' || st[i].Sub[j].Grade[0] == 'E' || st[i].Sub[j].Grade[0] == 'F')
				break;
		}
		break;
	}
	cout << "\n";
}

void info_stu() // �л� ���� �Է� �ޱ� - ������ ���� ���� �Է� �Լ� ����
{
	for (int i = 0; i < 2; i++) {
		cout << "*" << i + 1 << "��° �л� �̸��� �й��� �Է��ϼ���.\n";
		cout << "�̸� : ";
		cin >> st[i].StdName;
		cout << "�й� : "; cin >> st[i].Hakbun; cout << "\n";
		for (int j = 0; j < 3; j++) {
			info_hak(i, j); // ������ ���� ���� �Է¹ޱ�
		}
	}
}

void info_resul(int i, int j) // ���� ���� ���
{
	double sum; // �� ������ ������� ���� ���� ����
	cout.width(15);
	cout << st[i].Sub[j].SubName;
	cout.width(15);
	cout << st[i].Sub[j].Hakjumm;
	cout.width(15);
	cout << st[i].Sub[j].Grade;
	cout.width(15);
	sum = st[i].Sub[j].GPA * st[i].Sub[j].Hakjumm; // �� ������ ������� = ���� * ����
	cout.width(15);
	cout << sum;
	haksum += st[i].Sub[j].Hakjumm;
	er = er + sum; // �� ������ ������ ���� ���� er�� �ִ� ����
}

int main(void)
{
	while (1)
	{
		pri_Menu();
		if (num == 1) {// num�� ���� 1�̶�� �л� ���� �Է� �ޱ�
			info_stu(); // �л� ���� �Է� �ޱ� - ������ ���� ���� �Է� �Լ� ����
			pri_Menu();
		}
		if (num == 2)
		{
			cout << "\n";
			cout.width(45);
			cout << "��ü �л� ���� ����\n";
			cout << "====================================================================\n";
			for (int i = 0; i < 2; i++)
			{
				cout.width(10);
				cout << "�̸� : " << st[i].StdName; // �̸����
				cout.width(10);
				cout << "�й� : " << st[i].Hakbun << "\n"; // �й����
				cout << "====================================================================\n";
				cout.width(15);
				cout << "�����" << "            ��������" << "      ������ " << "      �������� " << "\n";
				cout << "====================================================================\n";

				for (int j = 0; j < 3; j++) // 3�����̱� ������ 3�� �ݺ�
				{
					convert_number(i, j); // ���ĺ� ������ ���ڷ� ��ȯ
					cout.precision(2);
					cout << fixed;
					info_resul(i, j); // ���� ���λ��� ���
					cout.width(10);
					cout << "\n";
				}
				st[i].AveGPA = er / haksum; // ������� = �� ���� �������� ��/ �� ����
				cout << "====================================================================\n";
				cout.width(45);
				cout << "��� ���� :" << st[i].AveGPA << "\n";
				cout << "\n";
				er = 0; // ���� �ݺ��� ���ؼ� �ʱ�ȭ
				haksum = 0; // ���� �ݺ��� ���ؼ� �ʱ�ȭ
			}
		}
		pri_Menu();
		if (num != 1 && num != 2) // num�� 1�� 2 �̿��� ���̸�, ���ѹݺ��� Ż��
		{
			cout << "���α׷��� �����մϴ�.";
			break;
		}
	}
}