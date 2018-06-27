#pragma once
#include <string>
using namespace std;

class GameDataSet
{
public:
	GameDataSet();
	~GameDataSet();

	void ReadQuestionFile();
	static int ReturnQuestionDataNum();
	static string ReturnQuestionData(int);

	static int questionDataNum;
	static string* questionData;
};

