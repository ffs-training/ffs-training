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

selectMode StartGame::SelectMode() // ゲームの難易度を決めさせる関数
{
	// 難易度の出力
	cout << '\n';
	cout << "遊びたいゲームの難易度に合う数字を入力し、Enter キーを押してください。\n";
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

		// 指定した数字が選ばれたとき
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

		// 指定した数字が選ばれなかったときは選択しなおし
		else
		{
			cout << "【入力エラー】 0, 1, 2 のいずれかの数字を入力してください。\n\n";
		}
	}

	return mode;
}

bool StartGame::SelectContinue() // もう一度プレイするかユーザーに決めさせる関数
{
	cout << "もう一度遊びますか？\n";
	cout << "希望する内容に合う数字を入力し、Enter キーを押してください。\n";
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

		// continue するとき
		if (inputNum == "0")
		{
			setWrongNum = false;
			select = true;
		}
		// continue しないとき
		else if (inputNum == "1")
		{
			// while の停止
			setWrongNum = false;
			select = false;
		}
		// 指定した数字が選ばれなかったときは選択しなおし
		else
		{
			cout << "【入力エラー】 0 または 1 を入力してください。\n\n";
		}
	}
	return select;
}

int StartGame::Play() // タイピングゲームの実行関数
{
	GameDataSet gameDataSet;
	gameDataSet.ReadQuestionFile();

	bool isContinued = true;

	while (isContinued)
	{
		PlayGame *playGame = NULL;

		// 指定した数字が選ばれたとき
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
			cout << "ゲームが実行できませんでした。\n";
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