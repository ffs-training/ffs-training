#include "CalcTimeLength.h"

int CalcTimeLength::timeLength = 0;

CalcTimeLength::CalcTimeLength()
{
}


CalcTimeLength::~CalcTimeLength()
{
}

int CalcTimeLength::CalcTime(int tempo, int divisionNum)
{
	timeLength = (240000 / tempo); // �S���� (�S�x��) �̒������v�Z (ms)

	timeLength = timeLength / divisionNum;
	
	return timeLength;
}