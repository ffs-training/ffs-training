#include "BeepCalcFrequency.h"
#include "SplitString.h"
#include <map>
#include <iostream>
using namespace std;

enum scaleNum { C = -9, D = -7, E = -5, F = -4, G = -2, A = 0, B = 2 };

BeepCalcFrequency::BeepCalcFrequency()
{
	tone = { "A", "B", "C", "D", "E", "F", "G" };
	itr = tone.end();
}


BeepCalcFrequency::~BeepCalcFrequency()
{
}

void BeepCalcFrequency::SetOctave(string octave, double &n)
{
	// オクターブの判定
	SplitString splitString;
	int noteLengthNum = splitString.devideNum(octave, "O");
	noteLengthNum = noteLengthNum - 4;
	n = n + (12 * noteLengthNum);
}

void BeepCalcFrequency::SetScale(string scale, double &n)
{
	// 音階の判定
	if (scale.find("+") != std::string::npos)
	{
		n = n + 1;
	}
	else if (scale.find("-") != std::string::npos)
	{
		n = n - 1;
	}

	map<string, int> mp;
	mp["A"] = A;
	mp["B"] = B;
	mp["C"] = C;
	mp["D"] = D;
	mp["E"] = E;
	mp["F"] = F;
	mp["G"] = G;

    for (itr = tone.begin(); itr != tone.end(); ++itr)
	{
		if (scale.find(*itr) != std::string::npos )
		{
			n = n + (mp[*itr]);
			break;
		}

	}
}
