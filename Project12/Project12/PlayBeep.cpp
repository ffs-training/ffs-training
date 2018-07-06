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
	tempo = 100; // default �l��ݒ�
}

PlayBeep::~PlayBeep()
{
}

int PlayBeep::JudgeScoreContent(string line)
{
	if (line.find("tempo=") != std::string::npos)
	{
		return noteOrRestOrTempo(Tempo); // �e���|
	}
	else if (line.find("P") != std::string::npos)
	{
		return noteOrRestOrTempo(Rest); // �x��
	}
	else if (line.find("O") != std::string::npos)
	{
		return noteOrRestOrTempo(Note); // ���� (������ O ����n�܂�悤�ɂ��Ă���)
	}
	else
	{
		cout << "�y���̒��ɉ����E�x���E�e���|�ȊO�̗v�f���܂܂�Ă���\��������܂��B\n";
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

