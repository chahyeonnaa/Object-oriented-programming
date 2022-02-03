#pragma once
#include<iostream>
#include<string>
#include"InputUtil.h"
using namespace std;

class IOInterface { // �θ� Ŭ����
protected:
	string m_name;
	int m_data;

public:
	IOInterface(string m_name) // �����ִ� ������
	{
		this->m_name = m_name;
		cout << "IOInterface�� �����ִ� ������ ȣ��\n";
	}
	IOInterface() // ����Ʈ ������
	{
		m_name = "";
		m_data = 0;
		cout << "IOInterface�� ����Ʈ ������ ȣ��\n";
	}
	~IOInterface() // �Ҹ���
	{
		cout << "IOInterface�� �Ҹ��� ȣ��\n";
	}
	void InputData() // ��������� �� �Է�
	{
		InputUtil::InputValue(m_name);
		InputUtil::InputValue(m_data);
	}

	void PrintData()const // ��������� �� ���
	{
		cout << m_name << "\n";
		cout << m_data << "\n";
	}
	void Modify(string name, int data) // ��������� �� ����
	{
		m_name = name;
		m_data = data;
	}

	string GetName()const // �������Լ� : m_name�� Ŭ���� �ۿ��� ���� �� �ְ���.
	{
		return m_name;
	}
	int GetData()const // �������Լ� : m_data�� Ŭ���� �ۿ��� ���� �� �ְ���.
	{
		return m_data;
	}



};

