#include "BeepPlayNote.h"
#include "BeepCalcFrequency.h"
#include "BeepCalcDuration.h"
#include <Windows.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;



BeepPlayNote::BeepPlayNote()
{
	frequency = 0;
	duration = 0;
}


BeepPlayNote::~BeepPlayNote()
{
}

void BeepPlayNote::PlayNote(string note, int wholeToneLength)
{
	CalcNote(SplitToElement(note), wholeToneLength);
	// 値をもとに計算
	Beep(frequency, duration);
	cout << "Note < f: " << frequency << ", d: " << duration << " >\n";
}

vector<string> BeepPlayNote::SplitToElement(string singleNote) // 1 音を要素に分解
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


void BeepPlayNote::CalcNote(vector<string> noteElement, int wholeToneLength)
{
	// 音符の計算
	int aN = 0;
	int a0 = 440;
	double n = 0.0;

	string octave = noteElement[0];
	string soundLength = noteElement[1];
	string scale = noteElement[2];

	BeepCalcFrequency beepCalcFrequency;
	beepCalcFrequency.SetOctave(octave, n);
	beepCalcFrequency.SetScale(scale, n);
	aN = (int)(a0 * pow(2, (n / 12.0)));
	frequency = aN;

	BeepCalcDuration beepCalcDuration;
	duration = beepCalcDuration.SetNoteLength(soundLength, wholeToneLength);
}