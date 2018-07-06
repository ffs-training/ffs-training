#include "Conductor.h"
#include "SetScore.h"
#include "PlayMusic.h"
#include "PlayBeep.h"
#include "UserInput.h"
#include <iostream>


Conductor::Conductor()
{
}


Conductor::~Conductor()
{
}

void Conductor::SetAndPlay()
{
	UserInput userInput; // 楽譜とモードを選択
	int selectScoreNum = userInput.SelectScoreNum();
	int selectPlayMode = userInput.SelectPlayMode();

	SetScore setscore; // 楽譜を用意
	vector<string> score = setscore.SetSelectedScore(selectScoreNum);

	PlayMusic *playMusic = NULL; // モードに合うインスタンスを生成
	CreatePlayer(selectPlayMode, playMusic);

	playMusic->Play(&score); // 演奏

	system("PAUSE"); // 演奏途中でプログラムが終了しないように待つ

	delete playMusic;
}


void Conductor::CreatePlayer(int modeNum, PlayMusic*& playMusic)
{
	if (modeNum == 1)
	{
		playMusic = new PlayBeep();
	}
}