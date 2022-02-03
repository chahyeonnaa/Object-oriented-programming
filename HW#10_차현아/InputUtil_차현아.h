#pragma once
#include<iostream>
#include<string>
using namespace std;

class InputUtil
{
public:

	inline static void InputValue(int& num) // ������ �Է½�
	{
		cin >> num;
		if (cin.fail() == 1) // ���ڸ� �Է��ؾ��ϴ� ���� ���ڰ� �ԷµǸ�,
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "������ �ٽ� �Է� :";
			InputUtil::InputValue(num); // ���Է� �޾ƾ���.
			return;
		}
		cin.ignore();
	}

	inline static void InputValue(string& name)// ���ڿ� �Է½�
	{
		getline(cin, name);
	
	}

	inline static void InputValue(char* word)
	{
		cin >> word;
		cin.ignore(); // ���� ����
	}

	inline static void InputValue(float& num)
	{
		cin >> num;
		cin.ignore(); // ���� ����
	}

	inline static void InputValue(double& num)
	{
		cin >> num;
		cin.ignore(); // ���� ����
	}


};

