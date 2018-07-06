#include "CalcWholeToneLength.h"


CalcWholeToneLength::CalcWholeToneLength()
{
	wholeTone = 0;
}


CalcWholeToneLength::~CalcWholeToneLength()
{
}

int CalcWholeToneLength::CalcWholeTone(int tempo)
{
	if (tempo == 0)
	{
		return 0;
	}
	if (tempo != 0)
	{
		wholeTone = (4 * 60 * 1000 / tempo); // �S���� (�S�x��) �̒������v�Z (ms)
	}
	
	return wholeTone;
}