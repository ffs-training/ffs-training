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
	UserInput userInput; // �y���ƃ��[�h��I��
	int selectScoreNum = userInput.SelectScoreNum();
	int selectPlayMode = userInput.SelectPlayMode();

	SetScore setscore; // �y����p��
	vector<string> score = setscore.SetSelectedScore(selectScoreNum);

	PlayMusic *playMusic = NULL; // ���[�h�ɍ����C���X�^���X�𐶐�
	CreatePlayer(selectPlayMode, playMusic);

	playMusic->Play(&score); // ���t

	system("PAUSE"); // ���t�r���Ńv���O�������I�����Ȃ��悤�ɑ҂�

	delete playMusic;
}


void Conductor::CreatePlayer(int modeNum, PlayMusic*& playMusic)
{
	if (modeNum == 1)
	{
		playMusic = new PlayBeep();
	}
}