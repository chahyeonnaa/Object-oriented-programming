/*****************************************************/
/*             HW#9 : 생성자와 소멸자 실습           */
/*  작성자 : 차현아        날짜 : 2021년 5월 14일     */
/*                                                   */
/* 문제 정의 : 객체지향방식의 성적처리프로그램 #2작성*/
/*                                                   */
/******************************************************/

#include<iostream>
#include<string> //string 클래스를 사용하기 위한 헤더파일
using namespace std;

class Subject {
protected: // 클래스 자신과 상속받은 자식 클래스에만 허용
	string m_name; // 과목명
	int m_hakjum;  // 학점
	string m_grade; // 등급
	float m_GPA;    // 평점

public:
	void InputValue(string&); // 입력을 위한 함수
	void InputValue(int&);
	void InputData(); // 멤버변수 값 입력_내부적으로 InputValue() 이용 
	void PrintTitle(); // 멤버변수에 대한 Title Text 출력
	void PrintData(); // 멤버변수 값 출력
	void CalcGPA(); // 평점계산
	void Modify(); // 과목 정보 수정

	Subject(); // 디폴트 생성자
	Subject(string name, int hakjum, string grade); // 인자있는 생성자
	Subject(const Subject& sub); // 복사생성자
	~Subject(); // 소멸자

	string GetName(); // 접근자 함수(클래스 멤버 변수에 대한 접근 허용)
	int GetHakjum();
	string GetGrade();
	float GetGPA();

	void SetName(string name);
	void SetHakjum(int num);
	void SetGrade(string gra);
	void SetGPA(float num);


};
// 클래스의 구현부_멤버 함수 정의
Subject::Subject() // 디폴트 생성자 구현부
{
	m_name = "";
	m_hakjum = 0;
	m_grade = "";
	m_GPA = 0.0;
	cout << "* Subject() 디폴트 생성자 호출 *\n";
}

Subject::Subject(string name, int hakjum, string grade) // 인자있는 생성자
{
	m_name = name;
	m_hakjum = hakjum;
	m_grade = grade;
	CalcGPA();
	cout << "* Subject 인자있는 생성자 호출 *\n";
}
Subject::Subject(const Subject& sub)
{
	this->m_name = sub.m_name;
	this->m_hakjum = sub.m_hakjum;
	this->m_grade = sub.m_grade;
	this->m_GPA = sub.m_GPA;

	cout << "* Subject 복사생성자 호출 *\n";
}
Subject::~Subject()
{
	cout << "Subject 소멸자 호출\n";
}

inline void Subject::InputValue(string& str) // 문자열 입력시
{
	getline(cin, str);
}

inline void Subject::InputValue(int& i) // 정수 입력시
{
	cin >> i;
	cin.ignore(); // 버퍼 비워주기
}


void Subject::CalcGPA() // 한 과목의 평점 계산하기 ex)3학점 * 4.5 = 13.5
{
	if (m_grade == "A+") // string  객체의 문자열 비교를 통해 GPA에 숫자 값 할당
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

	m_GPA = m_GPA * m_hakjum; // 학점과 변환된 등급을 곱하여 평점 계산

}

void Subject::InputData()// 사용자에게 멤버변수의 값을 직접 입력받음.
{
	cout << "교과목 명:";
	InputValue(m_name); // 인자가 문자열이므로 문자열 입력 함수 호출
	cout << "과목 학점수:";
	InputValue(m_hakjum); // 인자가 정수이므로 정수형 입력 함수 호출
	cout << "과목등급<A+ ~F>:";
	InputValue(m_grade); // 인자가 문자열이므로 문자열 입력 함수 호출
	cout << "\n";

}

void Subject::PrintTitle() // 멤버변수에 대한 title 텍스트를 화면에 출력
{
	cout << "====================================================================\n";
	cout.width(15);
	cout << "교과목명" << "            학점수" << "        등급 " << "         평점 " << "\n";
	cout << "====================================================================\n";

}

void Subject::PrintData() // 멤버 변수의 값을 화면에 출력
{
	cout.precision(2);
	cout << fixed;
	cout.width(15);
	cout << m_name; // 과목이름
	cout.width(15);
	cout << m_hakjum; // 과목학점
	cout.width(15);
	cout << m_grade; // 과목등급
	cout.width(15);
	CalcGPA();
	cout << m_GPA << "\n"; // 평균평점

}

void Subject::Modify()
{
	cout << "*< " << m_name << " >의 정보를 수정하세요\n";
	cout << "교과목명: ";
	InputValue(m_name);
	cout << "과목학점 :";
	InputValue(m_hakjum);
	cout << "과목등급 :";
	InputValue(m_grade);
	cout << "\n";
	CalcGPA();

}
string Subject::GetName() // 접근자함수 : m_name을 클래스 밖에서 읽을 수 있게함.
{
	return m_name;
}

int Subject::GetHakjum() // 접근자함수 : m_hakjum을 클래스 밖에서 읽을 수 있게함.
{
	return m_hakjum;
}

float Subject::GetGPA() // 접근자함수 : m_GPA을 클래스 밖에서 읽을 수 있게함.
{
	return m_GPA;
}

string Subject::GetGrade() // 접근자함수 : m_grade을 클래스 밖에서 읽을 수 있게함.
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


// 여기부터 Student 클래스 
class Student {
protected:
	string m_name; // 학생 이름
	int m_hakbun;  // 학번
	int m_subnum;  // 수강한 과목 수
	Subject* m_sub; // 수강한 과목들
	float m_aveGPA; // 수강한 과목들의 평균 평점

public:
	void InputValue(string&);
	void InputValue(int&);
	void InputData(); // 멤버변수 값 입력
	void PrintData(); // 멤버변수 값 출력
	void CalcAveGPA(float sum, float haksum); // 평균 평점 계산
	void Modify(); // 학생 정보 수정

	Student(); // 디폴트 생성자 
	Student(string name, int hakbun, int subnum, Subject* sub); // 인자있는 생성자
	Student(const Student& std);// 복사 생성자
	~Student();

	string GetName(); // 접근자함수 : 클래스 밖에서 멤버변수를 읽을 수 있게함.
	int GetHakbun();
	int GetSubNum();
	float GetAveGPA();

};

Student::Student() //디폴트 생성자 
{
	m_name = "";
	m_hakbun = 0;
	m_subnum = 0;
	m_sub = NULL;
	m_aveGPA = 0.0;
	cout << "* Student 디폴트 생성자 호출 *\n";

}

Student::Student(string name, int hakbun, int subnum, Subject* sub) // 인자있는 생성자_깊은 복사 해야함
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


	cout << "* Student 인자있는 생성자 호출 *\n";
}

Student::~Student() // 할당받은 메모리 공간 해제
{
	cout << "Student 소멸자 호출\n";
	delete[]m_sub;
	m_sub = NULL;
}

Student::Student(const Student& std) //복사생성자
{
	this->m_name = std.m_name;
	this->m_hakbun = std.m_hakbun;
	this->m_subnum = std.m_subnum;

	this->m_sub = new Subject[m_subnum];
	//과목복사가 일어나야함.

	for (int i = 0; i < m_subnum; i++)
	{
		(this->m_sub + i)->SetName((std.m_sub + i)->GetName());
		(this->m_sub + i)->SetHakjum((std.m_sub + i)->GetHakjum());
		(this->m_sub + i)->SetGrade((std.m_sub + i)->GetGrade());
		(this->m_sub + i)->SetGPA((std.m_sub + i)->GetGPA());
	}

}
void Student::InputValue(string& str) // 문자열 입력을 위한 함수
{
	getline(cin, str);
}

void Student::InputValue(int& i) // 정수 입력을 위한 함수
{
	cin >> i;
	cin.ignore(); // 버퍼 비우기
}

void Student::InputData() // 사용자로부터 데이터 입력 받기
{
	cout << "*" << "학생 이름과 학번을 입력하세요.\n";
	cout << "이름 : ";
	InputValue(m_name); // 인자가 문자열이므로 문자열 입력 함수 호출
	cout << "학번 : ";
	InputValue(m_hakbun);
	cout << "\n"; // 인자가 정수이므로 정수형 입력 함수 호출

	cout << "수강한 과목 수 입력 :";
	InputValue(m_subnum);

	m_sub = new Subject[m_subnum]; // 입력받은 과목 수 만큼 과목 정보 공간을 동적할당


	for (int j = 0; j < (m_subnum); j++)
	{
		cout << "* 수강한 교과목" << m_subnum << "개와 각 교과목명, 과목학점, 과목등급을 입력하세요.\n";
		(m_sub + j)->InputData(); // 한과목씩 과목 정보 입력
	}

}

void Student::CalcAveGPA(float sum, float haksum) // 전체 학점 평균을 계산하는 함수
{
	m_aveGPA = sum / haksum; // 평점들의 합/ 총 학점 수
}

void Student::PrintData() // 정보 출력
{
	float sum = 0; // 평균 평점을 더해서 받을 변수
	float haksum = 0; // 전체 학점 수를 더해서 받을 변수
	cout.width(10);
	cout << "이름 : " << m_name; // 이름출력
	cout.width(10);
	cout << "학번 : " << m_hakbun << "\n" << "\n"; // 학번출력
	cout.width(20);

	m_sub->PrintTitle(); //Subject 클래스의 PrintTitle() 호출

	for (int p = 0; p < m_subnum; p++) // 입력받은 과목수 만큼 반복문을 돌면서
	{
		(m_sub + p)->PrintData(); // 각 과목 정보 출력
		haksum = haksum + (m_sub + p)->GetHakjum(); // 각 과목의 학점수를 더하여 변수에 합을 할당_접근자 함수를 사용하여 접근가능
		sum = sum + (m_sub + p)->GetGPA(); // 각 과목의 평점을 더하여 변수에 할당_접근자 함수를 사용하여 접근가능
	}

	cout << "--------------------------------------------------------------------\n";
	cout.width(45);
	CalcAveGPA(sum, haksum); // 평균평점 계산
	cout << "평균 평점 :" << m_aveGPA << "\n" << "\n";

}

void Student::Modify()
{
	string Type; // 학생정보 또는 과목정보 문자열 저장용 string
	cout << "수정<학생정보/과목정보/모두>:"; // 수정할 내용 입력
	InputValue(Type);

	if (Type == "학생정보") // 학생정보 수정이면
	{
		cout << "*< " << m_name << "  " << m_hakbun << " >의 정보를 수정하세요\n";
		cout << "이름 : ";
		InputValue(m_name); // 인자가 문자열이므로 문자열 입력 함수 호출
		cout << "학번 : ";
		InputValue(m_hakbun);
		cout << "\n";
	}
	else if (Type == "과목정보") // 과목정보 수정_어떤 과목을 수정할 것인지 과목 찾기
	{
		string subject; // string 문자열 객체
		cout << "검색할 과목 이름 :"; // 교과목이 있는지 검색
		InputValue(subject);
		int i;
		for (i = 0; i < m_subnum; i++) // 수강하는 과목의 수만큼 반복
		{
			if (subject == (m_sub + i)->GetName()) // 입력받은 과목과 수강 과목들을 차례대로 비교
			{
				(m_sub + i)->Modify();
				break;
			}
			else
				continue; // 일치하는 과목을 찾지 못했다면, 계속 다음 반복을 수행
		}
		if (i == m_subnum)
		{
			cout << "일치하는 과목이 없습니다. \n"; // 일치하는 과목이 없을 경우, 메세지 출력
		}

	}
	else if (Type == "모두")
	{
		cout << "*< " << m_name << "  " << m_hakbun << " >의 정보를 수정하세요\n";
		cout << "이름 : ";
		InputValue(m_name); // 인자가 문자열이므로 문자열 입력 함수 호출
		cout << "학번 : ";
		InputValue(m_hakbun);
		cout << "\n";

		string subject; // string 문자열 객체
		cout << "검색할 과목 이름 :"; // 교과목이 있는지 검색
		InputValue(subject);
		int i;
		for (i = 0; i < m_subnum; i++) // 수강하는 과목의 수만큼 반복
		{
			if (subject == (m_sub + i)->GetName()) // 입력받은 과목과 수강 과목들을 차례대로 비교
			{
				(m_sub + i)->Modify();
				break;
			}
			else
				continue; // 일치하는 과목을 찾지 못했다면, 계속 다음 반복을 수행
		}
		if (i == m_subnum)
		{
			cout << "일치하는 과목이 없습니다. \n"; // 일치하는 과목이 없을 경우, 메세지 출력
		}


	}

}

string Student::GetName() // 접근자함수 : 클래스 밖에서 멤버변수를 읽을 수 있게함.
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
	Subject sub1("컴퓨터", 3, "C+"); // 인자있는 생성자
	Subject sub2(sub1); // 복사생성자
	cout << "\n" << "sub1의 정보" << "\n";
	sub1.PrintTitle();
	sub1.PrintData();

	cout << "\n" << "sub2의 정보" << "\n";
	sub2.PrintTitle();
	sub2.PrintData();
	cout << "\n";
	sub2.Modify(); //sub2의 내용 수정
	sub2.PrintTitle(); // 수정된 내용 출력
	sub2.PrintData();
	cout << "\n";

	Student st2("홍길동", 2013909845, 1, &sub1); // 인자있는 생성자_깊은복사를 하도록구현
	Student st1(st2); // 깊은 복사
	Student st3("차현아", 2020039009, 1, &sub2);


	cout << "\n" << "st1의 정보" << "\n";
	st1.PrintData();

	cout << "\n" << "st2의 정보" << "\n";
	st2.PrintData();

	cout << "\n" << "st3의 정보" << "\n";
	st3.PrintData();


	cout << "\n" << "st2의 정보수정" << "\n";
	st2.Modify(); // st2 학생의 정보 수정_
	cout << "\n" << "수정된 st2의 정보" << "\n";
	st2.PrintData();
	st1.PrintData();

	cout << "\n" << "st3의 정보" << "\n";
	st3.PrintData();

	return 0;
}
