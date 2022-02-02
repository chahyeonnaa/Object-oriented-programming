/*****************************************************/
/*             HW#6 : 문자열 실습                    */
/*  작성자 : 차현아        날짜 : 2021년 4월 16일    */
/*                                                   */
/* 문제 정의 : 성적처리프로그램#4 개선               */
/******************************************************/
#include<iostream>
#include<string> //string 클래스를 사용하기 위한 헤더파일
using namespace std;

int num; // 메뉴번호를 받는 변수
float sum = 0; int haksum = 0;
int StudentNum; // 학생수 입력 변수
struct Student* ptr; // 학생수를 입력받은 후, 입력받은 학생수 만큼 동적으로 구조체 공간을 할당하기 위한 변수

struct Subject { /*과목 정보*/
	string SubName; // 과목이름
	int Hakjumm;      // 과목학점
	string Grade;   // 과목등급
	float GPA;        // 과목평점
};
struct Student { /*학생 정보*/
	string StdName; // 학생이름
	int Hakbun;       // 학번
	Subject* Sub;     // 과목_과목수를 입력받기 위해 구조체 포인터로 선언
	int SubNum;       // 과목수
	float AveGPA;     //교과목 평균 평점
};

inline void InputValue(string& str) // 개별데이터를 사용자로부터 입력받기 위한 인라인 함수(문자열 입력을 위함)
{                                   // 전달 인자의 레퍼런스 선언을 통해 연결시킴
	getline(cin, str); //getline()함수를 통해 문자열을 입력받음
}

inline void InputValue(int& i) // 개별데이터를 사용자로부터 입력받기 위한 인라인 함수(정수 입력을 위함)
{
	cin >> i;
	cin.ignore(); // 버퍼 비우기
}

inline void Print_Menu() // 메뉴를 출력하고, 메뉴번호를 입력받는 인라인 함수
{
	cout << "========= 메뉴 =========\n";
	cout << "1. 학생 성적 입력 \n" << "2. 전체 학생 성적 보기\n" << "3. 학생 이름 검색\n";
	cout << "4. 전체 학생 목록 보기\n" << "5. 학생 정보 수정\n" << "6. 프로그램 종료\n";
	cout << "원하는 기능을 입력하세요 :";
	InputValue(num); // 메뉴 번호 입력
}

void convert_number(Subject* psub) // 학점을 숫자평점으로 바꿔주는 함수_psub은 과목 공간을 가리키는 구조체 포인터
{
	if (psub->Grade == "A+") // string  객체의 문자열 비교를 통해 GPA에 숫자 값 할당
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
void info_hak(Subject* psub) // 제대로 된 등급을 입력했는지 확인하기 위한 함수_ 정해진 값이 아니면 계속 입력받게함.
{
	if (psub->Grade == "A+" || psub->Grade == "A0" || psub->Grade == "B+" || psub->Grade == "C+" || psub->Grade == "C0" || psub->Grade == "D+" || psub->Grade == "D0" || psub->Grade == "F")
		return; // 정상적으로 리턴
	else
	{
		while (1)
		{
			cout << "과목등급<A+ ~F>:";
			InputValue(psub->Grade); // 정상 값을 입력할때까지 입력받음
			if (psub->Grade == "A+" || psub->Grade == "A0" || psub->Grade == "B+" || psub->Grade == "C+" || psub->Grade == "C0" || psub->Grade == "D+" || psub->Grade == "D0" || psub->Grade == "F")
				break;
		}
	}

}

void CalcGPA(Subject* psub) // 과목당 교과목 평점 구하기_숫자로 바꿔준 학점과 과목당 학점을 곱함
{
	psub->GPA = psub->GPA * psub->Hakjumm;

}
float CalcAveGPA(Subject* psub)// 교과목 평균 평점구하기 - 과목정보를 담고있는 동적으로 할당된 구조체 Subject를 가리키는 구조체 포인터 psub 
{
	sum = sum + psub->GPA; // 각 교과목의 평점을 더해 전역변수 sum에 넣기
	haksum = haksum + psub->Hakjumm; // 각 교과목의 학점을 더해 전역변수 haksum에 넣기
	return sum / haksum; // 교과목 평균 평점구하기 = 각 교과목의 평점의 합 / 각 교과목 학점의 총 합
}

void InputData(Student* pSt, int StudentNum) // 모든 정보를 입력받는 함수
{
	for (int i = 0; i < StudentNum; i++)
	{
		cout << "*" << i + 1 << "번째 학생 이름과 학번을 입력하세요.\n";
		cout << "이름 : ";
		InputValue((pSt + i)->StdName); // 인자가 문자열이므로 문자열 입력 함수 호출
		cout << "학번 : ";
		InputValue(pSt[i].Hakbun);
		cout << "\n"; // 인자가 정수이므로 정수형 입력 함수 호출

		cout << "수강한 과목 수 입력 :";
		InputValue(pSt[i].SubNum);

		pSt[i].Sub = new Subject[(pSt[i].SubNum)]; // 입력받은 과목 수 만큼 과목 정보 공간을 동적할당

		for (int j = 0; j < (pSt[i].SubNum); j++)
		{
			cout << "* 수강한 교과목" << pSt[i].SubNum << "개와 각 교과목명, 과목학점, 과목등급을 입력하세요.\n";

			cout << "교과목 명:";
			InputValue(pSt[i].Sub[j].SubName); // 인자가 문자열이므로 문자열 입력 함수 호출
			cout << "과목 학점수:";
			InputValue(pSt[i].Sub[j].Hakjumm); // 인자가 정수이므로 정수형 입력 함수 호출
			cout << "과목등급<A+ ~F>:";
			InputValue(pSt[i].Sub[j].Grade); // 인자가 정수이므로 정수형 입력 함수 호출

			info_hak((pSt + i)->Sub + j); // 등급을 제대로 입력했는지 확인하는 절차_각 학생마다 할당된 과목 구조체를 인자로 전달
			convert_number((pSt + i)->Sub + j); // 학점을 숫자평점으로 바꿔주는 함수_ 각각의 과목을 인자로 전달하여 계산
			CalcGPA((pSt + i)->Sub + j); // 교과목 평점 계산
			pSt[i].AveGPA = CalcAveGPA((pSt + i)->Sub + j); // 평균 평점 계산
		}
		sum = 0;
		haksum = 0; // 다음 반복을 위해 초기화
	}
}

void PrintOneData(Student* ptr) // 각 개인의 정보를 출력해주는 함수 - ptr은 포인터라는 것을 기억해야함
{
	cout.width(10);
	cout << "이름 : " << ptr->StdName; // 이름출력
	cout.width(10);
	cout << "학번 : " << ptr->Hakbun << "\n" << "\n"; // 학번출력
	cout.width(20);
	cout << "====================================================================\n";
	cout.width(15);
	cout << "과목명" << "            과목학점" << "      과목등급 " << "      과목평점 " << "\n";
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
	cout << "평균 평점 :" << ptr->AveGPA << "\n" << "\n";
}

void PrintAllData(Student* ptr) // 전체 학생 정보 출력 - Student 구조체를 가리키는 구조체 포인터 ptr
{
	PrintOneData(ptr); // 각각의 학생 정보를 가리키는 구조체 포인터를 인수로 전달 
}

Student* StdSearch(Student* pSt, string name) // Student 구조체를 가리키는 구조체 포인터 pSt
{
	if (pSt->StdName == name) // (매개변수로 넘어온)번째 학생의 이름과 입력받은 이름을 비교
		return pSt; // 해당 학생 정보가 있는 주소를 리턴 - 주소를 리턴한다는 것을 반드시 기억해야함
	else
		return 0;
}

Subject* SubSearch(const Student* pSt) // 특정 과목을 검색하는 함수
{
	string subject; // string 문자열 객체
	cout << "검색할 과목 이름 :"; // 교과목이 있는지 검색
	InputValue(subject);
	int i;
	for (i = 0; i < pSt->SubNum; i++) // 수강하는 과목의 수만큼 반복
	{
		if (subject == pSt->Sub[i].SubName) // 입력받은 과목과 수강 과목들을 차례대로 비교
			return &(pSt->Sub[i]); // 해당 과목이 있는곳의 주소를 리턴함
		else
			continue; // 일치하는 과목을 찾지 못했다면, 계속 다음 반복을 수행
	}
	if (i == pSt->SubNum)
	{
		cout << "일치하는 과목이 없습니다. \n"; // 일치하는 과목이 없을 경우, 메세지 출력
		return NULL; // 널값을 반환
	}

}

void PrintAllStdList(Student* pSt) // 전체 학생의 목록(학번, 이름)을 출력하는 함수_ Student 구조체를 가리키는 포인터 pSt사용
{
	cout << "====================================\n";
	cout.width(15);
	cout << "학번";
	cout.width(15);
	cout << "이름\n";
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

void ModifyStdInfo(Student* ptr, int StudentNum) // 특정 학생의 이름과 학번을 수정할 수 있는 함수
{
	cout << "검색할 학생의 이름:";
	string name;
	InputValue(name);
	int i;
	Student* SearchStd; // 학생 정보를 찾는 함수의 리턴 값(주소)을 받는 구조체 포인터
	for (i = 0; i < StudentNum; i++) // 학생 수 만큼 입력받은 이름과 학생 이름들을 비교
	{
		SearchStd = StdSearch(ptr + i, name); // 학생찾기
		if (SearchStd != NULL) // 이름을 찾았다면
		{
			string Type; // 학생정보 또는 과목정보 문자열 저장용 string
			cout << "수정<학생정보/과목정보>:"; // 학생정보수정 or 과목정보수정 선택
			InputValue(Type);
			if (Type == "학생정보") // 학생정보 수정이면
			{
				cout << "*< " << SearchStd->StdName << "  " << SearchStd->Hakbun << " >의 정보를 수정하세요\n"; // 주소를 받았기때문에 SearchStd는 해당 학생의 주소를 이미 가리키고 있음.
				cout << "이름 :";                                                                               // SearchStd[i].Hakbun 으로 착각하지 않도록 주의_ 학생을 이미 가리키고 있음!
				InputValue(SearchStd->StdName); // 정보수정
				cout << "학번 :";
				InputValue(SearchStd->Hakbun); // 정보 수정
				break; // 이름을 찾았으면 반복문 탈출
			}
			else if (Type == "과목정보") // 과목정보 수정
			{
				Subject* subb = SubSearch(SearchStd); // 과목이름 탐색 결과를 받을 구조체
				if (subb != NULL)
				{
					cout << "*< " << subb->SubName << ", 학점 : " << subb->Hakjumm << ", 등급 : " << subb->Grade << " >의 정보를 수정하세요\n";
					cout << "교과목명: ";
					InputValue(subb->SubName);
					cout << "과목학점 :";
					InputValue(subb->Hakjumm);
					cout << "과목등급 :";
					InputValue(subb->Grade);

					info_hak(subb); // 등급을 제대로 입력했는지 확인하는 절차_각 학생마다 할당된 과목 구조체를 인자로 전달
					convert_number(subb); // 학점을 숫자평점으로 바꿔주는 함수_ 각각의 과목을 인자로 전달하여 계산
					CalcGPA(subb); // 교과목 평점 계산

					sum = 0;
					haksum = 0;
					for (int r = 0; r < SearchStd->SubNum; r++) // 수강한 과목 수 만큼 반복
					{
						SearchStd->AveGPA = CalcAveGPA(SearchStd->Sub + r); // 평균 평점 계산
					}

				}
			}
			return; // 정상 종료
		}
		else
			continue; // 이름을 찾지 못했다면 다음 반복을 계속 수행
	}
	if (i == StudentNum) cout << "일치하는 이름이 없습니다.\n"; // 명단에 이름이 없다면, 오류 메세지 출력

	sum = 0;
	haksum = 0;
}

int main(void)
{
	while (1)
	{
		Print_Menu();
		if (num == 1)
		{// num의 값이 1이라면 학생 정보 입력 받기
			cout << "학생 수 입력 :";
			InputValue(StudentNum);
			ptr = new Student[StudentNum]; // 입력받은 학생수 만큼 필요한 공간을 동적으로 할당

			InputData(ptr, StudentNum); // 모든 데이터 입력
		}
		else if (num == 2) // 2를 누르면
		{
			cout << "\n";
			cout.width(45);
			for (int z = 0; z < StudentNum; z++)
			{
				PrintAllData(ptr + z); // 전체 학생 성적 보기
			}

		}
		else if (num == 3) // 3을 누르면 학생찾기
		{
			int i;
			Student* SearchStd; // 학생이름 탐색 결과를 받을 구조체
			cout << "검색할 학생 이름:";
			string name;
			InputValue(name);
			for (i = 0; i < StudentNum; i++) // 학생 수 만큼 입력받은 이름과 학생 이름들을 비교
			{
				SearchStd = StdSearch(ptr + i, name);
				if (SearchStd != NULL)
				{
					PrintOneData(SearchStd);// 학생 이름 탐색 결과를 받는 구조체에 들어있는 실제 값을 인자로 넘겨줌.
					break; // 이름을 찾았으면 반복문 탈출
				}
				else
					continue; // 이름을 찾지 못했다면 다음 반복을 계속 수행
			}
			if (i == StudentNum) // 이름을 찾지 못했다면
				cout << "일치하는 학생이 없습니다.\n";
		}
		else if (num == 4) // 4번을 누르면,
		{
			PrintAllStdList(ptr); // 전체 학생 목록 출력
		}
		else if (num == 5) // 5번을 누르면,
		{
			ModifyStdInfo(ptr, StudentNum); // 학생 정보 수정
		}
		else if (num != 1 && num != 2 && num != 3 && num != 4 && num != 5) // num이 메뉴번호 외의 값이면, 무한반복문 탈출
		{
			cout << "프로그램을 종료합니다.";
			break;
		}
	}
}

