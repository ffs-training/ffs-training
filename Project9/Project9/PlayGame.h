#pragma once
#include <string>
using namespace std;

class PlayGame
{
public:
	PlayGame();
	~PlayGame();

	virtual void AskQuestion();
	int ReturnQuestionNum();
	int ReturnScore();
	double ReturnTotalTime();

protected:
	static int questionNum;
	static int score;
	static double totalTime;
};

