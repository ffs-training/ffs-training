#include "PlayBeep.h"
#include "PlayMusic.h"
#include <Windows.h>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <math.h>
#include <stdio.h>
using namespace std;

enum scaleNum { C = -9, D = -7, E = -5, F = -4, G = -2, A = 0, B = 2 };
enum noteOrRestOrTempo { Note = 1, Rest = 2, Tempo = 3 };

int PlayBeep::wholeToneLength;
int PlayBeep::tempo = 100; // default ��ݒ�

PlayBeep::PlayBeep()
{
	wholeToneLength = 0;

	frequency = 0;
	duration = 0;
}

PlayBeep::~PlayBeep()
{
}

void PlayBeep::CalcWholeToneLength(int tempo)
{
	wholeToneLength = (240000 / tempo);
}


int PlayBeep::JudgeScoreContent(string element)
{
	if (element.find("tempo") != std::string::npos)
	{
		return noteOrRestOrTempo(Tempo); // �e���|
	}
	else if (element.find("P") != std::string::npos)
	{
		return noteOrRestOrTempo(Rest); // �x��
	}
	else if (element.find("O") != std::string::npos)
	{
		return noteOrRestOrTempo(Note); // ����
	}
	else
	{
		cout << "�y���̒��ɉ����E�x���E�e���|�ȊO�̗v�f���܂܂�Ă���\��������܂��B\n";
	}

	return 0;
}

vector<string> PlayBeep::SplitToElement(string singleNote)
{
	vector<string> element;
	char* p;
	char* copy = _strdup(singleNote.c_str()); // �ΏۂƂȂ镶����
	const char* delim = " "; // �f���~�^�i��؂蕶���j
	char* ctx;

	// �v�f 1 ��
	p = strtok_s(copy, delim, &ctx);
	element.push_back(p);

	// �v�f 2 �ڈȍ~
	while (p != NULL)
	{
		p = strtok_s(NULL, delim, &ctx);
		if (p != NULL)
		{
			element.push_back(p);
		}
	}

	delete[] copy;
	return element;
}

void PlayBeep::CalcNote(vector<string> element)
{
	int aN = 0;
	int a0 = 440;
	double n = 0.0;

	string octave = element[0];
	string Notelength = element[1];
	string scale = element[2];

	SetOctave(octave, n);
	SetScale(scale, n);
	aN = (int)(a0 * pow(2, (n / 12.0)));
	frequency = aN;

	SetNoteLength(Notelength);
}

void PlayBeep::SetOctave(string octave, double &n)
{
	// �I�N�^�[�u�̔���
	if (octave.find("O") != std::string::npos)
	{
		char* p;
		char* copy = _strdup(octave.c_str());
		const char* delim = "O";
		char* ctx;

		p = strtok_s(copy, delim, &ctx);
		int a = (stoi)(p);
		a = a - 4;
		n = n + (12 * a);
		delete[] copy;
	}
	else
	{
		cout << "�����̑� 1 �v�f�ɃI�N�^�[�u���Z�b�g����Ă��܂���B\n";
	}
}

void PlayBeep::SetScale(string scale, double &n)
{
	// ���K�̔���
	if (scale.find("+") != std::string::npos)
	{
		n++;
	}
	else if (scale.find("-") != std::string::npos)
	{
		n--;
	}

	if (scale.find("A") != std::string::npos)
	{
		n = n + scaleNum(A);
	}
	else if (scale.find("B") != std::string::npos)
	{
		n = n + scaleNum(B);
	}
	else if (scale.find("C") != std::string::npos)
	{
		n = n + scaleNum(C);
	}
	else if (scale.find("D") != std::string::npos)
	{
		n = n + scaleNum(D);
	}
	else if (scale.find("E") != std::string::npos)
	{
		n = n + scaleNum(E);
	}
	else if (scale.find("F") != std::string::npos)
	{
		n = n + scaleNum(F);
	}
	else if (scale.find("G") != std::string::npos)
	{
		n = n + scaleNum(G);
	}
	else
	{
		cout << "�����̑� 3 �v�f�ɉ��K (A-G) ���Z�b�g����Ă��܂���B\n";
	}
}


void PlayBeep::SetNoteLength(string noteLength)
{
	// �����̔���
	if (noteLength.find("L") != std::string::npos)
	{
		char* p;
		char* copy = _strdup(noteLength.c_str());
		const char* delim = "L";
		char* ctx;

		p = strtok_s(copy, delim, &ctx);
		duration = wholeToneLength / (atoi)(p);
		delete[] copy;
	}
}

int PlayBeep::CalcRest(string elementRest)
{
	char* p;
	char* copy = _strdup(elementRest.c_str());
	const char* delim = "P";
	char* ctx;

	p = strtok_s(copy, delim, &ctx);
	duration = wholeToneLength / (atoi)(p);
	delete[] copy;
	return duration;
}

void PlayBeep::SetTempo(string elementTempo)
{
	if (elementTempo.find("tempo=") != std::string::npos)
	{
		char* p;
		char* copy = _strdup(elementTempo.c_str());
		const char* delim = "tempo=";
		char* ctx;

		p = strtok_s(copy, delim, &ctx);
		tempo = (stoi)(p);
		delete[] copy;
	}
}

void PlayBeep::Play(vector<string>* score)
{
	vector<string>::iterator itr;

	for (itr = score->begin(); itr != score->end(); ++itr)
	{
		string singleTone = *itr;	
		switch (JudgeScoreContent(singleTone))
		{
		case Note:
		{
			CalcNote(SplitToElement(singleTone));
			// �l�����ƂɌv�Z
			Beep(frequency, duration);
			cout << "Note < f: " << frequency << ", d: " << duration << " >\n";
			break;
		}
		case Rest:
		{
			Sleep(CalcRest(singleTone));
			cout << "Rest < " << CalcRest(singleTone) << " >\n";
			break;
		}
		case Tempo:
		{
			SetTempo(singleTone);
			CalcWholeToneLength(tempo);
			cout << "* tempo [ " << tempo << " ]\n";
			break;
		}
		default:
			break;
		}
	}
}

