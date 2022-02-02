/*****************************************************/
/*             HW#4 : ������ �Լ� ���               */
/*  �ۼ��� : ������        ��¥ : 2021�� 4�� 2��     */
/*                                                   */
/* ���� ���� : ����ó�����α׷�#3                    */
/******************************************************/
#include<iostream>
#include<cstring>
using namespace std;

int num; // �޴���ȣ�� �޴� ����
float sum = 0; int haksum = 0;

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

inline void Print_Menu() // �޴��� ����ϰ�, �޴���ȣ�� �Է¹޴� �ζ��� �Լ�
{
	cout << "========= �޴� =========\n";
	cout << "1. �л� ���� �Է� \n" << "2. ��ü �л� ���� ����\n" << "3. �л� �̸� �˻�\n";
	cout << "4. ��ü �л� ��� ����\n" << "5. �л� ���� ����\n" << "6. ���α׷� ����\n";
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
void CalcGPA(Subject& Sub) // ����� ������ ���� ���ϱ� - �л� ������ ����ִ� ����ü ���� st�� ���۷��� Sub
{
	Sub.GPA = Sub.GPA * Sub.Hakjumm;

}
float CalcAveGPA(Subject* Sub, int j)// ������ ��� �������ϱ� - ���������� ����ִ� ����ü Subject�� ����Ű�� ����ü ������ Sub 
{
	sum = sum + Sub[j].GPA; // �� �������� ������ ���� �������� sum�� �ֱ�
	haksum = haksum + Sub[j].Hakjumm; // �� �������� ������ ���� �������� haksum�� �ֱ�
	return sum / haksum; // ������ ��� �������ϱ� = �� �������� ������ �� / �� ������ ������ �� ��

}
inline void InputValue(char* str) // ���������͸� ����ڷκ��� �Է¹ޱ� ���� �ζ��� �Լ�(���ڿ� �Է��� ����)
{
	cin >> str;
}
inline void InputValue(int& i) // ���������͸� ����ڷκ��� �Է¹ޱ� ���� �ζ��� �Լ�(���� �Է��� ����)
{
	cin >> i;
}
void info_hak(int i, int j) // ������ ���� ���� �Է� �ޱ� 
{
	cout << "* ������ ������ 3���� �� �������, ��������, �������� �Է��ϼ���.\n";
	cout << "������ ��:"; InputValue(st[i].Sub[j].SubName); // ���ڰ� ���ڿ��̹Ƿ� ���ڿ� �Է� �Լ� ȣ��
	cout << "���� ������:"; InputValue(st[i].Sub[j].Hakjumm); // ���ڰ� �����̹Ƿ� ������ �Է� �Լ� ȣ��
	cout << "������<A+ ~F>:"; InputValue(st[i].Sub[j].Grade); // ���ڰ� �����̹Ƿ� ������ �Է� �Լ� ȣ��
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
		InputValue(st[i].StdName); // ���ڰ� ���ڿ��̹Ƿ� ���ڿ� �Է� �Լ� ȣ��
		cout << "�й� : "; InputValue(st[i].Hakbun); cout << "\n"; // ���ڰ� �����̹Ƿ� ������ �Է� �Լ� ȣ��
		for (int j = 0; j < 3; j++) {
			info_hak(i, j); // ������ ���� ���� �Է¹ޱ�_ �����ε�� �ζ��� �Լ� InputValue()���
		}
	}
}

void PrintOneData(const Student& rSt, int i) // ���� �Ż�, ���� ���� ��� - �л� ������ ����ִ� ����ü ���� st�� ���� rSt
{
	cout.width(10);
	cout << "�̸� : " << rSt.StdName; // �̸����
	cout.width(10);
	cout << "�й� : " << rSt.Hakbun << "\n" << "\n"; // �й����
	cout.width(20);
	cout << i + 1 << "��° �л� ���� ����\n";
	cout << "====================================================================\n";
	cout.width(15);
	cout << "�����" << "            ��������" << "      ������ " << "      �������� " << "\n";
	cout << "====================================================================\n";
	for (int j = 0; j < 3; j++)
	{
		convert_number(i, j); // ���ĺ� ������ ���ڷ� ��ȯ
		cout.precision(2);
		cout << fixed;
		CalcGPA(st[i].Sub[j]);// j��° ������ ������ ���� ���ϱ�
		st[i].AveGPA = CalcAveGPA(st[i].Sub, j); // i��° �л��� ������ ������ �μ��� ����
		cout.width(15);
		cout << rSt.Sub[j].SubName;
		cout.width(15);
		cout << rSt.Sub[j].Hakjumm;
		cout.width(15);
		cout << rSt.Sub[j].Grade;
		cout.width(15);
		cout << rSt.Sub[j].GPA << "\n";
		cout.width(15);
	}

	cout << "====================================================================\n";
	cout.width(45);
	cout << "��� ���� :" << st[i].AveGPA << "\n" << "\n";
	sum = 0; // �����ݺ��� ���� 0���� �ʱ�ȭ
	haksum = 0;
}

void PrintAllData(const Student* pSt) // ��ü �л� ���� ��� - Student ����ü�� ����Ű�� ����ü ������ pSt
{
	for (int i = 0; i < 2; i++)
	{
		PrintOneData(pSt[i], i); // i��° �л� ������ ����Ű�� ����ü �����͸� �μ��� ���� 
	}
}
Student* StdSearch(Student* pSt, int i, char name[]) // Student ����ü�� ����Ű�� ����ü ������ pSt
{
	int result = strcmp(pSt[i].StdName, name); // i��° �л��� �̸��� �Է¹��� �̸��� ��
	if (result == 0)
		return &pSt[i]; // �ش� �л� ������ �ִ� �ּҸ� ���� 
	else
		return 0;
}

void PrintAllStdList(Student* pSt) // ��ü �л��� ���(�й�, �̸�)�� ����ϴ� �Լ�_ Student ����ü�� ����Ű�� ������ pSt���
{
	cout << "====================================\n";
	cout.width(15);
	cout << "�й�";
	cout.width(15);
	cout << "�̸�\n";
	cout << "====================================\n";
	for (int i = 0; i < 2; i++)
	{
		cout.width(15);
		cout << pSt[i].Hakbun;
		cout.width(15);
		cout << pSt[i].StdName << "\n";
	}
	cout << "====================================\n";
	cout << "\n";
}
void ModifyStdInfo(Student* pSt) // Ư�� �л��� �̸��� �й��� ������ �� �ִ� �Լ�
{
	cout << "�˻��� �л��� �̸�:";
	char name[20];
	cin >> name;
	int i;
	Student* SearchStd; // �л� ������ ã�� �Լ��� ���� ���� �޴� ����ü ������
	for (i = 0; i < 2; i++) // �л� �� ��ŭ �Է¹��� �̸��� �л� �̸����� ��
	{
		SearchStd = StdSearch(st, i, name);
		if (SearchStd != NULL) // �̸��� ã�Ҵٸ�
		{
			cout << "*< " << SearchStd[i].StdName << "  " << SearchStd[i].Hakbun << " >�� ������ �����ϼ���\n";
			cout << "�̸� :";
			InputValue(SearchStd[i].StdName); // ��������
			cout << "�й� :";
			InputValue(SearchStd[i].Hakbun); // ���� ����
			break; // �̸��� ã������ �ݺ��� Ż��
		}
		else
			continue; // �̸��� ã�� ���ߴٸ� ���� �ݺ��� ��� ����
	}
	if (i == 2) cout << "��ġ�ϴ� �̸��� �����ϴ�.\n"; // ��ܿ� �̸��� ���ٸ�, ���� �޼��� ���
}
int main(void)
{
	while (1)
	{
		Print_Menu();
		if (num == 1) {// num�� ���� 1�̶�� �л� ���� �Է� �ޱ�
			info_stu(); // �л� ���� �Է� �ޱ� - ������ ���� ���� �Է� �Լ� ����
		}
		else if (num == 2)
		{
			cout << "\n";
			cout.width(45);
			PrintAllData(st); // ��ü �л� ���� ����
		}
		else if (num == 3)
		{
			int i;
			Student* SearchStd; // �л��̸� Ž�� ����� ���� ����ü
			cout << "�˻��� �л� �̸�:";
			char name[20];
			cin >> name;
			for (i = 0; i < 2; i++) // �л� �� ��ŭ �Է¹��� �̸��� �л� �̸����� ��
			{
				SearchStd = StdSearch(st, i, name);
				if (SearchStd != NULL)
				{
					PrintOneData(*SearchStd, i);// �л� �̸� Ž�� ����� �޴� ����ü�� ����ִ� ���� ���� ���ڷ� �Ѱ���.
					break; // �̸��� ã������ �ݺ��� Ż��
				}
				else
					continue; // �̸��� ã�� ���ߴٸ� ���� �ݺ��� ��� ����
			}
			if (i == 2) // �̸��� ã�� ���ߴٸ�
				cout << "��ġ�ϴ� �л��� �����ϴ�.\n";
		}
		else if (num == 4) // 4���� ������, ��ü
		{
			PrintAllStdList(st); // ��ü �л� ��� ���
		}
		else if (num == 5) // 5���� ������,
		{
			ModifyStdInfo(st); // �л� ���� ����
		}
		else if (num != 1 && num != 2 && num != 3 && num != 4 && num != 5) // num�� �޴���ȣ ���� ���̸�, ���ѹݺ��� Ż��
		{
			cout << "���α׷��� �����մϴ�.";
			break;
		}
	}
}
