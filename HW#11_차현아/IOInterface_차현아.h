#pragma once
#include<iostream>
#include<string>
#include"InputUtil.h"
using namespace std;

class IOInterface { // 부모 클래스
protected:
	string m_name;
	int m_data;

public:
	IOInterface(string m_name) // 인자있는 생성자
	{
		this->m_name = m_name;
		cout << "IOInterface의 인자있는 생성자 호출\n";
	}
	IOInterface() // 디폴트 생성자
	{
		m_name = "";
		m_data = 0;
		cout << "IOInterface의 디폴트 생성자 호출\n";
	}
	~IOInterface() // 소멸자
	{
		cout << "IOInterface의 소멸자 호출\n";
	}
	void InputData() // 멤버변수의 값 입력
	{
		InputUtil::InputValue(m_name);
		InputUtil::InputValue(m_data);
	}

	void PrintData()const // 멤버변수의 값 출력
	{
		cout << m_name << "\n";
		cout << m_data << "\n";
	}
	void Modify(string name, int data) // 멤버변수의 값 수정
	{
		m_name = name;
		m_data = data;
	}

	string GetName()const // 접근자함수 : m_name을 클래스 밖에서 읽을 수 있게함.
	{
		return m_name;
	}
	int GetData()const // 접근자함수 : m_data를 클래스 밖에서 읽을 수 있게함.
	{
		return m_data;
	}



};

