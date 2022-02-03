/*****************************************************/
/*             HW#9 : �����ڿ� �Ҹ��� �ǽ�           */
/*  �ۼ��� : ������        ��¥ : 2021�� 5�� 14��     */
/*                                                   */
/* ���� ���� : ��ü�������� ����ó�����α׷� #2�ۼ�*/
/*                                                   */
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
	void InputValue(string&); // �Է��� ���� �Լ�
	void InputValue(int&);
	void InputData(); // ������� �� �Է�_���������� InputValue() �̿� 
	void PrintTitle(); // ��������� ���� Title Text ���
	void PrintData(); // ������� �� ���
	void CalcGPA(); // �������
	void Modify(); // ���� ���� ����

	Subject(); // ����Ʈ ������
	Subject(string name, int hakjum, string grade); // �����ִ� ������
	Subject(const Subject& sub); // ���������
	~Subject(); // �Ҹ���

	string GetName(); // ������ �Լ�(Ŭ���� ��� ������ ���� ���� ���)
	int GetHakjum();
	string GetGrade();
	float GetGPA();

	void SetName(string name);
	void SetHakjum(int num);
	void SetGrade(string gra);
	void SetGPA(float num);


};
// Ŭ������ ������_��� �Լ� ����
Subject::Subject() // ����Ʈ ������ ������
{
	m_name = "";
	m_hakjum = 0;
	m_grade = "";
	m_GPA = 0.0;
	cout << "* Subject() ����Ʈ ������ ȣ�� *\n";
}

Subject::Subject(string name, int hakjum, string grade) // �����ִ� ������
{
	m_name = name;
	m_hakjum = hakjum;
	m_grade = grade;
	CalcGPA();
	cout << "* Subject �����ִ� ������ ȣ�� *\n";
}
Subject::Subject(const Subject& sub)
{
	this->m_name = sub.m_name;
	this->m_hakjum = sub.m_hakjum;
	this->m_grade = sub.m_grade;
	this->m_GPA = sub.m_GPA;

	cout << "* Subject ��������� ȣ�� *\n";
}
Subject::~Subject()
{
	cout << "Subject �Ҹ��� ȣ��\n";
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

void Subject::Modify()
{
	cout << "*< " << m_name << " >�� ������ �����ϼ���\n";
	cout << "�������: ";
	InputValue(m_name);
	cout << "�������� :";
	InputValue(m_hakjum);
	cout << "������ :";
	InputValue(m_grade);
	cout << "\n";
	CalcGPA();

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

void Subject::SetName(string name)
{
	m_name = name;
}
void Subject::SetHakjum(int num)
{
	m_hakjum = num;
}
void Subject::SetGrade(string gra)
{
	m_grade = gra;
}
void Subject::SetGPA(float num)
{
	m_GPA = num;
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
	void InputValue(string&);
	void InputValue(int&);
	void InputData(); // ������� �� �Է�
	void PrintData(); // ������� �� ���
	void CalcAveGPA(float sum, float haksum); // ��� ���� ���
	void Modify(); // �л� ���� ����

	Student(); // ����Ʈ ������ 
	Student(string name, int hakbun, int subnum, Subject* sub); // �����ִ� ������
	Student(const Student& std);// ���� ������
	~Student();

	string GetName(); // �������Լ� : Ŭ���� �ۿ��� ��������� ���� �� �ְ���.
	int GetHakbun();
	int GetSubNum();
	float GetAveGPA();

};

Student::Student() //����Ʈ ������ 
{
	m_name = "";
	m_hakbun = 0;
	m_subnum = 0;
	m_sub = NULL;
	m_aveGPA = 0.0;
	cout << "* Student ����Ʈ ������ ȣ�� *\n";

}

Student::Student(string name, int hakbun, int subnum, Subject* sub) // �����ִ� ������_���� ���� �ؾ���
{
	m_name = name;
	m_hakbun = hakbun;
	m_subnum = subnum;

	m_sub = new Subject[m_subnum];

	for (int i = 0; i < m_subnum; i++)
	{
		(m_sub + i)->SetName((sub + i)->GetName());
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

Student::Student(const Student& std) //���������
{
	this->m_name = std.m_name;
	this->m_hakbun = std.m_hakbun;
	this->m_subnum = std.m_subnum;

	this->m_sub = new Subject[m_subnum];
	//���񺹻簡 �Ͼ����.

	for (int i = 0; i < m_subnum; i++)
	{
		(this->m_sub + i)->SetName((std.m_sub + i)->GetName());
		(this->m_sub + i)->SetHakjum((std.m_sub + i)->GetHakjum());
		(this->m_sub + i)->SetGrade((std.m_sub + i)->GetGrade());
		(this->m_sub + i)->SetGPA((std.m_sub + i)->GetGPA());
	}

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

void Student::Modify()
{
	string Type; // �л����� �Ǵ� �������� ���ڿ� ����� string
	cout << "����<�л�����/��������/���>:"; // ������ ���� �Է�
	InputValue(Type);

	if (Type == "�л�����") // �л����� �����̸�
	{
		cout << "*< " << m_name << "  " << m_hakbun << " >�� ������ �����ϼ���\n";
		cout << "�̸� : ";
		InputValue(m_name); // ���ڰ� ���ڿ��̹Ƿ� ���ڿ� �Է� �Լ� ȣ��
		cout << "�й� : ";
		InputValue(m_hakbun);
		cout << "\n";
	}
	else if (Type == "��������") // �������� ����_� ������ ������ ������ ���� ã��
	{
		string subject; // string ���ڿ� ��ü
		cout << "�˻��� ���� �̸� :"; // �������� �ִ��� �˻�
		InputValue(subject);
		int i;
		for (i = 0; i < m_subnum; i++) // �����ϴ� ������ ����ŭ �ݺ�
		{
			if (subject == (m_sub + i)->GetName()) // �Է¹��� ����� ���� ������� ���ʴ�� ��
			{
				(m_sub + i)->Modify();
				break;
			}
			else
				continue; // ��ġ�ϴ� ������ ã�� ���ߴٸ�, ��� ���� �ݺ��� ����
		}
		if (i == m_subnum)
		{
			cout << "��ġ�ϴ� ������ �����ϴ�. \n"; // ��ġ�ϴ� ������ ���� ���, �޼��� ���
		}

	}
	else if (Type == "���")
	{
		cout << "*< " << m_name << "  " << m_hakbun << " >�� ������ �����ϼ���\n";
		cout << "�̸� : ";
		InputValue(m_name); // ���ڰ� ���ڿ��̹Ƿ� ���ڿ� �Է� �Լ� ȣ��
		cout << "�й� : ";
		InputValue(m_hakbun);
		cout << "\n";

		string subject; // string ���ڿ� ��ü
		cout << "�˻��� ���� �̸� :"; // �������� �ִ��� �˻�
		InputValue(subject);
		int i;
		for (i = 0; i < m_subnum; i++) // �����ϴ� ������ ����ŭ �ݺ�
		{
			if (subject == (m_sub + i)->GetName()) // �Է¹��� ����� ���� ������� ���ʴ�� ��
			{
				(m_sub + i)->Modify();
				break;
			}
			else
				continue; // ��ġ�ϴ� ������ ã�� ���ߴٸ�, ��� ���� �ݺ��� ����
		}
		if (i == m_subnum)
		{
			cout << "��ġ�ϴ� ������ �����ϴ�. \n"; // ��ġ�ϴ� ������ ���� ���, �޼��� ���
		}


	}

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
	Subject sub1("��ǻ��", 3, "C+"); // �����ִ� ������
	Subject sub2(sub1); // ���������
	cout << "\n" << "sub1�� ����" << "\n";
	sub1.PrintTitle();
	sub1.PrintData();

	cout << "\n" << "sub2�� ����" << "\n";
	sub2.PrintTitle();
	sub2.PrintData();
	cout << "\n";
	sub2.Modify(); //sub2�� ���� ����
	sub2.PrintTitle(); // ������ ���� ���
	sub2.PrintData();
	cout << "\n";

	Student st2("ȫ�浿", 2013909845, 1, &sub1); // �����ִ� ������_�������縦 �ϵ��ϱ���
	Student st1(st2); // ���� ����
	Student st3("������", 2020039009, 1, &sub2);


	cout << "\n" << "st1�� ����" << "\n";
	st1.PrintData();

	cout << "\n" << "st2�� ����" << "\n";
	st2.PrintData();

	cout << "\n" << "st3�� ����" << "\n";
	st3.PrintData();


	cout << "\n" << "st2�� ��������" << "\n";
	st2.Modify(); // st2 �л��� ���� ����_
	cout << "\n" << "������ st2�� ����" << "\n";
	st2.PrintData();
	st1.PrintData();

	cout << "\n" << "st3�� ����" << "\n";
	st3.PrintData();

	return 0;
}
