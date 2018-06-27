#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include "GameDataSet.h"
using namespace std;

int GameDataSet::questionDataNum = 0;
string* GameDataSet::questionData;

GameDataSet::GameDataSet()
{
}


GameDataSet::~GameDataSet()
{
	delete[] questionData;
}

void GameDataSet::ReadQuestionFile() // �t�@�C�����J���āA����z��Ɋi�[����֐�
{
	// ���t�@�C�����J��
	ifstream fin;
	string fileName = "quention.txt";
	fin.open(fileName, std::ios::in);

	// �t�@�C�����J���Ȃ������Ƃ�
	if (!fin)
	{
		cout << "���t�@�C�����I�[�v���ł��܂���ł����B\n";
	}
	// �t�@�C�����J�����Ƃ�
	else
	{
		cout << "���t�@�C�����I�[�v�����܂����B\n";
	}

	string line;

	// ���t�@�C���̍s���𐔂���
	while (!fin.eof())
	{
		getline(fin, line);
		questionDataNum = questionDataNum + 1;
	}

	// eof �t���O���N���A
	fin.clear();

	// �t�@�C���|�C���^��擪�Ɉړ�
	fin.ifstream::seekg(0, ios_base::beg);

	// �s���ɍ��킹�Ĕz����쐬
	questionData = new string[questionDataNum];

	// �e�L�X�g���P�s���ǂݎ���Ĕz��Ɋi�[
	for (int j = 0; j < questionDataNum; j++)
	{
		getline(fin, line);
		questionData[j] = line;
	}

	// ���t�@�C�������
	fin.close();
}

int GameDataSet::ReturnQuestionDataNum()
{
	if (questionData != NULL)
	{
		return questionDataNum;
	}
	else
	{
		cout << "���t�@�C�����ǂݍ��߂Ă��܂���B\n";
	}
}

string GameDataSet::ReturnQuestionData(int n)
{
	if (questionData != NULL)
	{
		return questionData[n];
	}
	else
	{
		cout << "���t�@�C�����ǂݍ��߂Ă��܂���B\n";
	}
}
