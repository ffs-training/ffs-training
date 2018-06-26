#include <iostream>
#include <fstream>
#include <string>
#include "EditTimeFile.h"
#include "ReadFile.h"
#include "WriteFile.h"
using namespace std;

void EditTimeFile(string gameMode, double totalTime) // time �t�@�C���Ɍ��ʂ�ǉ����ă\�[�g�A�㏑������֐�
{
	// �t�@�C�����̎w��
	string timeFileName = gameMode + "ModeTimeFile.txt";

	int timeRankingNum;
	double* timeRanking;

	ReadFile(timeFileName, totalTime, timeRankingNum, timeRanking);

	// ���ʂ��\�[�g (time �͏����� (�l�����������̂���))
	for (int s = 0; s < timeRankingNum - 1; s++)
	{
		for (int t = s + 1; t < timeRankingNum; t++)
		{
			// ���̔��ɓ����Ă��鐔���̕����������Ƃ�
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