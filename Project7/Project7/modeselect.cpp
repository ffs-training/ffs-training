//#include "modeselect.h"
//#include <iostream>
//
//modeselect::modeselect()
//{
//	// ユーザーに難易度（出題数）を決めさせる
//	cout << "ゲームの難易度を選択し、数字を入力してください。\n";
//	cout << "EASY   ...  0 \n";
//	cout << "NORMAL ...  1 \n";
//	cout << "HARD   ...  2 \n";
//}
//
//modeselect::~modeselect()
//{
//}
//
//void modeselect::selectnum()
//{
//	while (is_not_set)
//	{
//		cin >> num;
//
//		// 指定した数字が選ばれたとき
//		if (num == 0 || num == 1 || num == 2)
//		{
//			is_not_set = false;
//		}
//
//		// 指定した数字が選ばれなかったとき
//		else
//		{
//			cout << "0, 1, 2 のいずれかの数字を入力してください。\n";
//			getchar();
//		}
//
//	}
//}
//
//void modeselect::decidenum()
//{
//	// 0 -> 5 問、1 -> 10 問、2 -> 15 問、に設定
//	level = 5 * (num + 1);
//}
