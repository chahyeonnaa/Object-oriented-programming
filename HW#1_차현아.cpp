/**************************************************/
/*             HW#1 : C++ 시작하기                */
/*  작성자 : 차현아        날짜 : 2021년 3월 14일 */
/*                                                */
/* 문제 정의 : 성적처리프로그램                   */
/* 학생 정보, 성적과 관련된 정보를 입력 받고 각 과목평점과 학생의 평균 평점을 구하여 결과 값을 출력하는 프로그램입니다. */
/*************************************************/
#include<iostream>
#include<cstring>
using namespace std;

int num; // 메뉴번호를 받는 변수
double er = 0; // 각 과목평점을 점점 더한 값을 넣을 변수 (반복문에 이용)
int haksum=0; // 과목의 학점을 더해 넣을 변수- 총 평점 계산에 쓰임.

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

void pri_Menu() // 메뉴를 출력하고, 메뉴번호를 입력받는 함수
{
	cout << "===== 메뉴 =====\n";
	cout << "1. 학생 성적 입력\n" << "2. 전체 학생 성적 보기\n" << "3. 프로그램 종료\n";
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

void info_hak(int i, int j) // 수강한 과목 정보 입력 받기 
{
	cout << "* 수강한 교과목 3개와 각 교과목명, 과목학점, 과목등급을 입력하세요.\n";
	cout << "교과목 명:"; cin >> st[i].Sub[j].SubName;
	cout << "과목 학점수:"; cin >> st[i].Sub[j].Hakjumm;
	cout << "과목등급<A+ ~F>:"; cin >> st[i].Sub[j].Grade;
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
		cin >> st[i].StdName;
		cout << "학번 : "; cin >> st[i].Hakbun; cout << "\n";
		for (int j = 0; j < 3; j++) {
			info_hak(i, j); // 수강한 과목 정보 입력받기
		}
	}
}

void info_resul(int i, int j) // 과목 정보 출력
{
	double sum; // 한 과목의 평균평점 값을 넣을 변수
	cout.width(15);
	cout << st[i].Sub[j].SubName;
	cout.width(15);
	cout << st[i].Sub[j].Hakjumm;
	cout.width(15);
	cout << st[i].Sub[j].Grade;
	cout.width(15);
	sum = st[i].Sub[j].GPA * st[i].Sub[j].Hakjumm; // 한 과목의 평균평점 = 학점 * 평점
	cout.width(15);
	cout << sum;
	haksum += st[i].Sub[j].Hakjumm;
	er = er + sum; // 각 과목의 평점을 더해 변수 er에 넣는 과정
}

int main(void)
{
	while (1)
	{
		pri_Menu();
		if (num == 1) {// num의 값이 1이라면 학생 정보 입력 받기
			info_stu(); // 학생 정보 입력 받기 - 수강한 과목 정보 입력 함수 포함
			pri_Menu();
		}
		if (num == 2)
		{
			cout << "\n";
			cout.width(45);
			cout << "전체 학생 성적 보기\n";
			cout << "====================================================================\n";
			for (int i = 0; i < 2; i++)
			{
				cout.width(10);
				cout << "이름 : " << st[i].StdName; // 이름출력
				cout.width(10);
				cout << "학번 : " << st[i].Hakbun << "\n"; // 학번출력
				cout << "====================================================================\n";
				cout.width(15);
				cout << "과목명" << "            과목학점" << "      과목등급 " << "      과목평점 " << "\n";
				cout << "====================================================================\n";

				for (int j = 0; j < 3; j++) // 3과목이기 때문에 3번 반복
				{
					convert_number(i, j); // 알파벳 학점을 숫자로 변환
					cout.precision(2);
					cout << fixed;
					info_resul(i, j); // 과목 세부사항 출력
					cout.width(10);
					cout << "\n";
				}
				st[i].AveGPA = er / haksum; // 평균학점 = 각 과목 평점들의 합/ 총 학점
				cout << "====================================================================\n";
				cout.width(45);
				cout << "평균 평점 :" << st[i].AveGPA << "\n";
				cout << "\n";
				er = 0; // 다음 반복을 위해서 초기화
				haksum = 0; // 다음 반복을 위해서 초기화
			}
		}
		pri_Menu();
		if (num != 1 && num != 2) // num이 1과 2 이외의 값이면, 무한반복문 탈출
		{
			cout << "프로그램을 종료합니다.";
			break;
		}
	}
}