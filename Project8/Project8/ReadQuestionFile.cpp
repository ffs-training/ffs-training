#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include "ReadQuestionFile.h"
using namespace std;

void ReadQuestionFile(int& fileQuestionNum, string*& question) // ファイルを開けて、問題を配列に格納する関数
{
	// 問題ファイルを開く
	ifstream fin;
	string fileName = "quention.txt";
	fin.open(fileName, std::ios::in);

	// ファイルが開けなかったとき
	if (!fin)
	{
		cout << "問題ファイルをオープンできませんでした。\n\n";
	}

	// ファイルが開けたとき
	else
	{
		cout << "問題ファイルをオープンしました。\n\n";
	}

	string line;

	// 問題ファイルの行数を数える
	while (!fin.eof())
	{
		getline(fin, line);
		fileQuestionNum = fileQuestionNum + 1;
	}

	// eof フラグをクリア
	fin.clear();

	// ファイルポインタを先頭に移動
	fin.ifstream::seekg(0, ios_base::beg);

	// 行数に合わせて配列を作成
	question = new string[fileQuestionNum];

	// テキストを１行ずつ読み取って配列に格納
	for (int j = 0; j < fileQuestionNum; j++)
	{
		getline(fin, line);
		question[j] = line;
	}

	// 問題ファイルを閉じる
	fin.close();
}