#pragma once
#include "PlayGame.h"
class PlayGameEasy :
	public PlayGame
{
public:
	using PlayGame::AskQuestion;
	using PlayGame::ReturnQuestionNum;
	using PlayGame::ReturnScore;
	using PlayGame::ReturnTotalTime;
	PlayGameEasy();
	~PlayGameEasy();
};

