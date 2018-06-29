#include "Note.h"



Note::Note()
{
	frequency = 0;
	duration = 0;
}


Note::~Note()
{
}

int Note::ReturnFrequency(int num)
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

int Note::ReturnDuration(int num)
{
	if (num == 1)
	{
		duration = 1000; // 4 分音符
	}
	if (num == 2)
	{
		duration = 500; // 8 分音符 ((4 分音符の長さ) / 2)
	}

	return duration;
}