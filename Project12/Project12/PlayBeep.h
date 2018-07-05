#pragma once
#include <string>
#include <vector>
#include "PlayMusic.h"
using namespace std;

class PlayBeep :
	public PlayMusic
{
public:
	PlayBeep();
	~PlayBeep();

	void Play(vector<string>*);

private:
	vector<string> SplitToElement(string);
	int JudgeScoreContent(string);
	void CalcNote(vector<string>);
	void SetOctave(string, double&);
	void SetScale(string, double&);
	void SetSoundLength(string);
	int CalcRest(string);
	void SetTempo(string);
	void CalcWholeToneLength(int);

	static int tempo;
	static int wholeToneLength;
	int frequency;
	int duration;
};

