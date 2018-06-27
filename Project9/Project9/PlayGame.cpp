#include <iostream>
#include <string>
#include <time.h>
#include "PlayGame.h"
#include "PlayGameEasy.h"
#include "PlayGameNormal.h"
#include "PlayGameHard.h"
#include "GameDataSet.h"
using namespace std;

int PlayGame::questionNum = 0;
int PlayGame::score = 0;
double PlayGame::totalTime = 0;

PlayGame::PlayGame()
{
}


PlayGame::~PlayGame()
{
}

void PlayGame::AskQuestion() // 問題をランダムに出題（+ 同時に時間計測）する関数
{
	int questionDataNum = GameDataSet::ReturnQuestionDataNum();

	string answer;

	cout << "問題文と同じ文を入力し、Enter キーを押してください。\n";
	cout << "（ 1 問 間違えるごとにペナルティとして 時間が 10 秒加算されます ）\n\n";
	srand((unsigned)time(NULL));
	for (int r = 0; r < questionNum; r++)
	{

		int n = rand() % questionDataNum;
		string question = GameDataSet::ReturnQuestionData(n);
		cout << "Q." << r + 1 << ' ' << question << '\n';

		// タイマースタート
		clock_t start = clock();

		// ユーザーからの入力
		cout << ">> ";
		cin >> answer;
		cout << '\n';

		// タイマーストップ
		clock_t end = clock();

		// totalTime に今回かかった時間を加算
		totalTime = totalTime + (double)(end - start) / CLOCKS_PER_SEC;

		// 入力判定
		if (question == answer)
		{
			score = score + 1;
		}
	}

	// 出題＆解答がすべて終了したタイミングで（（不正解数） × 10）sec を totalTime に加算（ペナルティ）
	totalTime = totalTime + ((double)(questionNum - score) * 10.0);
}

int PlayGame::ReturnQuestionNum()
{
	return questionNum;
}

int PlayGame::ReturnScore()
{
	return score;
}

double PlayGame::ReturnTotalTime()
{
	return totalTime;
}