#include "SetScore.h"
#include <fstream>
#include <iostream>
#include <iterator>



SetScore::SetScore()
{
}


SetScore::~SetScore()
{
}


vector<string> SetScore::SetSelectedScore(string scoreFileName)
{
	ifstream ifs;
	ifs.open(scoreFileName);

	if (ifs.fail())
	{
		cout << "ファイルを開けませんでした。\n";
	}

	string str;
	vector<string> violin1;
	while (ifs && getline(ifs, str))
	{
		violin1.push_back(str);
	}

	ifs.close();

	return violin1;
}