#include <iostream>
#include <string>
#include <time.h>
#include "AskQuestion.h"
using namespace std; 

void AskQuestion(int thisTimeQuestionNum, int fileQuestionNum, string*& question, double& totalTime, int& score) 
    // 問題をランダムに"出題"する関数 + 同時に時間計測
{
	string answer;

	cout << "問題文と同じ文を入力し、Enter キーを押してください。\n";
	cout << "（ 1 問 間違えるごとにペナルティとして 時間が 10 秒加算されます ）\n\n";

	for (int r = 0; r < thisTimeQuestionNum; r++)
	{
		srand((unsigned)time(NULL));

		string thisquestion = question[rand() % fileQuestionNum];
		cout << "Q." << r + 1 << ' ' << thisquestion << '\n';

		// タイマースタート
		clock_t start = clock();

		// ユーザーからの入力
		cout << ">> ";
		cin >> answer;
		cout << '\n';

		// タイマーストップ
		clock_t end = clock();

		// 累積時間
		totalTime = totalTime + (double)(end - start) / CLOCKS_PER_SEC;

		// 入力判定
		if (thisquestion == answer)
		{
			score = score + 1;
		}
	}

	// 1 問間違えるごとに 10 sec のペナルティとする
	totalTime = totalTime + ((double)(thisTimeQuestionNum - score) * 10.0);
}