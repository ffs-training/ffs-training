#include "Conductor.h"
#include "SetScore.h"
#include "PlayMusic.h"
#include "PlayBeep.h"
#include <iostream>

string Conductor::fileName;

Conductor::Conductor()
{
}


Conductor::~Conductor()
{
}


void Conductor::SetAndPlay()
{
	selectScore();
	SetScore setScore;
	vector<string> score = setScore.SetSelectedScore(fileName);
	PlayBeep playBeep;
	playBeep.Play(&score);

	system("PAUSE");
}

void Conductor::selectScore()
{
	cout << "演奏したい楽譜の番号を選択・入力して Enter キーを押してください。\n";
	cout << "\n";
	cout << " 番号 : 楽譜名" << "\n";
	cout << "  1   : Symphony No.25 in G Minor, K.183 Violin1 <Normal>"<< "\n";
	cout << "  2   : Symphony No.25 in G Minor, K.183 Violin1 <Tempo Arrange>" << "\n";
	cout << "  3   : きらきらぼし（前半）" << "\n";
	cout << "\n";

	bool isWrongNum = true;
	while (isWrongNum)
	{
		string num;
		cout << ">> ";
		cin >> num;
		cout << "\n\n";

		if (num == "1")
		{
			isWrongNum = false;
			fileName = "Violin1.txt";
		}
		else if (num == "2")
		{
			isWrongNum = false;
			fileName = "Violin1TempoArrange.txt";
		}
		else if (num == "3")
		{
			isWrongNum = false;
			fileName = "TwinkleTwinkleLittleStar.txt";
		}
		else
		{
			cout << "正しい数字を入力してください。\n\n";
		}
	}
}