#pragma once
#include <string>
using namespace std;
class BeepCalcDuration
{
public:
	BeepCalcDuration();
	~BeepCalcDuration();
	int SetNoteLength(string, int);
	int SetRestLength(string, int);
};

