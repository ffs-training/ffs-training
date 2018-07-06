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
	// �l�����ƂɌv�Z
	Beep(frequency, duration);
	cout << "Note < f: " << frequency << ", d: " << duration << " >\n";
}

vector<string> BeepPlayNote::SplitToElement(string singleNote) // 1 ����v�f�ɕ���
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


void BeepPlayNote::CalcNote(vector<string> noteElement, int wholeToneLength)
{
	// �����̌v�Z
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