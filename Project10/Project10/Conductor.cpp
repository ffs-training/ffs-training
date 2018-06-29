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

	// ���[�U�[�ɉ���I��������
	cout << "���t���������ɑΉ����鐔������͂��AEnter �L�[�������Ă��������B\n";
	cout << " �� (A4) �� 4 ������ ... 1" << '\n';
	cout << " �\ (G5) �� 8 ������ ... 2" << '\n';
	cout << "\n";

	ReturnNoteInfo(scale, divisionNum); // ���͂����l�ɑΉ����� scale �� divisionNum ��Ԃ�

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
			cout << "������l�����͂���܂����B\n";
			cout << "1 �܂��� 2 ����͂��AEnter �L�[�������Ă��������B\n";
			cout << "\n";
		}
	}
}