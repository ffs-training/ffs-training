#include "BeepCalcWholeTone.h"
#include <iostream>
using namespace std;



BeepCalcWholeTone::BeepCalcWholeTone()
{
}


BeepCalcWholeTone::~BeepCalcWholeTone()
{
}

int BeepCalcWholeTone::CalcWholeToneLength(int tempo, int& wholeToneLength)
{
	if (tempo <= 0)
	{
		cout << "tempo �̒l�� 0 �ȉ��Ȃ̂ŉ����E�x���̒������v�Z�ł��܂���B\n";
		return -1;
	}
	if (tempo > 0)
	{
		wholeToneLength = (4 * 60 * 1000) / tempo;
	}
	return 0;
}