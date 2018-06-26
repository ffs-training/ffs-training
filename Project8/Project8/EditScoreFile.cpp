#include <iostream>
#include <fstream>
#include <string>
#include "EditScoreFile.h"
#include "ReadFile.h"
#include "WriteFile.h"
using namespace std;

void EditScoreFile(string gamemode,int score) // score_rank �t�@�C���Ɍ��ʂ�ǉ����ă\�[�g�A�㏑������֐�
{
	string scoreFileName = gamemode + "ModeScoreFile.txt";

	int scoreRankingNum;
	int* scoreRanking;

	ReadFile(scoreFileName, score, scoreRankingNum, scoreRanking);

	// ���ʂ��\�[�g (score �͍~�� (�l���傫�����̂��珇��))
	for (int s = 0; s < scoreRankingNum - 1; s++)
	{
		for (int t = s + 1; t < scoreRankingNum; t++)
		{
			//���̔��ɓ����Ă��鐔���̕����傫���Ƃ�
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