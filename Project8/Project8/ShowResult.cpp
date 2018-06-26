#include <iostream>
#include <string>
#include "ShowResult.h"
using namespace std;

void ShowResult(int score, int questionNum, double totalTime)
{
	// 今回の結果を表示
	cout << "今回のあなたの成績は…\n";
	cout << "正答率 " << score << " / " << questionNum << " でした！" << '\n';
	cout << "経過時間 " << totalTime << " 秒でした！" << '\n';
	cout << '\n';
}