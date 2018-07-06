#include "BeepPlayRest.h"
#include "BeepCalcDuration.h"
#include <string>
#include <iostream>
#include <Windows.h>
using namespace std;



BeepPlayRest::BeepPlayRest()
{
}


BeepPlayRest::~BeepPlayRest()
{
}

void BeepPlayRest::PlayRest(string line, int wholeToneLength)
{
	BeepCalcDuration beepCalcDuration;
	Sleep(beepCalcDuration.SetRestLength(line, wholeToneLength));
	cout << "Rest < " << beepCalcDuration.SetRestLength(line, wholeToneLength) << " >\n";
}