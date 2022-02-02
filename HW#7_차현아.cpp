/*****************************************************/
/*             HW#7 : 객체지향 프로그래밍 시작하기   */
/*  작성자 : 차현아        날짜 : 2021년 4월 30일    */
/*                                                   */
/* 문제 정의 : vector 클래스 사용해보기              */
/******************************************************/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct WORD
{
	string str;
	int count;
};
vector<WORD*> words; // WORD 구조체를 가리키는 구조체 포인터들의 공간을 품어주는 벡터 클래스의 객체 words

int CountWords(string buffer) // 해당 단어가 있는지 확인
{
	int i;
	for (i = 0; i < words.size(); i++)
	{
		if (words.at(i)->str == buffer) // 해당 단어가 구조체 안에 있으면 
		{
			(words.at(i)->count) += 1; // count 1 증가
			break; // 반복문 탈출
		}
		else // 해당 단어를 찾지 못했으면 
			continue; // 반복을 계속 이어나감
	}

	if (i == words.size()) // 찾고자 하는 단어가 구조체 안에 없으면
	{
		words.push_back(new WORD); // 벡터 클래스의 객체 words에 구조체 공간을 할당해줘야함. *중요*
		words.at(i)->str = buffer;// 단어를 구조체에 넣어줌.
		(words.at(i)->count) = 0; // 카운트 값을 0으로 초기화
		(words.at(i)->count) += 1; // count 1 증가
		return 0;
	}

}
void PrintWords() // 결과 출력
{
	cout << "============\n";
	for (int i = 0; i < words.size(); i++) // 모든 내용을 출력
	{
		cout << words.at(i)->str << ": " << words.at(i)->count;
		cout << "\n";
	}
	cout << "============\n";
}
int main()
{
	cout << "문자열 입력. 종료 : Ctrl+Z \n";
	string buffer; // 입력받을 문자열을 담을 객체
	while (1)// Ctrl+Z가 입력될때까지 문자열을 계속 입력 받음
	{
		cin >> buffer;
		if (cin.eof()) // Ctrl+Z가 입력되면 반복문 탈출
			break;
		CountWords(buffer);
	}

	PrintWords(); // 결과 출력
	words.clear(); // 모든 원소를 제거
}


