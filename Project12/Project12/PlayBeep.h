#pragma once
#include <string>
#include <vector>
#include "PlayMusic.h"
using namespace std;

class PlayBeep :
	public PlayMusic
{
private:
	static int tempo;
	static int wholeToneLength;

public:
	PlayBeep();
	~PlayBeep();

	void Play(vector<string>*);

private:
	int JudgeScoreContent(string);

};

