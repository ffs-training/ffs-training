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
	cout << "演奏したい楽譜の番号を選択・入力して Enter キーを押してください。\n";
	cout << "\n";
	cout << " 番号 : 楽譜名" << "\n";
	cout << "  1   : Symphony No.25 in G Minor, K.183 Violin1 <Normal>" << "\n";
	cout << "  2   : Symphony No.25 in G Minor, K.183 Violin1 <Tempo Arrange>" << "\n";
	cout << "  3   : きらきらぼし（前半）" << "\n";
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
			cout << "正しい数字を入力してください。\n\n";
		}
	}

	return (stoi)(num);
}

int UserInput::SelectPlayMode()
{
	cout << "演奏したい Mode 番号を選択・入力して Enter キーを押してください。\n";
	cout << "\n";
	cout << " 番号 : Mode" << "\n";
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
			cout << "正しい数字を入力してください。\n\n";
		}
	}

	return (stoi)(num);
}