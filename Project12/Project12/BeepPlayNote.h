#pragma once
#include <string>
#include <vector>
using namespace std;
class BeepPlayNote
{
private:
	int frequency;
	int duration;
public:
	BeepPlayNote();
	~BeepPlayNote();
	void PlayNote(string, int);
private:
	vector<string> SplitToElement(string);
	void CalcNote(vector<string>, int);
};

