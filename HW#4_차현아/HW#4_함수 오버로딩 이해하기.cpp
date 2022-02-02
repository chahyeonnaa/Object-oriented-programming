/**************************************************/
/*             HW#4 : 개선된 함수기능             */
/*  작성자 : 차현아        날짜 : 2021년 4월 2일  */
/*                                                */
/* 문제 정의 : 4-1. 함수 오버로딩 이해하기        */
/*************************************************/
#include<iostream>
#include<cstring>
using namespace std;

void GetMin(int x, int y) // 두 정수중 최소값을 구하는 함수
{
	if (x < y)
		cout << "최소값은 " << x << "입니다.\n";
	else
		cout << "최소값은 " << y << "입니다.\n";
}
void GetMin(double x, double y) // 두 실수 중 최소값을 구하는 함수
{
	if (x < y)
		cout << "최소값은 " << x << "입니다.\n";
	else
		cout << "최소값은 " << y << "입니다.\n";
}
void GetMin(char x[], char y[]) // 두 문자열 중 작은 문자열을 구하는 함수
{
	if (strcmp(x, y) < 0) // 문자열을 구성하는 문자들의 아스키코드 값을 차례대로 비교
		cout << "최소값은 " << x << "입니다.\n";
	else
		cout << "최소값은 " << y << "입니다.\n";
}

void GetMin(int a[], int size) // 정수형 배열 중 최소값을 구하는 함수
{
	int min = a[0]; // min값을 배열의 첫번째 원소로 지정
	for (int i = 0; i < size; i++) // 배열 전체를 돌면서 비교
	{
		if (min > a[i]) // 앞에서 지정한 min보다 작은 값이 나타나면
			min = a[i]; // 그 값을 min으로 지정
	}
	cout << "최소값은 " << min << "입니다.\n";
}

int main(void)
{
	int num1, num2;
	double num3, num4;
	char str[20], str1[20];
	int num[10];
	cout << "두개의 정수를 입력하세요:";
	cin >> num1; cin >> num2;
	GetMin(num1, num2); // 정수 두개를 인자로하여 함수 호출 -> 정수형 GetMin 호출
	cout << "두개의 실수를 입력하세요:";
	cin >> num3;  cin >> num4;
	GetMin(num3, num4);  // 실수 두개를 인자로하여 함수 호출 -> 실수형 GetMin 호출
	cout << "두개의 문자열을 입력하세요:";
	cin >> str >> str1;
	GetMin(str, str1); // 문자열 두개를 인자로하여 함수 호출 -> 문자열형 GetMin 호출
	cout << "배열의 원소 :";
	for (int i = 0; i < 10; i++)
	{
		cin >> num[i]; // 배열에 들어갈 데이터 입력 받기
	}
	GetMin(num, 10); // 정수형 배열과 그 크기를 인자로하여 함수 호출 -> 정수 배열형 GetMin 호출
}
