#include "Note.h"
#include "CalcWholeToneLength.h"
#include <iostream>
using namespace std;

enum SelectSound { A4 = 1, G5 = 2 };

Note::Note()
{
	frequency = 0;
	duration = 0;
}


Note::~Note()
{
}

void Note::ReturnNoteInfo(int input, int& scale, int& divisionNum)
{
	switch (input)
	{
	case 1:
		scale = A4;
		divisionNum = 4;
		break;
	case 2:
		scale = G5;
		divisionNum = 8;
		break;
	default:
		break;
	}
}

void Note::SetFrequency(int num)
{
	if (num == 1)
	{
		frequency = 440; // A4
	}
	if (num == 2)
	{
		frequency = 784; // G5
	}
}

int Note::SetDuration(int tempo, int divisionNum)
{
	CalcWholeToneLength calcWholeNoteLength;
	if (divisionNum <= 0)
	{
		cout << "‰¹•„‚Ì’·‚³‚ÌÝ’è‚ªŒë‚Á‚Ä‚¢‚Ü‚·B\n";
		return -1;
	}
	if (divisionNum > 0)
	{
		duration = calcWholeNoteLength.CalcWholeTone(tempo) / divisionNum;
	}
	return 0;
}

int Note::GetFrequency()
{
	return frequency;
}

int Note::GetDuration()
{
	return duration;
}