#include "BeepSetTempo.h"
#include "SplitString.h"
#include <iostream>
using namespace std;



BeepSetTempo::BeepSetTempo()
{
}


BeepSetTempo::~BeepSetTempo()
{
}

int BeepSetTempo::SetTempo(string elementTempo)
{
	SplitString splitString;
	int tempo = splitString.devideNum(elementTempo, "tempo=");

	cout << "* tempo [ " << tempo << " ]\n";

	return tempo;
}
