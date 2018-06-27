#pragma once
#include "PlayGame.h"
class PlayGameNormal :
	public PlayGame
{
public:
	using PlayGame::AskQuestion;
	using PlayGame::ReturnQuestionNum;
	using PlayGame::ReturnScore;
	using PlayGame::ReturnTotalTime;
	PlayGameNormal();
	~PlayGameNormal();
};

