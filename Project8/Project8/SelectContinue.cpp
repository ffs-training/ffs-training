#include <iostream>
#include <string>
#include "SelectContinue.h"
using namespace std;

bool SelectContinue() // もう一度プレイするかユーザーに決めさせる関数
{
	cout << "もう一度遊びますか？\n";
	cout << "数字を選択し、入力してください。\n";
	cout << " YES ...  0" << '\n';
	cout << " NO  ...  1" << '\n';
	cout << '\n';

	string cont_num;

	bool setwrongnum = true;

	while (setwrongnum)
	{
		cout << "<< ";
		cin >> cont_num;
		cout << '\n';

		// continue するとき
		if (cont_num == "0")
		{
			setwrongnum = false;
			return true;
		}
		// continue しないとき
		else if (cont_num == "1")
		{
			// while の停止
			setwrongnum = false;
			return false;
		}
		// 指定した数字が選ばれなかったときは選択しなおし
		else
		{
			cout << "0 または 1 を入力してください。\n\n";
		}
	}
	return false;
}