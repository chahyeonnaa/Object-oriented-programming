/*****************************************************/
/*             HW#4 : 개선된 함수 기능               */
/*  작성자 : 차현아        날짜 : 2021년 4월 2일     */
/*                                                   */
/* 문제 정의 : 성적처리프로그램#3                    */
/******************************************************/
#include<iostream>
#include<cstring>
using namespace std;

int num; // 메뉴번호를 받는 변수
float sum = 0; int haksum = 0;

struct Subject { /*과목 정보*/
	char SubName[30]; // 과목이름
	int Hakjumm;      // 과목학점
	char Grade[10];   // 과목등급
	float GPA;        // 과목평점
};
struct Student { /*학생 정보*/
	char StdName[30]; // 학생이름
	int Hakbun;       // 학번
	Subject Sub[3];   // 과목
	float AveGPA;     //교과목 평균 평점
};

struct Student st[2]; // 2명의 학생 정보를 입력받을 변수

inline void Print_Menu() // 메뉴를 출력하고, 메뉴번호를 입력받는 인라인 함수
{
	cout << "========= 메뉴 =========\n";
	cout << "1. 학생 성적 입력 \n" << "2. 전체 학생 성적 보기\n" << "3. 학생 이름 검색\n";
	cout << "4. 전체 학생 목록 보기\n" << "5. 학생 정보 수정\n" << "6. 프로그램 종료\n";
	cout << "원하는 기능을 입력하세요 :";
	cin >> num;
}

void convert_number(int i, int j) // 학점을 숫자평점으로 바꿔주는 함수
{
	if (st[i].Sub[j].Grade[0] == 'A') // [0]번에 제일 먼저 입력되는 알파벳을 기준으로 수치화
		st[i].Sub[j].GPA = 4.0;
	else if (st[i].Sub[j].Grade[0] == 'B')
		st[i].Sub[j].GPA = 3.0;
	else if (st[i].Sub[j].Grade[0] == 'C')
		st[i].Sub[j].GPA = 2.0;
	else if (st[i].Sub[j].Grade[0] == 'D')
		st[i].Sub[j].GPA = 1.0;
	else if (st[i].Sub[j].Grade[0] == 'F')
		st[i].Sub[j].GPA = 0;

	if (st[i].Sub[j].Grade[1] == '+') //[1]번에 +가 입력되면, 위에서 잡았던 기준값에서 
		st[i].Sub[j].GPA += 0.5;      // 계산

}
void CalcGPA(Subject& Sub) // 과목당 교과목 평점 구하기 - 학생 정보가 들어있는 구조체 변수 st의 레퍼런스 Sub
{
	Sub.GPA = Sub.GPA * Sub.Hakjumm;

}
float CalcAveGPA(Subject* Sub, int j)// 교과목 평균 평점구하기 - 과목정보를 담고있는 구조체 Subject를 가리키는 구조체 포인터 Sub 
{
	sum = sum + Sub[j].GPA; // 각 교과목의 평점을 더해 전역변수 sum에 넣기
	haksum = haksum + Sub[j].Hakjumm; // 각 교과목의 학점을 더해 전역변수 haksum에 넣기
	return sum / haksum; // 교과목 평균 평점구하기 = 각 교과목의 평점의 합 / 각 교과목 학점의 총 합

}
inline void InputValue(char* str) // 개별데이터를 사용자로부터 입력받기 위한 인라인 함수(문자열 입력을 위함)
{
	cin >> str;
}
inline void InputValue(int& i) // 개별데이터를 사용자로부터 입력받기 위한 인라인 함수(정수 입력을 위함)
{
	cin >> i;
}
void info_hak(int i, int j) // 수강한 과목 정보 입력 받기 
{
	cout << "* 수강한 교과목 3개와 각 교과목명, 과목학점, 과목등급을 입력하세요.\n";
	cout << "교과목 명:"; InputValue(st[i].Sub[j].SubName); // 인자가 문자열이므로 문자열 입력 함수 호출
	cout << "과목 학점수:"; InputValue(st[i].Sub[j].Hakjumm); // 인자가 정수이므로 정수형 입력 함수 호출
	cout << "과목등급<A+ ~F>:"; InputValue(st[i].Sub[j].Grade); // 인자가 정수이므로 정수형 입력 함수 호출
	switch (st[i].Sub[j].Grade[0]) // st[i].Sub[j].Grade[0]값을 잘 못 입력할 상황을 대비 
	{
	case 'A':
	case 'B':
	case 'C':
	case 'D':
	case 'E':
	case 'F': // 제대로 입력했을시 
		break; // 스위치문 탈출
	default: // 잘 못 입력했다면, 
		while (1)
		{
			cout << "과목등급<A+ ~F>:"; cin >> st[i].Sub[j].Grade; // 제대로 된 값이 입력될 때까지 계속 입력받기
			if (st[i].Sub[j].Grade[0] == 'A' || st[i].Sub[j].Grade[0] == 'B' || st[i].Sub[j].Grade[0] == 'C' || st[i].Sub[j].Grade[0] == 'D' || st[i].Sub[j].Grade[0] == 'E' || st[i].Sub[j].Grade[0] == 'F')
				break;
		}
		break;
	}
	cout << "\n";
}

void info_stu() // 학생 정보 입력 받기 - 수강한 과목 정보 입력 함수 포함
{
	for (int i = 0; i < 2; i++) {
		cout << "*" << i + 1 << "번째 학생 이름과 학번을 입력하세요.\n";
		cout << "이름 : ";
		InputValue(st[i].StdName); // 인자가 문자열이므로 문자열 입력 함수 호출
		cout << "학번 : "; InputValue(st[i].Hakbun); cout << "\n"; // 인자가 정수이므로 정수형 입력 함수 호출
		for (int j = 0; j < 3; j++) {
			info_hak(i, j); // 수강한 과목 정보 입력받기_ 오버로드된 인라인 함수 InputValue()사용
		}
	}
}

void PrintOneData(const Student& rSt, int i) // 개인 신상, 성적 정보 출력 - 학생 정보를 담고있는 구조체 변수 st의 별명 rSt
{
	cout.width(10);
	cout << "이름 : " << rSt.StdName; // 이름출력
	cout.width(10);
	cout << "학번 : " << rSt.Hakbun << "\n" << "\n"; // 학번출력
	cout.width(20);
	cout << i + 1 << "번째 학생 성적 보기\n";
	cout << "====================================================================\n";
	cout.width(15);
	cout << "과목명" << "            과목학점" << "      과목등급 " << "      과목평점 " << "\n";
	cout << "====================================================================\n";
	for (int j = 0; j < 3; j++)
	{
		convert_number(i, j); // 알파벳 학점을 숫자로 변환
		cout.precision(2);
		cout << fixed;
		CalcGPA(st[i].Sub[j]);// j번째 과목의 교과목 평점 구하기
		st[i].AveGPA = CalcAveGPA(st[i].Sub, j); // i번째 학생의 교과목 정보를 인수로 전달
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
	cout << "평균 평점 :" << st[i].AveGPA << "\n" << "\n";
	sum = 0; // 다음반복을 위해 0으로 초기화
	haksum = 0;
}

void PrintAllData(const Student* pSt) // 전체 학생 정보 출력 - Student 구조체를 가리키는 구조체 포인터 pSt
{
	for (int i = 0; i < 2; i++)
	{
		PrintOneData(pSt[i], i); // i번째 학생 정보를 가리키는 구조체 포인터를 인수로 전달 
	}
}
Student* StdSearch(Student* pSt, int i, char name[]) // Student 구조체를 가리키는 구조체 포인터 pSt
{
	int result = strcmp(pSt[i].StdName, name); // i번째 학생의 이름과 입력받은 이름을 비교
	if (result == 0)
		return &pSt[i]; // 해당 학생 정보가 있는 주소를 리턴 
	else
		return 0;
}

void PrintAllStdList(Student* pSt) // 전체 학생의 목록(학번, 이름)을 출력하는 함수_ Student 구조체를 가리키는 포인터 pSt사용
{
	cout << "====================================\n";
	cout.width(15);
	cout << "학번";
	cout.width(15);
	cout << "이름\n";
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
void ModifyStdInfo(Student* pSt) // 특정 학생의 이름과 학번을 수정할 수 있는 함수
{
	cout << "검색할 학생의 이름:";
	char name[20];
	cin >> name;
	int i;
	Student* SearchStd; // 학생 정보를 찾는 함수의 리턴 값을 받는 구조체 포인터
	for (i = 0; i < 2; i++) // 학생 수 만큼 입력받은 이름과 학생 이름들을 비교
	{
		SearchStd = StdSearch(st, i, name);
		if (SearchStd != NULL) // 이름을 찾았다면
		{
			cout << "*< " << SearchStd[i].StdName << "  " << SearchStd[i].Hakbun << " >의 정보를 수정하세요\n";
			cout << "이름 :";
			InputValue(SearchStd[i].StdName); // 정보수정
			cout << "학번 :";
			InputValue(SearchStd[i].Hakbun); // 정보 수정
			break; // 이름을 찾았으면 반복문 탈출
		}
		else
			continue; // 이름을 찾지 못했다면 다음 반복을 계속 수행
	}
	if (i == 2) cout << "일치하는 이름이 없습니다.\n"; // 명단에 이름이 없다면, 오류 메세지 출력
}
int main(void)
{
	while (1)
	{
		Print_Menu();
		if (num == 1) {// num의 값이 1이라면 학생 정보 입력 받기
			info_stu(); // 학생 정보 입력 받기 - 수강한 과목 정보 입력 함수 포함
		}
		else if (num == 2)
		{
			cout << "\n";
			cout.width(45);
			PrintAllData(st); // 전체 학생 성적 보기
		}
		else if (num == 3)
		{
			int i;
			Student* SearchStd; // 학생이름 탐색 결과를 받을 구조체
			cout << "검색할 학생 이름:";
			char name[20];
			cin >> name;
			for (i = 0; i < 2; i++) // 학생 수 만큼 입력받은 이름과 학생 이름들을 비교
			{
				SearchStd = StdSearch(st, i, name);
				if (SearchStd != NULL)
				{
					PrintOneData(*SearchStd, i);// 학생 이름 탐색 결과를 받는 구조체에 들어있는 실제 값을 인자로 넘겨줌.
					break; // 이름을 찾았으면 반복문 탈출
				}
				else
					continue; // 이름을 찾지 못했다면 다음 반복을 계속 수행
			}
			if (i == 2) // 이름을 찾지 못했다면
				cout << "일치하는 학생이 없습니다.\n";
		}
		else if (num == 4) // 4번을 누르면, 전체
		{
			PrintAllStdList(st); // 전체 학생 목록 출력
		}
		else if (num == 5) // 5번을 누르면,
		{
			ModifyStdInfo(st); // 학생 정보 수정
		}
		else if (num != 1 && num != 2 && num != 3 && num != 4 && num != 5) // num이 메뉴번호 외의 값이면, 무한반복문 탈출
		{
			cout << "프로그램을 종료합니다.";
			break;
		}
	}
}
