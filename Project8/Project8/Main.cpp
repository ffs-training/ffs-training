#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;

#include "ReadQuestionFile.h"
#include "SelectMode.h"
#include "AskQuestion.h"
#include "EditScoreFile.h"
#include "EditTimeFile.h"
#include "ShowResult.h"
#include "SelectContinue.h"

using namespace std;

struct GameType // game が続く場合は保持してほしいもの
{
public:
	int fileQuestionNum;  // ファイルに書かれた問題の数
	string* question; // ファイルに書かれた問題を格納した配列
};

struct OneGameScore // 1 game ごとにリセットされるもの
{
public:
	int thisTimeQuestionNum;  // 出題数
	int score;
	double totalTime;
	string gameMode; // mode を文字化

	OneGameScore()
	{
		thisTimeQuestionNum = 0;
		score = 0;
		totalTime = 0;
		gameMode.clear();
	}
};

int main()
{
	GameType typinggame;
	memset(&typinggame, NULL, sizeof(typinggame)); // 構造体の初期化

	// 複数回プレイできるように設定、continue しない場合は false に書き換える
	bool isContinued = true;

	// 問題ファイルの読み込み
	// (複数回プレイする場合も読み込みは一度でいいので while ループ外で)
	ReadQuestionFile(typinggame.fileQuestionNum, typinggame.question);

	while (isContinued)
	{
		OneGameScore oneGameScore;
		//memset(&oneGameScore, NULL, sizeof(oneGameScore)); // 構造体の初期化
		SelectMode(oneGameScore.thisTimeQuestionNum, oneGameScore.gameMode);
		AskQuestion(oneGameScore.thisTimeQuestionNum, typinggame.fileQuestionNum, typinggame.question, oneGameScore.totalTime, oneGameScore.score);
		EditScoreFile(oneGameScore.gameMode, oneGameScore.score);
		EditTimeFile(oneGameScore.gameMode, oneGameScore.totalTime);
		ShowResult(oneGameScore.score, oneGameScore.thisTimeQuestionNum, oneGameScore.totalTime);

		isContinued = SelectContinue();
	}

	// メモリの開放必要？??

	return 0;
}