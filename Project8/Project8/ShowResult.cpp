#include <iostream>
#include <string>
#include "ShowResult.h"
using namespace std;

void ShowResult(int score, int questionNum, double totalTime)
{
	// ����̌��ʂ�\��
	cout << "����̂��Ȃ��̐��т́c\n";
	cout << "������ " << score << " / " << questionNum << " �ł����I" << '\n';
	cout << "�o�ߎ��� " << totalTime << " �b�ł����I" << '\n';
	cout << '\n';
}