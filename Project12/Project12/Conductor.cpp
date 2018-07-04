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
	cout << "���t�������y���̔ԍ���I���E���͂��� Enter �L�[�������Ă��������B\n";
	cout << "\n";
	cout << " �ԍ� : �y����" << "\n";
	cout << "  1   : Symphony No.25 in G Minor, K.183 Violin1 <Normal>"<< "\n";
	cout << "  2   : Symphony No.25 in G Minor, K.183 Violin1 <Tempo Arrange>" << "\n";
	cout << "  3   : ���炫��ڂ��i�O���j" << "\n";
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
			cout << "��������������͂��Ă��������B\n\n";
		}
	}
}