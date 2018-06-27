#pragma once
#include "PlayGame.h"
class PlayGameHard :
	public PlayGame
{
public:
	using PlayGame::AskQuestion;
	using PlayGame::ReturnQuestionNum;
	using PlayGame::ReturnScore;
	using PlayGame::ReturnTotalTime;
	PlayGameHard();
	~PlayGameHard();
};

