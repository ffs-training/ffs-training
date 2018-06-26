#include <iostream>
#include <fstream>
#include <string>
#include "EditTimeFile.h"
#include "ReadFile.h"
#include "WriteFile.h"
using namespace std;

void EditTimeFile(string gameMode, double totalTime) // time ファイルに結果を追加してソート、上書きする関数
{
	// ファイル名の指定
	string timeFileName = gameMode + "ModeTimeFile.txt";

	int timeRankingNum;
	double* timeRanking;

	ReadFile(timeFileName, totalTime, timeRankingNum, timeRanking);

	// 結果をソート (time は昇順で (値が小さいものから))
	for (int s = 0; s < timeRankingNum - 1; s++)
	{
		for (int t = s + 1; t < timeRankingNum; t++)
		{
			// 次の箱に入っている数字の方が小さいとき
			if (timeRanking[s] > timeRanking[t])
			{
				double tmp = timeRanking[t];
				timeRanking[t] = timeRanking[s];
				timeRanking[s] = tmp;
			}
		}
	}

	WriteFile(timeFileName, timeRankingNum, timeRanking);
}