#include <iostream>
#include <string>
#include <time.h>
#include "AskQuestion.h"
using namespace std; 

void AskQuestion(int thisTimeQuestionNum, int fileQuestionNum, string*& question, double& totalTime, int& score) 
    // ���������_����"�o��"����֐� + �����Ɏ��Ԍv��
{
	string answer;

	cout << "��蕶�Ɠ���������͂��AEnter �L�[�������Ă��������B\n";
	cout << "�i 1 �� �ԈႦ�邲�ƂɃy�i���e�B�Ƃ��� ���Ԃ� 10 �b���Z����܂� �j\n\n";

	for (int r = 0; r < thisTimeQuestionNum; r++)
	{
		srand((unsigned)time(NULL));

		string thisquestion = question[rand() % fileQuestionNum];
		cout << "Q." << r + 1 << ' ' << thisquestion << '\n';

		// �^�C�}�[�X�^�[�g
		clock_t start = clock();

		// ���[�U�[����̓���
		cout << ">> ";
		cin >> answer;
		cout << '\n';

		// �^�C�}�[�X�g�b�v
		clock_t end = clock();

		// �ݐώ���
		totalTime = totalTime + (double)(end - start) / CLOCKS_PER_SEC;

		// ���͔���
		if (thisquestion == answer)
		{
			score = score + 1;
		}
	}

	// 1 ��ԈႦ�邲�Ƃ� 10 sec �̃y�i���e�B�Ƃ���
	totalTime = totalTime + ((double)(thisTimeQuestionNum - score) * 10.0);
}