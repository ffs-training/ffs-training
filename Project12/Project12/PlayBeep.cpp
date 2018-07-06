#include "PlayBeep.h"
#include "PlayMusic.h"
#include "BeepPlayNote.h"
#include "BeepPlayRest.h"
#include "BeepSetTempo.h"
#include "BeepCalcWholeTone.h"
#include <Windows.h>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <math.h>
#include <stdio.h>
using namespace std;

enum noteOrRestOrTempo { Note = 1, Rest = 2, Tempo = 3 };

int PlayBeep::wholeToneLength;
int PlayBeep::tempo;

PlayBeep::PlayBeep()
{
	wholeToneLength = 600;
	tempo = 100; // default 値を設定
}

PlayBeep::~PlayBeep()
{
}

int PlayBeep::JudgeScoreContent(string line)
{
	if (line.find("tempo=") != std::string::npos)
	{
		return noteOrRestOrTempo(Tempo); // テンポ
	}
	else if (line.find("P") != std::string::npos)
	{
		return noteOrRestOrTempo(Rest); // 休符
	}
	else if (line.find("O") != std::string::npos)
	{
		return noteOrRestOrTempo(Note); // 音符 (音符は O から始まるようにしてある)
	}
	else
	{
		cout << "楽譜の中に音符・休符・テンポ以外の要素が含まれている可能性があります。\n";
	}

	return 0;
}

void PlayBeep::Play(vector<string>* score)
{
	vector<string>::iterator itr;

	int isContinue = 0;

	for (itr = score->begin(); itr != score->end(); ++itr)
	{
		if (isContinue < 0)
		{
			break;
		}

		string line = *itr;	
		switch (JudgeScoreContent(line))
		{
		case Note:
		{
			BeepPlayNote beepPlayNote;
			beepPlayNote.PlayNote(line, wholeToneLength);
			break;
		}
		case Rest:
		{
			BeepPlayRest beepPlayRest;
			beepPlayRest.PlayRest(line, wholeToneLength);
			break;
		}
		case Tempo:
		{
			BeepSetTempo beepSetTempo;
			tempo = beepSetTempo.SetTempo(line);
			BeepCalcWholeTone beepCalcWholeTone;
			isContinue |= beepCalcWholeTone.CalcWholeToneLength(tempo, wholeToneLength);
			break;
		}
		default:
			break;
		}
	}
}

