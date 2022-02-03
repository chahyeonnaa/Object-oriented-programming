/*****************************************************/
/*             HW#8 : 클래스 기초 실습               */
/*  작성자 : 차현아        날짜 : 2021년 5월 7일     */
/*                                                   */
/* 문제 정의 :객체지향방식의 성적처리 프로그램#1 작성*/
/*            2. Student Class 테스트(분할컴파일전)   */
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
	void Initialize(); // 멤버변수 초기화
	void Initialize(string, int, string);
	void InputValue(string&); // 입력을 위한 함수
	void InputValue(int&);
	void InputData(); // 멤버변수 값 입력_내부적으로 InputValue() 이용 
	void PrintTitle(); // 멤버변수에 대한 Title Text 출력
	void PrintData(); // 멤버변수 값 출력
	void CalcGPA(); // 평점계산

	string GetName(); // 접근자 함수(클래스 멤버 변수에 대한 접근 허용)
	int GetHakjum();
	string GetGrade();
	float GetGPA();

};
// 클래스의 구현부_멤버 함수 정의
void Subject::Initialize() // 멤버 변수 초기화
{
	m_name = "";
	m_hakjum = 0;
	m_grade = "";
	m_GPA = 0.0;
}

void Subject::Initialize(string name, int jum, string grade)
// 데이터를 사용자에게 입력받지 않을때, 변수를 매개변수로 받아서 초기화해주는 함수
{
	m_name = name; // 멤버변수 자리에 데이터 할당해주기
	m_hakjum = jum;
	m_grade = grade;
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


// 여기부터 Student 클래스 
class Student {
protected:
	string m_name; // 학생 이름
	int m_hakbun;  // 학번
	int m_subnum;  // 수강한 과목 수
	Subject* m_sub; // 수강한 과목들
	float m_aveGPA; // 수강한 과목들의 평균 평점

public:
	void Initialize(); // 멤버변수 초기화
	void Initialize(string, int, int, Subject*); // 인자값으로 멤버변수 초기화
	void Remove(); // 동적메모리 해제(m_sub)
	void InputValue(string&);
	void InputValue(int&);
	void InputData(); // 멤버변수 값 입력
	void PrintData(); // 멤버변수 값 출력
	void CalcAveGPA(float sum, float haksum); // 평균 평점 계산

	string GetName(); // 접근자함수 : 클래스 밖에서 멤버변수를 읽을 수 있게함.
	int GetHakbun();
	int GetSubNum();
	float GetAveGPA();

};
// 클래스의 구현부_멤버 함수 정의
void Student::Initialize() // 멤버 변수 초기화
{
	m_name = "";
	m_hakbun = 0;
	m_subnum = 0;
	m_sub = NULL;
	m_aveGPA = 0.0;

}

void Student::Initialize(string str, int hak, int sub, Subject* ject) 
// 받아온 매개변수들을 멤버변수 값으로 할당_ *배열을 포인터로 받는다.
{
	m_name = str;
	m_hakbun = hak;
	m_subnum = sub;
	m_sub = ject;
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


void Student::Remove() // 할당받은 메모리 공간 해제
{
	delete[]m_sub;
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
	cout << "====================================================================\n";
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
	Subject sub[2]; // 객체 배열
	sub[0].Initialize("컴퓨터", 3, "C0"); // 과목정보 넣기 
	sub[1].Initialize("현대무용", 2, "A0");

	Student st1, st2; // Student 클래스의 일반 객체 생성

	st1.Initialize(); // st1을 빈공간으로 초기화
	st2.Initialize("홍길동", 2020039099, 2, sub); // 위에서 초기화한 과목 배열을 인자로 넘긴다.

	st1.InputData(); // 사용자로부터 직접 정보를 입력받음
	cout << "\n" << "st1 정보" << "\n";
	st1.PrintData(); // 정보 출력

	cout << "\n" << "st2 정보" << "\n";
	st2.PrintData(); // 정보출력

	st1.Remove(); //st1에서 과목정보를 할당한 메모리 공간해제

}