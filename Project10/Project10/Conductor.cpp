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

	// ���[�U�[�ɉ���I��������
	cout << "���t���������ɑΉ����鐔������͂��AEnter �L�[�������Ă��������B\n";
	cout << " �� ... 1" << '\n';
	cout << " �\ ... 2" << '\n';
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
			selectSound = ��;
		}
		else if (inputNum == "2")
		{
			isWrongNum = false;
			selectSound = �\;
		}
		else
		{
			cout << "������l�����͂���܂����B\n";
			cout << "1 �܂��� 2 ����͂��AEnter �L�[�������Ă��������B\n";
			cout << "\n";
		}
	}

	Sound sound;
	sound.MakeBeepSound(note.ReturnFrequency(selectSound), note.ReturnDuration(selectSound));

	system("PAUSE");
}