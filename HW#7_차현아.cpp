/*****************************************************/
/*             HW#7 : ��ü���� ���α׷��� �����ϱ�   */
/*  �ۼ��� : ������        ��¥ : 2021�� 4�� 30��    */
/*                                                   */
/* ���� ���� : vector Ŭ���� ����غ���              */
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
vector<WORD*> words; // WORD ����ü�� ����Ű�� ����ü �����͵��� ������ ǰ���ִ� ���� Ŭ������ ��ü words

int CountWords(string buffer) // �ش� �ܾ �ִ��� Ȯ��
{
	int i;
	for (i = 0; i < words.size(); i++)
	{
		if (words.at(i)->str == buffer) // �ش� �ܾ ����ü �ȿ� ������ 
		{
			(words.at(i)->count) += 1; // count 1 ����
			break; // �ݺ��� Ż��
		}
		else // �ش� �ܾ ã�� �������� 
			continue; // �ݺ��� ��� �̾��
	}

	if (i == words.size()) // ã���� �ϴ� �ܾ ����ü �ȿ� ������
	{
		words.push_back(new WORD); // ���� Ŭ������ ��ü words�� ����ü ������ �Ҵ��������. *�߿�*
		words.at(i)->str = buffer;// �ܾ ����ü�� �־���.
		(words.at(i)->count) = 0; // ī��Ʈ ���� 0���� �ʱ�ȭ
		(words.at(i)->count) += 1; // count 1 ����
		return 0;
	}

}
void PrintWords() // ��� ���
{
	cout << "============\n";
	for (int i = 0; i < words.size(); i++) // ��� ������ ���
	{
		cout << words.at(i)->str << ": " << words.at(i)->count;
		cout << "\n";
	}
	cout << "============\n";
}
int main()
{
	cout << "���ڿ� �Է�. ���� : Ctrl+Z \n";
	string buffer; // �Է¹��� ���ڿ��� ���� ��ü
	while (1)// Ctrl+Z�� �Էµɶ����� ���ڿ��� ��� �Է� ����
	{
		cin >> buffer;
		if (cin.eof()) // Ctrl+Z�� �ԷµǸ� �ݺ��� Ż��
			break;
		CountWords(buffer);
	}

	PrintWords(); // ��� ���
	words.clear(); // ��� ���Ҹ� ����
}


