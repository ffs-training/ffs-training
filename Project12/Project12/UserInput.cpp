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

int UserInput::SelectScoreNum()
{
	cout << "���t�������y���̔ԍ���I���E���͂��� Enter �L�[�������Ă��������B\n";
	cout << "\n";
	cout << " �ԍ� : �y����" << "\n";
	cout << "  1   : Symphony No.25 in G Minor, K.183 Violin1 <Normal>" << "\n";
	cout << "  2   : Symphony No.25 in G Minor, K.183 Violin1 <Tempo Arrange>" << "\n";
	cout << "  3   : ���炫��ڂ��i�O���j" << "\n";
	cout << "\n";

	string num;

	bool isWrongNum = true;
	while (isWrongNum)
	{
		cout << ">> ";
		cin >> num;
		cout << "\n\n";

		if (num == "1")
		{
			isWrongNum = false;
		}
		else if (num == "2")
		{
			isWrongNum = false;
		}
		else if (num == "3")
		{
			isWrongNum = false;
		}
		else
		{
			cout << "��������������͂��Ă��������B\n\n";
		}
	}

	return (stoi)(num);
}

int UserInput::SelectPlayMode()
{
	cout << "���t������ Mode �ԍ���I���E���͂��� Enter �L�[�������Ă��������B\n";
	cout << "\n";
	cout << " �ԍ� : Mode" << "\n";
	cout << "  1   : Beep" << "\n";
	cout << "\n";

	string num;

	bool isWrongNum = true;
	while (isWrongNum)
	{
		cout << ">> ";
		cin >> num;
		cout << "\n\n";

		if (num == "1")
		{
			isWrongNum = false;
		}
		else
		{
			cout << "��������������͂��Ă��������B\n\n";
		}
	}

	return (stoi)(num);
}