#include "Conductor.h"
#include "CalcTimeLength.h"
#include "Note.h"
#include "Sound.h"
#include <iostream>
#include <string>
using namespace std;

Conductor::Conductor()
{
}


Conductor::~Conductor()
{
}

void Conductor::Play()
{
	tempo = 100;
	CalcTimeLength calcTimeLength;

	// ユーザーに音を選択させる
	cout << "演奏したい音に対応する数字を入力し、Enter キーを押してください。\n";
	cout << " ラ (A4) の 4 分音符 ... 1" << '\n';
	cout << " ソ (G5) の 8 分音符 ... 2" << '\n';
	cout << "\n";

	ReturnNoteInfo(scale, divisionNum); // 入力した値に対応する scale と divisionNum を返す

	Sound sound;
	Note note;
	sound.MakeBeepSound(note.SetFrequency(scale), note.SetDuration(tempo, divisionNum));

	system("PAUSE");
}

void Conductor::ReturnNoteInfo(int& scale, int& divisionNum)
{
	bool isWrongNum = true;
	while (isWrongNum)
	{
		cout << ">> ";
		string inputNum;
		cin >> inputNum;
		cout << "\n";

		if (inputNum == "1")
		{
			isWrongNum = false;
			scale = A4;
			divisionNum = 4;
		}
		else if (inputNum == "2")
		{
			isWrongNum = false;
			scale = G5;
			divisionNum = 8;
		}
		else
		{
			cout << "誤った値が入力されました。\n";
			cout << "1 または 2 を入力し、Enter キーを押してください。\n";
			cout << "\n";
		}
	}
}