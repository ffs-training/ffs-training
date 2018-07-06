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
	// �����̔���
	SplitString splitString;
	int noteLengthNum = splitString.devideNum(noteLength, "L");
	if (wholeToneLength <= 0)
	{
		cout << "�����̒������}�C�i�X�������� 0 �ɂȂ��Ă��܂��B\n";
		return -1;
	}
	int noteDuration = wholeToneLength / noteLengthNum;
	return noteDuration;

}

int BeepCalcDuration::SetRestLength(string elementRest, int wholeToneLength)
{
	// �x���̌v�Z
	SplitString splitString;
	int restNum = splitString.devideNum(elementRest, "P");
	if (wholeToneLength <= 0)
	{
		cout << "�����̒������}�C�i�X�������� 0 �ɂȂ��Ă��܂��B\n";
		return -1;
	}
	int restDuration = wholeToneLength / restNum;
	return restDuration;
}