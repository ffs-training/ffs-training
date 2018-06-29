#include "Conductor.h"
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
	Note note;
	SelectSound selectSound;

	// ユーザーに音を選択させる
	cout << "演奏したい音に対応する数字を入力し、Enter キーを押してください。\n";
	cout << " ラ ... 1" << '\n';
	cout << " ソ ... 2" << '\n';
	cout << "\n";

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
			selectSound = ラ;
		}
		else if (inputNum == "2")
		{
			isWrongNum = false;
			selectSound = ソ;
		}
		else
		{
			cout << "誤った値が入力されました。\n";
			cout << "1 または 2 を入力し、Enter キーを押してください。\n";
			cout << "\n";
		}
	}

	Sound sound;
	sound.MakeBeepSound(note.ReturnFrequency(selectSound), note.ReturnDuration(selectSound));

	system("PAUSE");
}