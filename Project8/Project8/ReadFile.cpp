#include <iostream>
#include <fstream>
#include <string>
#include "ReadFile.h"
using namespace std;

template void ReadFile<int>(string, int, int&, int*&);
template void ReadFile<double>(string, double, int&, double*&);

template <typename T>
void ReadFile(string fileName, T result, int& fileContentsNum, T*& RankingSort)
// ファイルに記載されているデータを配列に格納し、配列の最後に今回の結果を追加する関数
{
	// ファイルを開く
	ifstream ifs;
	ifs.open(fileName, std::ios::in);
	 
	// ファイルが開けなかったとき (開けないことがあるのか？)
	if (!ifs)
	{
		cout << "ファイル「" << fileName << "」をオープンできませんでした。\n\n";
	}

	// ファイルが開けたとき
	else
	{
		cout << "ファイル「" << fileName << "」をオープンしました。\n\n";
	}

	string line;

	// ファイルの行数を数える
	fileContentsNum = 0;

	while (!ifs.eof())
	{
		getline(ifs, line);
		fileContentsNum = fileContentsNum + 1;
	}

	// 最後に今回の結果を追加するので、配列要素数を 1 プラス
	fileContentsNum++;

	// eof フラグをクリア
	ifs.clear();

	// ファイルポインタを先頭に移動
	ifs.ifstream::seekg(0, ios_base::beg);

	// 必要な要素数分の配列を作成
	RankingSort = new T[fileContentsNum];

	// テキストを 1 行ずつ読み取って配列に格納
	while (!ifs.eof())
	{
		for (int j = 0; j < fileContentsNum - 1; j++)
		{
			getline(ifs, line);
			RankingSort[j] = stod(line);
		}
	}

	// 配列の最後尾に今回の結果を格納
	RankingSort[fileContentsNum - 1] = result;

	// ファイルを閉じる
	ifs.close();
}