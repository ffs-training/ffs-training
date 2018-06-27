#include <iostream>
#include <fstream>
#include <string>
#include "GameDataSet.h"
#include "OutputResult.h"
using namespace std;

OutputResult::OutputResult()
{
}


OutputResult::~OutputResult()
{
}

void OutputResult::EditFile(string gameMode, double totalTime, int score) // 各ファイルの編集を行う関数を呼び出すための関数
{
	EditTimeFile(gameMode, totalTime);
	EditScoreFile(gameMode, score);
}

void OutputResult::EditTimeFile(string gameMode, double totalTime) // time ファイルに結果を追加してソート、上書きする関数
{
	// ファイル名の指定
	string timeFileName = gameMode + "ModeTimeFile.txt";

	int timeRankingNum;
	string * timeFileRead;
	ReadFile(timeFileName, timeRankingNum, timeFileRead);

	// string から double に配列を変換
	double* timeRanking;

	timeRankingNum++;
	timeRanking = new double[timeRankingNum];

	for (int i = 0; i < (timeRankingNum - 1); i++)
	{
		timeRanking[i] = (stod)(timeFileRead[i]);
	}

	// 配列の最後尾に今回の結果を格納
	timeRanking[timeRankingNum - 1] = totalTime;

	// 結果をソート (time は昇順で (値が小さいものから))
	for (int s = 0; s < (timeRankingNum - 1); s++)
	{
		for (int t = s + 1; t < timeRankingNum; t++)
		{
			// 次の箱に入っている数字の方が小さいとき
			if (timeRanking[s] > timeRanking[t])
			{
				double tmp = timeRanking[t];
				timeRanking[t] = timeRanking[s];
				timeRanking[s] = tmp;
			}
		}
	}

	WriteFile(timeFileName, timeRankingNum, timeRanking);

	delete[] timeFileRead;
	delete[] timeRanking;
}

void OutputResult::EditScoreFile(string gamemode, int score) // score ファイルに結果を追加してソート、上書きする関数
{
	string scoreFileName = gamemode + "ModeScoreFile.txt";

	int scoreRankingNum;
	string * scoreFileRead;

	ReadFile(scoreFileName, scoreRankingNum, scoreFileRead);

	// string から int に配列を変換
	int* scoreRanking;
	scoreRankingNum++;
	scoreRanking = new int[scoreRankingNum];

	for (int i = 0; i < (scoreRankingNum - 1); i++)
	{
		scoreRanking[i] = (stoi)(scoreFileRead[i]);
	}

	// 配列の最後尾に今回の結果を格納
	scoreRanking[scoreRankingNum - 1] = score;

	// 結果をソート (score は降順 (値が大きいものから順に))
	for (int s = 0; s < (scoreRankingNum - 1); s++)
	{
		for (int t = s + 1; t < scoreRankingNum; t++)
		{
			//次の箱に入っている数字の方が大きいとき
			if (scoreRanking[s] < scoreRanking[t])
			{
				int tmp = scoreRanking[t];
				scoreRanking[t] = scoreRanking[s];
				scoreRanking[s] = tmp;
			}
		}
	}

	WriteFile(scoreFileName, scoreRankingNum, scoreRanking);

	delete[] scoreFileRead;
	delete[] scoreRanking;
}

void OutputResult::ReadFile(string fileName, int& fileContentsNum, string*& RankingSort) // ファイルに記載されているデータを string 型の配列に格納する関数
{
	// ファイルを開く
	ifstream ifs;
	ifs.open(fileName, std::ios::in);

	// ファイルが開けなかったとき
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

	// eof フラグをクリア
	ifs.clear();

	// ファイルポインタを先頭に移動
	ifs.ifstream::seekg(0, ios_base::beg);

	// 必要な要素数分の配列を作成
	RankingSort = new string[fileContentsNum];

	// テキストを 1 行ずつ読み取って配列に格納
	while (!ifs.eof())
	{
		for (int j = 0; j < fileContentsNum; j++)
		{
			getline(ifs, line);
			RankingSort[j] = line;
		}
	}

	// ファイルを閉じる
	ifs.close();
}

template void OutputResult::WriteFile<int>(string, int, int*);
template void OutputResult::WriteFile<double>(string, int, double*);

template <typename X>
void OutputResult::WriteFile(string fileName, int fileContentsNum, X* RankingSort) // ランキングファイルへ書き込む関数
{
	ofstream ofs;
	ofs.open(fileName, std::ios::out);

	for (int a = 0; a < fileContentsNum; a++)
	{
		ofs << RankingSort[a];
		// 配列の最後でなければ (最後の配列の 1 つ前までは) 改行を挿入
		if (a != (fileContentsNum - 1))
		{
			ofs << '\n';
		}
	}

	// ランキングファイルを閉じる
	ofs.close();
}

void OutputResult::ShowResult(int score, int questionNum, double totalTime) // 結果を表示する関数
{
	// 今回の結果を表示
	cout << "今回のあなたの成績は…\n";
	cout << "正答率 " << score << " / " << questionNum << " でした！" << '\n';
	cout << "所要時間 " << totalTime << " 秒でした！" << '\n';
	cout << '\n';
}