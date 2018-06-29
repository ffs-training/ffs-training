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
		duration = 1000; // 4 •ª‰¹•„
	}
	if (num == 2)
	{
		duration = 500; // 8 •ª‰¹•„ ((4 •ª‰¹•„‚Ì’·‚³) / 2)
	}

	return duration;
}