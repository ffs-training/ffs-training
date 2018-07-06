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
		cout << "tempo ‚Ì’l‚ª 0 ˆÈ‰º‚È‚Ì‚Å‰¹•„E‹x•„‚Ì’·‚³‚ªŒvŽZ‚Å‚«‚Ü‚¹‚ñB\n";
		return -1;
	}
	if (tempo > 0)
	{
		wholeToneLength = (4 * 60 * 1000) / tempo;
	}
	return 0;
}