#include <iostream>
#include <fstream>
#include <string>
#include <random>
#include <time.h>
using namespace std;

struct game
{
public:
	// 配列は関数内で new, 変数は関数内で初期化
    string mode; // 数字以外の入力にも対応するために string
	int score;
	double totaltime;

	string* question;
	int* score_ranking;
	double* time_ranking;

	int setquestion_num;  // ファイルに書かれた問題の数
	int question_num;     // 選んだ難易度を元に計算する出題数
	int scoreranking_num; // スコアランキングファイルに書かれた要素数
	int timeranking_num;  // タイムランキングファイルに書かれた要素数

	string gamemode; // mode を元にファイル名を決定するために使用

	string Scorefilename;
	string Timefilename;
};

struct game typinggame; // 構造体を初めに書いておくことでグローバル変数を作成


int fileread() // ファイルを開けて、問題を配列に格納する関数
{
	// 問題ファイルを開く
	ifstream fin;
	fin.open("quention.txt", std::ios::in);

	// ファイルが開けなかったとき (開けないことがあるのか？)
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

	typinggame.setquestion_num = 0; // 初期化

	while (!fin.eof())
	{
		getline(fin, line);
		typinggame.setquestion_num = typinggame.setquestion_num + 1;
	}

	// eof フラグをクリア
	fin.clear();

	// ファイルポインタを先頭に移動
	fin.ifstream::seekg(0, ios_base::beg);

	// 行数に合わせて配列を作成
	typinggame.question = new string[typinggame.setquestion_num];

	// テキストを１行ずつ読み取って配列に格納
	for (int j = 0; j < typinggame.setquestion_num; j++)
	{
		getline(fin, line);
		typinggame.question[j] = line;
	}

	// 問題ファイルを閉じる
	fin.close();

	return 0;
}

int modeselect() // ゲームの難易度を決めさせる関数
{
	// 難易度の出力
	cout << '\n';
	cout << "遊びたいゲームの難易度に合う数字を入力し、Enter キーを押してください。\n";
	cout << " EASY   ...  0" << '\n';
	cout << " NORMAL ...  1" << '\n';
	cout << " HARD   ...  2" << '\n';
	cout << '\n';

	bool is_not_set = true;

	while (is_not_set)
	{
		cout << ">> ";
		cin >> typinggame.mode;
		cout << '\n';

		// 指定した数字が選ばれたとき
		if (typinggame.mode == "0" || typinggame.mode == "1" || typinggame.mode == "2")
		{
			is_not_set = false;
		}

		// 指定した数字が選ばれなかったとき
		else
		{
			cout << "0, 1, 2 のいずれかの数字を入力してください。\n\n";
		}
	}
	return (stoi)(typinggame.mode);
}

int numdecide(int a) // 出題数を決定する関数
{
	typinggame.question_num = 0; // 初期化
	typinggame.question_num = 5 * (a + 1); // 0 -> 5 問、1 -> 10 問、2 -> 15 問、に設定

	return typinggame.question_num;
}

double random() // 問題をランダムに出題する関数 + 同時に時間計測
{
	typinggame.totaltime = 0; // 初期化
	typinggame.score = 0; // 初期化

	string answer;

	cout << "問題文と同じ文を入力し、Enter キーを押してください。\n\n";

	for (int r = 0; r < typinggame.question_num; r++)
	{
		srand((unsigned)time(NULL));
		
		string thisquestion = typinggame.question[rand() % typinggame.setquestion_num]; // 問題数を増やせばランダムになる様子...
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
		typinggame.totaltime = typinggame.totaltime + (double)(end - start) / CLOCKS_PER_SEC;

		// 入力判定
		if (thisquestion == answer)
		{
			typinggame.score = typinggame.score + 1;
		}
	}

	return 0;
}

void scorefileedit(int a) // score_rank ファイルに結果を追加してソート、上書きする関数
{
	// score ランキングファイルを開く
	if (a == 0)
	{
		typinggame.gamemode = "Easy";
	}
	else if (a == 1)
	{
		typinggame.gamemode = "Normal";
	}
	else if (a == 2)
	{
		typinggame.gamemode = "Hard";
	}

	typinggame.Scorefilename = typinggame.gamemode + "ModeScoreFile.txt";

	ifstream ifs;
	ifs.open(typinggame.Scorefilename, std::ios::in);

	// score ファイルが開けなかったとき (開けないことがあるのか？)
	if (!ifs)
	{
		cout << "スコアランキングファイルをオープンできませんでした。\n\n";
	}

	// score ファイルが開けたとき
	else
	{
		cout << "スコアランキングファイルをオープンしました。\n\n";
	}

	string line;

	// score ランキングファイルの行数を数える
	typinggame.scoreranking_num = 0;

	while (!ifs.eof())
	{
		getline(ifs, line);
		typinggame.scoreranking_num = typinggame.scoreranking_num + 1;
	}

	// 最後に今回の結果を追加するので、配列要素数を 1 プラス
	typinggame.scoreranking_num++;

	// eof フラグをクリア
	ifs.clear();

	// ファイルポインタを先頭に移動
	ifs.ifstream::seekg(0, ios_base::beg);

	// 必要数の配列を作成
	typinggame.score_ranking = new int[typinggame.scoreranking_num];

	// テキストを１行ずつ読み取って配列に格納
	for (int j = 0; j < typinggame.scoreranking_num - 1; j++)
	{
		getline(ifs, line);
		typinggame.score_ranking[j] = stoi(line);
	}

	// 配列の最後に今回の結果を格納
	typinggame.score_ranking[typinggame.scoreranking_num - 1] = typinggame.score;

	// score ランキングファイルを閉じる
	ifs.close();

	// 結果をソート (score は降順 (値が大きいものから順に))
	for (int s = 0; s < typinggame.scoreranking_num - 1; s++)
	{
		for (int t = s + 1; t < typinggame.scoreranking_num; t++)
		{
			// 次の箱に入っている数字の方が大きいとき
			if (typinggame.score_ranking[s] < typinggame.score_ranking[t])
			{
				int tmp = typinggame.score_ranking[t];
				typinggame.score_ranking[t] = typinggame.score_ranking[s];
				typinggame.score_ranking[s] = tmp;
			}
		}
	}

	// score ランキングファイルへの書き込み
	ofstream ofs;
	ofs.open(typinggame.Scorefilename, std::ios::out);

	for (int a = 0; a < typinggame.scoreranking_num; a++)
	{
		ofs << typinggame.score_ranking[a];
		// 配列の最後でなければ (配列終了の 1 つ前までは) 改行を挿入
		if (a != (typinggame.scoreranking_num - 1))
		{
			ofs << '\n';
		}
	}

	// score ランキングファイルを閉じる
	ofs.close();
}

void timefileedit() // time ファイルに結果を追加してソート、上書きする関数
{
	// ファイル名の指定
	typinggame.Timefilename = typinggame.gamemode + "ModeTimeFile.txt";

	// time ランキングファイルを開く
	ifstream ifs;
	ifs.open(typinggame.Timefilename, std::ios::in);

	// time ファイルが開けなかったとき (開けないことがあるのか？)
	if (!ifs)
	{
		cout << "タイムランキングファイルをオープンできませんでした。\n\n";
	}

	// time ファイルが開けたとき
	else
	{
		cout << "タイムランキングファイルをオープンしました。\n\n";
	}

	string line;

	// time ランキングファイルの行数を数える
	typinggame.timeranking_num = 0;

	while (!ifs.eof())
	{
		getline(ifs, line);
		typinggame.timeranking_num = typinggame.timeranking_num + 1;
	}

	// 最後に今回の結果を追加するので、配列要素数を 1 プラス
	typinggame.timeranking_num++;

	// eof フラグをクリア
	ifs.clear();

	// ファイルポインタを先頭に移動
	ifs.ifstream::seekg(0, ios_base::beg);

	// 必要な要素数分の配列を作成
	typinggame.time_ranking = new double[typinggame.timeranking_num];

	// テキストを 1 行ずつ読み取って配列に格納
	while (!ifs.eof())
	{
		for (int j = 0; j < typinggame.timeranking_num - 1; j++)
		{
			getline(ifs, line);
			typinggame.time_ranking[j] = stod(line);
		}
	}

	// 配列の最後尾に今回の結果を格納
	typinggame.time_ranking[typinggame.timeranking_num - 1] = typinggame.totaltime;

	// time ランキングファイルを閉じる
	ifs.close();

	// 結果をソート (time は昇順で (値が小さいものから))
	for (int s = 0; s < typinggame.timeranking_num - 1; s++)
	{
		for (int t = s + 1; t < typinggame.timeranking_num; t++)
		{
			// 次の箱に入っている数字の方が小さいとき
			if (typinggame.time_ranking[s] > typinggame.time_ranking[t])
			{
				double tmp = typinggame.time_ranking[t];
				typinggame.time_ranking[t] = typinggame.time_ranking[s];
				typinggame.time_ranking[s] = tmp;
			}
		}
	}

	// time ランキングファイルへの書き込み
	ofstream ofs;
	ofs.open(typinggame.Timefilename, std::ios::out);

	for (int a = 0; a < typinggame.timeranking_num; a++)
	{
		ofs << typinggame.time_ranking[a];
		// 配列の最後でなければ改行を挿入
		if (a != (typinggame.timeranking_num - 1))
		{
			ofs << '\n';
		}
	}

	// time ランキングファイルを閉じる
	ofs.close();
}

void showresult()
{
	// 今回の結果を表示
	cout << "今回のあなたの成績は…\n";
	cout << "得点は " << typinggame.score << " / " << typinggame.question_num << " 点でした！" << '\n';
	cout << "時間は " << typinggame.totaltime << " 秒でした！" << '\n';
	cout << '\n';
}

int selectcontinue() // もう一度プレイするかユーザーに決めさせる関数
{
	cout << "もう一度遊びますか？\n";
	cout << "数字を選択し、入力してください。\n";
	cout << " YES ...  0" << '\n';
	cout << " NO  ...  1" << '\n';
	cout << '\n';

	string cont_num;

	bool is_not_set = true;

	while (is_not_set)
	{
		cout << "<< ";
		cin >> cont_num;
		cout << '\n';

		// continue するとき
		if (cont_num == "0")
		{
			is_not_set = false;
		}
		// continue しないとき
		else if (cont_num == "1")
		{
			// while の停止
			is_not_set = false;
		}
		// 指定した数字が選ばれなかったときは選択しなおし
		else
		{
			cout << "0 または 1 を入力してください。\n\n";
		}
	}

	return stoi(cont_num);
}

int main()
{
	// 複数回プレイできるように設定、continue しない場合は false に書き換える
	bool is_continued = true;

	struct game typinggame2;

	// 問題ファイルの読み込み
	// (複数回プレイする場合も読み込みは一度でいいので while ループ外で)
	fileread();

	while (is_continued)
	{
		memset(&typinggame, NULL, sizeof(typinggame));
		// 関数の呼び出し
		int a = modeselect();
		int b = numdecide(a);
		random();
		scorefileedit(a);
		timefileedit();
		showresult();

		int c = selectcontinue();
		// continue しない場合 while 文を抜ける
		if (c == 1)
		{
			is_continued = false;
		}
	}

	// メモリの開放必要？

	return 0;
}