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
int PlayBeep::tempo = 100; // default 値を設定

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
	wholeToneLength = (4 * 60 * 1000) / tempo;
}


int PlayBeep::JudgeScoreContent(string line)
{
	if (line.find("tempo") != std::string::npos)
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

vector<string> PlayBeep::SplitToElement(string singleNote) // 1 音を要素に分解
{
	vector<string> element;
	char* p;
	char* copy = _strdup(singleNote.c_str()); // 対象となる文字列
	const char* delim = " "; // デリミタ（区切り文字）
	char* ctx;

	// 要素 1 つ目
	p = strtok_s(copy, delim, &ctx);
	element.push_back(p);

	// 要素 2 つ目以降
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

void PlayBeep::CalcNote(vector<string> noteElement)
{
	// 音符の計算
	int aN = 0;
	int a0 = 440;
	double n = 0.0;

	string octave = noteElement[0];
	string soundLength = noteElement[1];
	string scale = noteElement[2];

	SetOctave(octave, n);
	SetScale(scale, n);
	aN = (int)(a0 * pow(2, (n / 12.0)));
	frequency = aN;

	SetSoundLength(soundLength);
}

void PlayBeep::SetOctave(string octave, double &n)
{
	// オクターブの判定
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
		cout << "音符の第 1 要素にオクターブがセットされていません。\n";
	}
}

void PlayBeep::SetScale(string scale, double &n)
{
	// 音階の判定
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
		cout << "音符の第 3 要素に音階 (A-G) がセットされていません。\n";
	}
}


void PlayBeep::SetSoundLength(string noteLength)
{
	// 音長の判定
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
	// 休符の計算
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
		string line = *itr;	
		switch (JudgeScoreContent(line))
		{
		case Note:
		{
			CalcNote(SplitToElement(line));
			// 値をもとに計算
			Beep(frequency, duration);
			cout << "Note < f: " << frequency << ", d: " << duration << " >\n";
			break;
		}
		case Rest:
		{
			Sleep(CalcRest(line));
			cout << "Rest < " << CalcRest(line) << " >\n";
			break;
		}
		case Tempo:
		{
			SetTempo(line);
			CalcWholeToneLength(tempo);
			cout << "* tempo [ " << tempo << " ]\n";
			break;
		}
		default:
			break;
		}
	}
}

