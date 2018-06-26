#include <iostream>
#include <fstream>
#include <string>
#include "WriteFile.h"
using namespace std;

template void WriteFile<int>(string fileName, int fileContentsNum, int* RankingSort);
template void WriteFile<double>(string fileName, int fileContentsNum, double* RankingSort);

template <typename X>
void WriteFile(string fileName, int fileContentsNum, X* RankingSort) // ランキングファイルへの書き込み
{
	ofstream ofs;
	ofs.open(fileName, std::ios::out);

	for (int a = 0; a < fileContentsNum; a++)
	{
		ofs << RankingSort[a];
		// 配列の最後でなければ (配列終了の 1 つ前までは) 改行を挿入
		if (a != (fileContentsNum - 1))
		{
			ofs << '\n';
		}
	}

	// ランキングファイルを閉じる
	ofs.close();
}