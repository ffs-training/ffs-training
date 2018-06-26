#include <iostream>
#include <string>
#include "SelectMode.h"
using namespace std;

void SelectMode(int& thisTimeQuestionNum, string& gameMode) // ゲームの難易度を決めさせる関数
{
	// 難易度の出力
	cout << '\n';
	cout << "遊びたいゲームの難易度に合う数字を入力し、Enter キーを押してください。\n";
	cout << " EASY   ...  0" << '\n';
	cout << " NORMAL ...  1" << '\n';
	cout << " HARD   ...  2" << '\n';
	cout << '\n';

	bool isWrongInput = true;
	string imode;

	while (isWrongInput)
	{
		cout << ">> ";
		cin >> imode;
		cout << '\n';

		// 指定した数字が選ばれたとき
		if (imode == "0")
		{
			isWrongInput = false;
			gameMode = "Easy";
		}
		else if (imode == "1")
		{
			isWrongInput = false;
			gameMode = "Normal";
		}
		else if (imode == "2")
		{
			isWrongInput = false;
			gameMode = "Hard";
		}

		// 指定した数字が選ばれなかったとき
		else
		{
			cout << "0, 1, 2 のいずれかの数字を入力してください。\n\n";
		}
	}

	thisTimeQuestionNum = 5 * ((stoi)(imode) + 1); // 0 -> 5 問、1 -> 10 問、2 -> 15 問、に設定
}