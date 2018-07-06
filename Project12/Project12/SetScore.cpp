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


vector<string> SetScore::SetSelectedScore(int num)
{
	if (num == 1)
	{
		fileName = "Violin1.txt";
	}
	if (num == 2)
	{
		fileName = "Violin1TempoArrange.txt";
	}
	if (num == 3)
	{
		fileName = "TwinkleTwinkleLittleStar.txt";
	}

	ifstream ifs;
	ifs.open(fileName);

	if (ifs.fail())
	{
		cout << "ファイルを開けませんでした。\n";
	}

	string str;
	vector<string> score;
	while (ifs && getline(ifs, str))
	{
		score.push_back(str);
	}

	ifs.close();

	return score;
}