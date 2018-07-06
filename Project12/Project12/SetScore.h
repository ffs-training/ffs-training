#pragma once
#include <vector>
#include <string>
using namespace std;

class SetScore
{
private:
	string fileName;
public:
	SetScore();
	~SetScore();
	vector<string> SetSelectedScore(int);
};

