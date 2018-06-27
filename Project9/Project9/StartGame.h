#pragma once
#include <string>
using namespace std;

enum selectMode { Easy = 0, Normal = 1, Hard = 2 };

class StartGame
{
public:
	StartGame();
	~StartGame();

	int Play();

private:
	selectMode SelectMode();
	bool SelectContinue();

	string inputNum;
	string gameMode;
};

