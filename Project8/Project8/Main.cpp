#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;

#include "ReadQuestionFile.h"
#include "SelectMode.h"
#include "AskQuestion.h"
#include "EditScoreFile.h"
#include "EditTimeFile.h"
#include "ShowResult.h"
#include "SelectContinue.h"

using namespace std;

struct GameType // game �������ꍇ�͕ێ����Ăق�������
{
public:
	int fileQuestionNum;  // �t�@�C���ɏ����ꂽ���̐�
	string* question; // �t�@�C���ɏ����ꂽ�����i�[�����z��
};

struct OneGameScore // 1 game ���ƂɃ��Z�b�g��������
{
public:
	int thisTimeQuestionNum;  // �o�萔
	int score;
	double totalTime;
	string gameMode; // mode �𕶎���

	OneGameScore()
	{
		thisTimeQuestionNum = 0;
		score = 0;
		totalTime = 0;
		gameMode.clear();
	}
};

int main()
{
	GameType typinggame;
	memset(&typinggame, NULL, sizeof(typinggame)); // �\���̂̏�����

	// ������v���C�ł���悤�ɐݒ�Acontinue ���Ȃ��ꍇ�� false �ɏ���������
	bool isContinued = true;

	// ���t�@�C���̓ǂݍ���
	// (������v���C����ꍇ���ǂݍ��݂͈�x�ł����̂� while ���[�v�O��)
	ReadQuestionFile(typinggame.fileQuestionNum, typinggame.question);

	while (isContinued)
	{
		OneGameScore oneGameScore;
		//memset(&oneGameScore, NULL, sizeof(oneGameScore)); // �\���̂̏�����
		SelectMode(oneGameScore.thisTimeQuestionNum, oneGameScore.gameMode);
		AskQuestion(oneGameScore.thisTimeQuestionNum, typinggame.fileQuestionNum, typinggame.question, oneGameScore.totalTime, oneGameScore.score);
		EditScoreFile(oneGameScore.gameMode, oneGameScore.score);
		EditTimeFile(oneGameScore.gameMode, oneGameScore.totalTime);
		ShowResult(oneGameScore.score, oneGameScore.thisTimeQuestionNum, oneGameScore.totalTime);

		isContinued = SelectContinue();
	}

	// �������̊J���K�v�H??

	return 0;
}