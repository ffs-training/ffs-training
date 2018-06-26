#include <iostream>
#include <fstream>
#include <string>
#include "EditScoreFile.h"
#include "ReadFile.h"
#include "WriteFile.h"
using namespace std;

void EditScoreFile(string gamemode,int score) // score_rank ファイルに結果を追加してソート、上書きする関数
{
	string scoreFileName = gamemode + "ModeScoreFile.txt";

	int scoreRankingNum;
	int* scoreRanking;

	ReadFile(scoreFileName, score, scoreRankingNum, scoreRanking);

	// 結果をソート (score は降順 (値が大きいものから順に))
	for (int s = 0; s < scoreRankingNum - 1; s++)
	{
		for (int t = s + 1; t < scoreRankingNum; t++)
		{
			//次の箱に入っている数字の方が大きいとき
			if (scoreRanking[s] < scoreRanking[t])
			{
				int tmp = scoreRanking[t];
				scoreRanking[t] = scoreRanking[s];
				scoreRanking[s] = tmp;
			}
		}
	}

	WriteFile(scoreFileName, scoreRankingNum, scoreRanking);
}