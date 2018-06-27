#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include "GameDataSet.h"
using namespace std;

int GameDataSet::questionDataNum = 0;
string* GameDataSet::questionData;

GameDataSet::GameDataSet()
{
}


GameDataSet::~GameDataSet()
{
	delete[] questionData;
}

void GameDataSet::ReadQuestionFile() // ファイルを開けて、問題を配列に格納する関数
{
	// 問題ファイルを開く
	ifstream fin;
	string fileName = "quention.txt";
	fin.open(fileName, std::ios::in);

	// ファイルが開けなかったとき
	if (!fin)
	{
		cout << "問題ファイルをオープンできませんでした。\n";
	}
	// ファイルが開けたとき
	else
	{
		cout << "問題ファイルをオープンしました。\n";
	}

	string line;

	// 問題ファイルの行数を数える
	while (!fin.eof())
	{
		getline(fin, line);
		questionDataNum = questionDataNum + 1;
	}

	// eof フラグをクリア
	fin.clear();

	// ファイルポインタを先頭に移動
	fin.ifstream::seekg(0, ios_base::beg);

	// 行数に合わせて配列を作成
	questionData = new string[questionDataNum];

	// テキストを１行ずつ読み取って配列に格納
	for (int j = 0; j < questionDataNum; j++)
	{
		getline(fin, line);
		questionData[j] = line;
	}

	// 問題ファイルを閉じる
	fin.close();
}

int GameDataSet::ReturnQuestionDataNum()
{
	if (questionData != NULL)
	{
		return questionDataNum;
	}
	else
	{
		cout << "問題ファイルが読み込めていません。\n";
	}
}

string GameDataSet::ReturnQuestionData(int n)
{
	if (questionData != NULL)
	{
		return questionData[n];
	}
	else
	{
		cout << "問題ファイルが読み込めていません。\n";
	}
}
