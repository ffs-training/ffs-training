#include "StartGame.h"
#include "GameDataSet.h"
#include "PlayGame.h"
#include "PlayGameEasy.h"
#include "PlayGameNormal.h"
#include "PlayGameHard.h"
#include "OutputResult.h"
#include <iostream>
#include <stdio.h>

StartGame::StartGame()
{
}


StartGame::~StartGame()
{
}

selectMode StartGame::SelectMode() // �Q�[���̓�Փx�����߂�����֐�
{
	// ��Փx�̏o��
	cout << '\n';
	cout << "�V�т����Q�[���̓�Փx�ɍ�����������͂��AEnter �L�[�������Ă��������B\n";
	cout << " EASY   ...  0" << '\n';
	cout << " NORMAL ...  1" << '\n';
	cout << " HARD   ...  2" << '\n';
	cout << '\n';

	PlayGame *playgame = NULL;
	selectMode mode;

	bool isWrongInput = true;

	while (isWrongInput)
	{
		cout << ">> ";
		string input;
		cin >> input;
		cout << '\n';

		// �w�肵���������I�΂ꂽ�Ƃ�
		if (input == "0")
		{
			isWrongInput = false;
			gameMode = "Easy";
			mode = Easy;
		}
		else if (input == "1")
		{
			isWrongInput = false;
			gameMode = "Normal";
			mode = Normal;
		}
		else if (input == "2")
		{
			isWrongInput = false;
			gameMode = "Hard";
			mode = Hard;
		}

		// �w�肵���������I�΂�Ȃ������Ƃ��͑I�����Ȃ���
		else
		{
			cout << "�y���̓G���[�z 0, 1, 2 �̂����ꂩ�̐�������͂��Ă��������B\n\n";
		}
	}

	return mode;
}

bool StartGame::SelectContinue() // ������x�v���C���邩���[�U�[�Ɍ��߂�����֐�
{
	cout << "������x�V�т܂����H\n";
	cout << "��]������e�ɍ�����������͂��AEnter �L�[�������Ă��������B\n";
	cout << " YES ...  0" << '\n';
	cout << " NO  ...  1" << '\n';
	cout << '\n';

	bool setWrongNum = true;
	bool select = true;

	while (setWrongNum)
	{
		cout << ">> ";
		cin >> inputNum;
		cout << '\n';

		// continue ����Ƃ�
		if (inputNum == "0")
		{
			setWrongNum = false;
			select = true;
		}
		// continue ���Ȃ��Ƃ�
		else if (inputNum == "1")
		{
			// while �̒�~
			setWrongNum = false;
			select = false;
		}
		// �w�肵���������I�΂�Ȃ������Ƃ��͑I�����Ȃ���
		else
		{
			cout << "�y���̓G���[�z 0 �܂��� 1 ����͂��Ă��������B\n\n";
		}
	}
	return select;
}

int StartGame::Play() // �^�C�s���O�Q�[���̎��s�֐�
{
	GameDataSet gameDataSet;
	gameDataSet.ReadQuestionFile();

	bool isContinued = true;

	while (isContinued)
	{
		PlayGame *playGame = NULL;

		// �w�肵���������I�΂ꂽ�Ƃ�
		switch (SelectMode())
		{
		case Easy:
			playGame = new PlayGameEasy();
			break;
		case Normal:
			playGame = new PlayGameNormal();
			break;
		case Hard:
			playGame = new PlayGameHard();
			break;
		default:
			break;
		} 

		if (playGame == NULL)
		{
			cout << "�Q�[�������s�ł��܂���ł����B\n";
			return 1;
		}

		playGame->AskQuestion();

		OutputResult outputResult;
		outputResult.EditFile(gameMode, playGame->ReturnTotalTime(), playGame->ReturnScore());
		outputResult.ShowResult(playGame->ReturnScore(), playGame->ReturnQuestionNum(), playGame->ReturnTotalTime());

		isContinued = SelectContinue();

		delete playGame;
	}

	return 0;
}