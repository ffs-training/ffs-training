#include <iostream>
#include <string>
#include <time.h>
#include "PlayGame.h"
#include "PlayGameEasy.h"
#include "PlayGameNormal.h"
#include "PlayGameHard.h"
#include "GameDataSet.h"
using namespace std;

int PlayGame::questionNum = 0;
int PlayGame::score = 0;
double PlayGame::totalTime = 0;

PlayGame::PlayGame()
{
}


PlayGame::~PlayGame()
{
}

void PlayGame::AskQuestion() // ���������_���ɏo��i+ �����Ɏ��Ԍv���j����֐�
{
	int questionDataNum = GameDataSet::ReturnQuestionDataNum();

	string answer;

	cout << "��蕶�Ɠ���������͂��AEnter �L�[�������Ă��������B\n";
	cout << "�i 1 �� �ԈႦ�邲�ƂɃy�i���e�B�Ƃ��� ���Ԃ� 10 �b���Z����܂� �j\n\n";
	srand((unsigned)time(NULL));
	for (int r = 0; r < questionNum; r++)
	{

		int n = rand() % questionDataNum;
		string question = GameDataSet::ReturnQuestionData(n);
		cout << "Q." << r + 1 << ' ' << question << '\n';

		// �^�C�}�[�X�^�[�g
		clock_t start = clock();

		// ���[�U�[����̓���
		cout << ">> ";
		cin >> answer;
		cout << '\n';

		// �^�C�}�[�X�g�b�v
		clock_t end = clock();

		// totalTime �ɍ��񂩂��������Ԃ����Z
		totalTime = totalTime + (double)(end - start) / CLOCKS_PER_SEC;

		// ���͔���
		if (question == answer)
		{
			score = score + 1;
		}
	}

	// �o�聕�𓚂����ׂďI�������^�C�~���O�Łi�i�s���𐔁j �~ 10�jsec �� totalTime �ɉ��Z�i�y�i���e�B�j
	totalTime = totalTime + ((double)(questionNum - score) * 10.0);
}

int PlayGame::ReturnQuestionNum()
{
	return questionNum;
}

int PlayGame::ReturnScore()
{
	return score;
}

double PlayGame::ReturnTotalTime()
{
	return totalTime;
}