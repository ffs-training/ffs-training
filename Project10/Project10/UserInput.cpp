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
	// ユーザーに音を選択させる
	cout << "演奏したい音に対応する数字を入力し、Enter キーを押してください。\n";
	cout << " ラ (A4) の 4 分音符 ... 1" << '\n';
	cout << " ソ (G5) の 8 分音符 ... 2" << '\n';
	cout << "\n";

	string inputNum;

	bool isWrongNum = true;
	while (isWrongNum)
	{
		cout << ">> ";

		cin >> inputNum;
		cout << "\n";

		if (inputNum == "1") // A4 4 分
		{
			isWrongNum = false;
		}
		else if (inputNum == "2") // G5 8 分
		{
			isWrongNum = false;
		}
		else
		{
			cout << "誤った値が入力されました。\n";
			cout << "1 または 2 を入力し、Enter キーを押してください。\n";
			cout << "\n";
		}
	}

	return (stoi)(inputNum);
}
