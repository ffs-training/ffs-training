#include "Note.h"
#include "CalcTimeLength.h"


Note::Note()
{
	frequency = 0;
	duration = 0;
}


Note::~Note()
{
}

int Note::SetFrequency(int num)
{
	if (num == 1)
	{
		frequency = 440; // A4
	}
	if (num == 2)
	{
		frequency = 784; // G5
	}

	return frequency;
}

int Note::SetDuration(int tempo, int divisionNum)
{
	duration = CalcTimeLength::CalcTime(tempo, divisionNum);
	return duration;
}