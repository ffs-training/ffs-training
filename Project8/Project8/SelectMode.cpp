#include <iostream>
#include <string>
#include "SelectMode.h"
using namespace std;

void SelectMode(int& thisTimeQuestionNum, string& gameMode) // �Q�[���̓�Փx�����߂�����֐�
{
	// ��Փx�̏o��
	cout << '\n';
	cout << "�V�т����Q�[���̓�Փx�ɍ�����������͂��AEnter �L�[�������Ă��������B\n";
	cout << " EASY   ...  0" << '\n';
	cout << " NORMAL ...  1" << '\n';
	cout << " HARD   ...  2" << '\n';
	cout << '\n';

	bool isWrongInput = true;
	string imode;

	while (isWrongInput)
	{
		cout << ">> ";
		cin >> imode;
		cout << '\n';

		// �w�肵���������I�΂ꂽ�Ƃ�
		if (imode == "0")
		{
			isWrongInput = false;
			gameMode = "Easy";
		}
		else if (imode == "1")
		{
			isWrongInput = false;
			gameMode = "Normal";
		}
		else if (imode == "2")
		{
			isWrongInput = false;
			gameMode = "Hard";
		}

		// �w�肵���������I�΂�Ȃ������Ƃ�
		else
		{
			cout << "0, 1, 2 �̂����ꂩ�̐�������͂��Ă��������B\n\n";
		}
	}

	thisTimeQuestionNum = 5 * ((stoi)(imode) + 1); // 0 -> 5 ��A1 -> 10 ��A2 -> 15 ��A�ɐݒ�
}