/**************************************************/
/*             HW#4 : 개선된 함수 기능 실습       */
/*  작성자 : 차현아        날짜 : 2021년 4월 2일 */
/*                                               */
/* 문제 정의 : 4-2. 함수 템플릿 이해하기         */
/*************************************************/
#include<iostream>
#define SIZE 5
using namespace std;
int num; // 메뉴번호를 입력받는 변수
void PrintMenu() // 메뉴를 출력하는 함수
{
	cout.width(15);
	cout << "< 메뉴 >\n";
	cout << "---------------------\n";
	cout.width(10);
	cout << "1. 정수 정렬\n" << "2. 실수 정렬\n" << "3. 종료\n";
	cout << "메뉴 선택 :";
	cin >> num;
}
template <class T> void Sort(T a[]) // 오름차순 정렬을 위한 함수 템플릿_ T자리에는 실수형 or 정수형 중 어떠한 자료형도 들어올 수 있다.
{
	for (int i = 0; i < SIZE - 1; i++) // 제일 마지막 인덱스는 비교대상 기준이 될 필요가 없기 때문에 SIZE-1까지 돌리기
	{
		T min = a[i]; // 최소값을 배열의 (i)첫번째 원소로 지정
		for (int j = i + 1; j < SIZE; j++)
		{
			if (min > a[j]) // 배열의 두번째 원소(j)부터 차례대로 (i)번째 원소랑 비교시작_ min보다 작은 값이 나오면,
			{               // 그 작은 값을 i자리로 옮겨야함.
				min = a[j]; 
				T temp = a[i]; // 어떤 자료형의 수가 들어올지 모르기 때문에 빈방의 자료형도 T로 지정.
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}

	cout << "정렬 결과 : "; 
	for (int z = 0; z < SIZE; z++) // 오름차순 정렬 결과 출력
	{
		cout.width(8);
		cout << a[z];
	}
	cout << "\n";
}

int main(void)
{
	while (1) // 무한 반복문
	{
		PrintMenu(); // 메뉴출력
		if (num == 1) // 1을 누르면, 
		{
			int arr[SIZE];
			cout << "5개의 정수를 입력하세요 :";
			for (int i = 0; i < SIZE; i++)
			{
				cin >> arr[i]; // 정수 입력 받기
			}
			Sort(arr); // 함수 템플릿에서 T가 int가 됨.
		}
		else if (num == 2) // 2를 누르면,
		{
			double arr2[SIZE];
			cout << "5개의 실수를 입력하세요 :";
			for (int i = 0; i < SIZE; i++)
			{
				cin >> arr2[i]; // 실수 입력 받기
			}
			Sort(arr2); // 함수 템플릿에서 T가 double이 됨
		}
		else if (num == 3) // 3을 누르면
			break; // 종료
		else // 메뉴번호 외의 값을 입력하면
			cout << "존재하지 않는 메뉴번호를 누르셨습니다.\n"; // 오류메세지 출력
	}
}
