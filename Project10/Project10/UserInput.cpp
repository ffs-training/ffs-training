#include "UserInput.h"
#include <iostream>
#include <string>
using namespace std;



UserInput::UserInput()
{
}


UserInput::~UserInput()
{
}

int UserInput::InputData()
{
	// ���[�U�[�ɉ���I��������
	cout << "���t���������ɑΉ����鐔������͂��AEnter �L�[�������Ă��������B\n";
	cout << " �� (A4) �� 4 ������ ... 1" << '\n';
	cout << " �\ (G5) �� 8 ������ ... 2" << '\n';
	cout << "\n";

	string inputNum;

	bool isWrongNum = true;
	while (isWrongNum)
	{
		cout << ">> ";

		cin >> inputNum;
		cout << "\n";

		if (inputNum == "1") // A4 4 ��
		{
			isWrongNum = false;
		}
		else if (inputNum == "2") // G5 8 ��
		{
			isWrongNum = false;
		}
		else
		{
			cout << "������l�����͂���܂����B\n";
			cout << "1 �܂��� 2 ����͂��AEnter �L�[�������Ă��������B\n";
			cout << "\n";
		}
	}

	return (stoi)(inputNum);
}
