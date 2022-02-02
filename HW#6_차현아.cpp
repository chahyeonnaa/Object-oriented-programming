/*****************************************************/
/*             HW#6 : ���ڿ� �ǽ�                    */
/*  �ۼ��� : ������        ��¥ : 2021�� 4�� 16��    */
/*                                                   */
/* ���� ���� : ����ó�����α׷�#4 ����               */
/******************************************************/
#include<iostream>
#include<string> //string Ŭ������ ����ϱ� ���� �������
using namespace std;

int num; // �޴���ȣ�� �޴� ����
float sum = 0; int haksum = 0;
int StudentNum; // �л��� �Է� ����
struct Student* ptr; // �л����� �Է¹��� ��, �Է¹��� �л��� ��ŭ �������� ����ü ������ �Ҵ��ϱ� ���� ����

struct Subject { /*���� ����*/
	string SubName; // �����̸�
	int Hakjumm;      // ��������
	string Grade;   // ������
	float GPA;        // ��������
};
struct Student { /*�л� ����*/
	string StdName; // �л��̸�
	int Hakbun;       // �й�
	Subject* Sub;     // ����_������� �Է¹ޱ� ���� ����ü �����ͷ� ����
	int SubNum;       // �����
	float AveGPA;     //������ ��� ����
};

inline void InputValue(string& str) // ���������͸� ����ڷκ��� �Է¹ޱ� ���� �ζ��� �Լ�(���ڿ� �Է��� ����)
{                                   // ���� ������ ���۷��� ������ ���� �����Ŵ
	getline(cin, str); //getline()�Լ��� ���� ���ڿ��� �Է¹���
}

inline void InputValue(int& i) // ���������͸� ����ڷκ��� �Է¹ޱ� ���� �ζ��� �Լ�(���� �Է��� ����)
{
	cin >> i;
	cin.ignore(); // ���� ����
}

inline void Print_Menu() // �޴��� ����ϰ�, �޴���ȣ�� �Է¹޴� �ζ��� �Լ�
{
	cout << "========= �޴� =========\n";
	cout << "1. �л� ���� �Է� \n" << "2. ��ü �л� ���� ����\n" << "3. �л� �̸� �˻�\n";
	cout << "4. ��ü �л� ��� ����\n" << "5. �л� ���� ����\n" << "6. ���α׷� ����\n";
	cout << "���ϴ� ����� �Է��ϼ��� :";
	InputValue(num); // �޴� ��ȣ �Է�
}

void convert_number(Subject* psub) // ������ ������������ �ٲ��ִ� �Լ�_psub�� ���� ������ ����Ű�� ����ü ������
{
	if (psub->Grade == "A+") // string  ��ü�� ���ڿ� �񱳸� ���� GPA�� ���� �� �Ҵ�
		psub->GPA = 4.5;
	else if (psub->Grade == "A0")
		psub->GPA = 4.0;
	else if (psub->Grade == "B+")
		psub->GPA = 3.5;
	else if (psub->Grade == "B0")
		psub->GPA = 3.0;
	else if (psub->Grade == "C+")
		psub->GPA = 2.5;
	else if (psub->Grade == "C0")
		psub->GPA = 2.0;
	else if (psub->Grade == "D+")
		psub->GPA = 1.5;
	else if (psub->Grade == "D0")
		psub->GPA = 1.0;
	else if (psub->Grade == "F")
		psub->GPA = 0;

}
void info_hak(Subject* psub) // ����� �� ����� �Է��ߴ��� Ȯ���ϱ� ���� �Լ�_ ������ ���� �ƴϸ� ��� �Է¹ް���.
{
	if (psub->Grade == "A+" || psub->Grade == "A0" || psub->Grade == "B+" || psub->Grade == "C+" || psub->Grade == "C0" || psub->Grade == "D+" || psub->Grade == "D0" || psub->Grade == "F")
		return; // ���������� ����
	else
	{
		while (1)
		{
			cout << "������<A+ ~F>:";
			InputValue(psub->Grade); // ���� ���� �Է��Ҷ����� �Է¹���
			if (psub->Grade == "A+" || psub->Grade == "A0" || psub->Grade == "B+" || psub->Grade == "C+" || psub->Grade == "C0" || psub->Grade == "D+" || psub->Grade == "D0" || psub->Grade == "F")
				break;
		}
	}

}

void CalcGPA(Subject* psub) // ����� ������ ���� ���ϱ�_���ڷ� �ٲ��� ������ ����� ������ ����
{
	psub->GPA = psub->GPA * psub->Hakjumm;

}
float CalcAveGPA(Subject* psub)// ������ ��� �������ϱ� - ���������� ����ִ� �������� �Ҵ�� ����ü Subject�� ����Ű�� ����ü ������ psub 
{
	sum = sum + psub->GPA; // �� �������� ������ ���� �������� sum�� �ֱ�
	haksum = haksum + psub->Hakjumm; // �� �������� ������ ���� �������� haksum�� �ֱ�
	return sum / haksum; // ������ ��� �������ϱ� = �� �������� ������ �� / �� ������ ������ �� ��
}

void InputData(Student* pSt, int StudentNum) // ��� ������ �Է¹޴� �Լ�
{
	for (int i = 0; i < StudentNum; i++)
	{
		cout << "*" << i + 1 << "��° �л� �̸��� �й��� �Է��ϼ���.\n";
		cout << "�̸� : ";
		InputValue((pSt + i)->StdName); // ���ڰ� ���ڿ��̹Ƿ� ���ڿ� �Է� �Լ� ȣ��
		cout << "�й� : ";
		InputValue(pSt[i].Hakbun);
		cout << "\n"; // ���ڰ� �����̹Ƿ� ������ �Է� �Լ� ȣ��

		cout << "������ ���� �� �Է� :";
		InputValue(pSt[i].SubNum);

		pSt[i].Sub = new Subject[(pSt[i].SubNum)]; // �Է¹��� ���� �� ��ŭ ���� ���� ������ �����Ҵ�

		for (int j = 0; j < (pSt[i].SubNum); j++)
		{
			cout << "* ������ ������" << pSt[i].SubNum << "���� �� �������, ��������, �������� �Է��ϼ���.\n";

			cout << "������ ��:";
			InputValue(pSt[i].Sub[j].SubName); // ���ڰ� ���ڿ��̹Ƿ� ���ڿ� �Է� �Լ� ȣ��
			cout << "���� ������:";
			InputValue(pSt[i].Sub[j].Hakjumm); // ���ڰ� �����̹Ƿ� ������ �Է� �Լ� ȣ��
			cout << "������<A+ ~F>:";
			InputValue(pSt[i].Sub[j].Grade); // ���ڰ� �����̹Ƿ� ������ �Է� �Լ� ȣ��

			info_hak((pSt + i)->Sub + j); // ����� ����� �Է��ߴ��� Ȯ���ϴ� ����_�� �л����� �Ҵ�� ���� ����ü�� ���ڷ� ����
			convert_number((pSt + i)->Sub + j); // ������ ������������ �ٲ��ִ� �Լ�_ ������ ������ ���ڷ� �����Ͽ� ���
			CalcGPA((pSt + i)->Sub + j); // ������ ���� ���
			pSt[i].AveGPA = CalcAveGPA((pSt + i)->Sub + j); // ��� ���� ���
		}
		sum = 0;
		haksum = 0; // ���� �ݺ��� ���� �ʱ�ȭ
	}
}

void PrintOneData(Student* ptr) // �� ������ ������ ������ִ� �Լ� - ptr�� �����Ͷ�� ���� ����ؾ���
{
	cout.width(10);
	cout << "�̸� : " << ptr->StdName; // �̸����
	cout.width(10);
	cout << "�й� : " << ptr->Hakbun << "\n" << "\n"; // �й����
	cout.width(20);
	cout << "====================================================================\n";
	cout.width(15);
	cout << "�����" << "            ��������" << "      ������ " << "      �������� " << "\n";
	cout << "====================================================================\n";
	for (int j = 0; j < ptr->SubNum; j++)
	{
		cout.precision(2);
		cout << fixed;
		cout.width(15);
		cout << ptr->Sub[j].SubName;
		cout.width(15);
		cout << ptr->Sub[j].Hakjumm;
		cout.width(15);
		cout << ptr->Sub[j].Grade;
		cout.width(15);
		cout << ptr->Sub[j].GPA << "\n";
		cout.width(15);
	}

	cout << "====================================================================\n";
	cout.width(45);
	cout << "��� ���� :" << ptr->AveGPA << "\n" << "\n";
}

void PrintAllData(Student* ptr) // ��ü �л� ���� ��� - Student ����ü�� ����Ű�� ����ü ������ ptr
{
	PrintOneData(ptr); // ������ �л� ������ ����Ű�� ����ü �����͸� �μ��� ���� 
}

Student* StdSearch(Student* pSt, string name) // Student ����ü�� ����Ű�� ����ü ������ pSt
{
	if (pSt->StdName == name) // (�Ű������� �Ѿ��)��° �л��� �̸��� �Է¹��� �̸��� ��
		return pSt; // �ش� �л� ������ �ִ� �ּҸ� ���� - �ּҸ� �����Ѵٴ� ���� �ݵ�� ����ؾ���
	else
		return 0;
}

Subject* SubSearch(const Student* pSt) // Ư�� ������ �˻��ϴ� �Լ�
{
	string subject; // string ���ڿ� ��ü
	cout << "�˻��� ���� �̸� :"; // �������� �ִ��� �˻�
	InputValue(subject);
	int i;
	for (i = 0; i < pSt->SubNum; i++) // �����ϴ� ������ ����ŭ �ݺ�
	{
		if (subject == pSt->Sub[i].SubName) // �Է¹��� ����� ���� ������� ���ʴ�� ��
			return &(pSt->Sub[i]); // �ش� ������ �ִ°��� �ּҸ� ������
		else
			continue; // ��ġ�ϴ� ������ ã�� ���ߴٸ�, ��� ���� �ݺ��� ����
	}
	if (i == pSt->SubNum)
	{
		cout << "��ġ�ϴ� ������ �����ϴ�. \n"; // ��ġ�ϴ� ������ ���� ���, �޼��� ���
		return NULL; // �ΰ��� ��ȯ
	}

}

void PrintAllStdList(Student* pSt) // ��ü �л��� ���(�й�, �̸�)�� ����ϴ� �Լ�_ Student ����ü�� ����Ű�� ������ pSt���
{
	cout << "====================================\n";
	cout.width(15);
	cout << "�й�";
	cout.width(15);
	cout << "�̸�\n";
	cout << "====================================\n";
	for (int i = 0; i < StudentNum; i++)
	{
		cout.width(15);
		cout << pSt[i].Hakbun;
		cout.width(15);
		cout << pSt[i].StdName << "\n";
	}
	cout << "====================================\n";
	cout << "\n";
}

void ModifyStdInfo(Student* ptr, int StudentNum) // Ư�� �л��� �̸��� �й��� ������ �� �ִ� �Լ�
{
	cout << "�˻��� �л��� �̸�:";
	string name;
	InputValue(name);
	int i;
	Student* SearchStd; // �л� ������ ã�� �Լ��� ���� ��(�ּ�)�� �޴� ����ü ������
	for (i = 0; i < StudentNum; i++) // �л� �� ��ŭ �Է¹��� �̸��� �л� �̸����� ��
	{
		SearchStd = StdSearch(ptr + i, name); // �л�ã��
		if (SearchStd != NULL) // �̸��� ã�Ҵٸ�
		{
			string Type; // �л����� �Ǵ� �������� ���ڿ� ����� string
			cout << "����<�л�����/��������>:"; // �л��������� or ������������ ����
			InputValue(Type);
			if (Type == "�л�����") // �л����� �����̸�
			{
				cout << "*< " << SearchStd->StdName << "  " << SearchStd->Hakbun << " >�� ������ �����ϼ���\n"; // �ּҸ� �޾ұ⶧���� SearchStd�� �ش� �л��� �ּҸ� �̹� ����Ű�� ����.
				cout << "�̸� :";                                                                               // SearchStd[i].Hakbun ���� �������� �ʵ��� ����_ �л��� �̹� ����Ű�� ����!
				InputValue(SearchStd->StdName); // ��������
				cout << "�й� :";
				InputValue(SearchStd->Hakbun); // ���� ����
				break; // �̸��� ã������ �ݺ��� Ż��
			}
			else if (Type == "��������") // �������� ����
			{
				Subject* subb = SubSearch(SearchStd); // �����̸� Ž�� ����� ���� ����ü
				if (subb != NULL)
				{
					cout << "*< " << subb->SubName << ", ���� : " << subb->Hakjumm << ", ��� : " << subb->Grade << " >�� ������ �����ϼ���\n";
					cout << "�������: ";
					InputValue(subb->SubName);
					cout << "�������� :";
					InputValue(subb->Hakjumm);
					cout << "������ :";
					InputValue(subb->Grade);

					info_hak(subb); // ����� ����� �Է��ߴ��� Ȯ���ϴ� ����_�� �л����� �Ҵ�� ���� ����ü�� ���ڷ� ����
					convert_number(subb); // ������ ������������ �ٲ��ִ� �Լ�_ ������ ������ ���ڷ� �����Ͽ� ���
					CalcGPA(subb); // ������ ���� ���

					sum = 0;
					haksum = 0;
					for (int r = 0; r < SearchStd->SubNum; r++) // ������ ���� �� ��ŭ �ݺ�
					{
						SearchStd->AveGPA = CalcAveGPA(SearchStd->Sub + r); // ��� ���� ���
					}

				}
			}
			return; // ���� ����
		}
		else
			continue; // �̸��� ã�� ���ߴٸ� ���� �ݺ��� ��� ����
	}
	if (i == StudentNum) cout << "��ġ�ϴ� �̸��� �����ϴ�.\n"; // ��ܿ� �̸��� ���ٸ�, ���� �޼��� ���

	sum = 0;
	haksum = 0;
}

int main(void)
{
	while (1)
	{
		Print_Menu();
		if (num == 1)
		{// num�� ���� 1�̶�� �л� ���� �Է� �ޱ�
			cout << "�л� �� �Է� :";
			InputValue(StudentNum);
			ptr = new Student[StudentNum]; // �Է¹��� �л��� ��ŭ �ʿ��� ������ �������� �Ҵ�

			InputData(ptr, StudentNum); // ��� ������ �Է�
		}
		else if (num == 2) // 2�� ������
		{
			cout << "\n";
			cout.width(45);
			for (int z = 0; z < StudentNum; z++)
			{
				PrintAllData(ptr + z); // ��ü �л� ���� ����
			}

		}
		else if (num == 3) // 3�� ������ �л�ã��
		{
			int i;
			Student* SearchStd; // �л��̸� Ž�� ����� ���� ����ü
			cout << "�˻��� �л� �̸�:";
			string name;
			InputValue(name);
			for (i = 0; i < StudentNum; i++) // �л� �� ��ŭ �Է¹��� �̸��� �л� �̸����� ��
			{
				SearchStd = StdSearch(ptr + i, name);
				if (SearchStd != NULL)
				{
					PrintOneData(SearchStd);// �л� �̸� Ž�� ����� �޴� ����ü�� ����ִ� ���� ���� ���ڷ� �Ѱ���.
					break; // �̸��� ã������ �ݺ��� Ż��
				}
				else
					continue; // �̸��� ã�� ���ߴٸ� ���� �ݺ��� ��� ����
			}
			if (i == StudentNum) // �̸��� ã�� ���ߴٸ�
				cout << "��ġ�ϴ� �л��� �����ϴ�.\n";
		}
		else if (num == 4) // 4���� ������,
		{
			PrintAllStdList(ptr); // ��ü �л� ��� ���
		}
		else if (num == 5) // 5���� ������,
		{
			ModifyStdInfo(ptr, StudentNum); // �л� ���� ����
		}
		else if (num != 1 && num != 2 && num != 3 && num != 4 && num != 5) // num�� �޴���ȣ ���� ���̸�, ���ѹݺ��� Ż��
		{
			cout << "���α׷��� �����մϴ�.";
			break;
		}
	}
}

