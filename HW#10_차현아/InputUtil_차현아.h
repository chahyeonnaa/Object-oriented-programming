#pragma once
#include<iostream>
#include<string>
using namespace std;

class InputUtil
{
public:

	inline static void InputValue(int& num) // 정수형 입력시
	{
		cin >> num;
		if (cin.fail() == 1) // 숫자를 입력해야하는 곳에 문자가 입력되면,
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "데이터 다시 입력 :";
			InputUtil::InputValue(num); // 재입력 받아야함.
			return;
		}
		cin.ignore();
	}

	inline static void InputValue(string& name)// 문자열 입력시
	{
		getline(cin, name);
	
	}

	inline static void InputValue(char* word)
	{
		cin >> word;
		cin.ignore(); // 버퍼 비우기
	}

	inline static void InputValue(float& num)
	{
		cin >> num;
		cin.ignore(); // 버퍼 비우기
	}

	inline static void InputValue(double& num)
	{
		cin >> num;
		cin.ignore(); // 버퍼 비우기
	}


};

