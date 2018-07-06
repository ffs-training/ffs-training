#include "BeepCalcDuration.h"
#include "SplitString.h"
#include <string>
#include <iostream>
using namespace std;



BeepCalcDuration::BeepCalcDuration()
{
}


BeepCalcDuration::~BeepCalcDuration()
{
}


int BeepCalcDuration::SetNoteLength(string noteLength, int wholeToneLength)
{
	// 音長の判定
	SplitString splitString;
	int noteLengthNum = splitString.devideNum(noteLength, "L");
	if (wholeToneLength <= 0)
	{
		cout << "音符の長さがマイナスもしくは 0 になっています。\n";
		return -1;
	}
	int noteDuration = wholeToneLength / noteLengthNum;
	return noteDuration;

}

int BeepCalcDuration::SetRestLength(string elementRest, int wholeToneLength)
{
	// 休符の計算
	SplitString splitString;
	int restNum = splitString.devideNum(elementRest, "P");
	if (wholeToneLength <= 0)
	{
		cout << "音符の長さがマイナスもしくは 0 になっています。\n";
		return -1;
	}
	int restDuration = wholeToneLength / restNum;
	return restDuration;
}