#pragma once
#include <vector>
#include <string>
using namespace std;
class BeepCalcFrequency
{
private:
	vector<string> tone;
	vector<string>::iterator itr;
public:
	BeepCalcFrequency();
	~BeepCalcFrequency();
	void SetOctave(string, double&);
	void SetScale(string, double&);
};

