#include <iostream>
#include <string>
#include "SelectContinue.h"
using namespace std;

bool SelectContinue() // ������x�v���C���邩���[�U�[�Ɍ��߂�����֐�
{
	cout << "������x�V�т܂����H\n";
	cout << "������I�����A���͂��Ă��������B\n";
	cout << " YES ...  0" << '\n';
	cout << " NO  ...  1" << '\n';
	cout << '\n';

	string cont_num;

	bool setwrongnum = true;

	while (setwrongnum)
	{
		cout << "<< ";
		cin >> cont_num;
		cout << '\n';

		// continue ����Ƃ�
		if (cont_num == "0")
		{
			setwrongnum = false;
			return true;
		}
		// continue ���Ȃ��Ƃ�
		else if (cont_num == "1")
		{
			// while �̒�~
			setwrongnum = false;
			return false;
		}
		// �w�肵���������I�΂�Ȃ������Ƃ��͑I�����Ȃ���
		else
		{
			cout << "0 �܂��� 1 ����͂��Ă��������B\n\n";
		}
	}
	return false;
}