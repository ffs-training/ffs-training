#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include "ReadQuestionFile.h"
using namespace std;

void ReadQuestionFile(int& fileQuestionNum, string*& question) // �t�@�C�����J���āA����z��Ɋi�[����֐�
{
	// ���t�@�C�����J��
	ifstream fin;
	string fileName = "quention.txt";
	fin.open(fileName, std::ios::in);

	// �t�@�C�����J���Ȃ������Ƃ�
	if (!fin)
	{
		cout << "���t�@�C�����I�[�v���ł��܂���ł����B\n\n";
	}

	// �t�@�C�����J�����Ƃ�
	else
	{
		cout << "���t�@�C�����I�[�v�����܂����B\n\n";
	}

	string line;

	// ���t�@�C���̍s���𐔂���
	while (!fin.eof())
	{
		getline(fin, line);
		fileQuestionNum = fileQuestionNum + 1;
	}

	// eof �t���O���N���A
	fin.clear();

	// �t�@�C���|�C���^��擪�Ɉړ�
	fin.ifstream::seekg(0, ios_base::beg);

	// �s���ɍ��킹�Ĕz����쐬
	question = new string[fileQuestionNum];

	// �e�L�X�g���P�s���ǂݎ���Ĕz��Ɋi�[
	for (int j = 0; j < fileQuestionNum; j++)
	{
		getline(fin, line);
		question[j] = line;
	}

	// ���t�@�C�������
	fin.close();
}