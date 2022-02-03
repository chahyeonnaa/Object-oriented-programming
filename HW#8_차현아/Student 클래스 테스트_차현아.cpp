/*****************************************************/
/*             HW#8 : Ŭ���� ���� �ǽ�               */
/*  �ۼ��� : ������        ��¥ : 2021�� 5�� 7��     */
/*                                                   */
/* ���� ���� :��ü�������� ����ó�� ���α׷�#1 �ۼ�*/
/*            2. Student Class �׽�Ʈ(������������)   */
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


// ������� Student Ŭ���� 
class Student {
protected:
	string m_name; // �л� �̸�
	int m_hakbun;  // �й�
	int m_subnum;  // ������ ���� ��
	Subject* m_sub; // ������ �����
	float m_aveGPA; // ������ ������� ��� ����

public:
	void Initialize(); // ������� �ʱ�ȭ
	void Initialize(string, int, int, Subject*); // ���ڰ����� ������� �ʱ�ȭ
	void Remove(); // �����޸� ����(m_sub)
	void InputValue(string&);
	void InputValue(int&);
	void InputData(); // ������� �� �Է�
	void PrintData(); // ������� �� ���
	void CalcAveGPA(float sum, float haksum); // ��� ���� ���

	string GetName(); // �������Լ� : Ŭ���� �ۿ��� ��������� ���� �� �ְ���.
	int GetHakbun();
	int GetSubNum();
	float GetAveGPA();

};
// Ŭ������ ������_��� �Լ� ����
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

int main(void)
{
	Subject sub[2]; // ��ü �迭
	sub[0].Initialize("��ǻ��", 3, "C0"); // �������� �ֱ� 
	sub[1].Initialize("���빫��", 2, "A0");

	Student st1, st2; // Student Ŭ������ �Ϲ� ��ü ����

	st1.Initialize(); // st1�� ��������� �ʱ�ȭ
	st2.Initialize("ȫ�浿", 2020039099, 2, sub); // ������ �ʱ�ȭ�� ���� �迭�� ���ڷ� �ѱ��.

	st1.InputData(); // ����ڷκ��� ���� ������ �Է¹���
	cout << "\n" << "st1 ����" << "\n";
	st1.PrintData(); // ���� ���

	cout << "\n" << "st2 ����" << "\n";
	st2.PrintData(); // �������

	st1.Remove(); //st1���� ���������� �Ҵ��� �޸� ��������

}