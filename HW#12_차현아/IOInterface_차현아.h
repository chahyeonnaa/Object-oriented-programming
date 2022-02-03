#pragma once
#include<iostream>
#include<string>
#include"InputUtil.h"
using namespace std;

class IOInterface { // �θ� Ŭ����
public:

	virtual ~IOInterface() // ���� �Ҹ���_ �Ļ�Ŭ������ �Ҹ��� ���� �� �⺻ Ŭ������ �Ҹ��� ȣ��
	{
		cout << "IOInterface�� �Ҹ��� ȣ��\n";
	}

	virtual void InputData() = 0;// ���� �����Լ��� ����_�Ļ�Ŭ�������� �������ؼ� �� �� �ֵ��� ������ ����
	virtual void PrintData()const = 0;
	virtual void Modify() = 0;


};

