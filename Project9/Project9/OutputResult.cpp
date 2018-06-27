#include <iostream>
#include <fstream>
#include <string>
#include "GameDataSet.h"
#include "OutputResult.h"
using namespace std;

OutputResult::OutputResult()
{
}


OutputResult::~OutputResult()
{
}

void OutputResult::EditFile(string gameMode, double totalTime, int score) // �e�t�@�C���̕ҏW���s���֐����Ăяo�����߂̊֐�
{
	EditTimeFile(gameMode, totalTime);
	EditScoreFile(gameMode, score);
}

void OutputResult::EditTimeFile(string gameMode, double totalTime) // time �t�@�C���Ɍ��ʂ�ǉ����ă\�[�g�A�㏑������֐�
{
	// �t�@�C�����̎w��
	string timeFileName = gameMode + "ModeTimeFile.txt";

	int timeRankingNum;
	string * timeFileRead;
	ReadFile(timeFileName, timeRankingNum, timeFileRead);

	// string ���� double �ɔz���ϊ�
	double* timeRanking;

	timeRankingNum++;
	timeRanking = new double[timeRankingNum];

	for (int i = 0; i < (timeRankingNum - 1); i++)
	{
		timeRanking[i] = (stod)(timeFileRead[i]);
	}

	// �z��̍Ō���ɍ���̌��ʂ��i�[
	timeRanking[timeRankingNum - 1] = totalTime;

	// ���ʂ��\�[�g (time �͏����� (�l�����������̂���))
	for (int s = 0; s < (timeRankingNum - 1); s++)
	{
		for (int t = s + 1; t < timeRankingNum; t++)
		{
			// ���̔��ɓ����Ă��鐔���̕����������Ƃ�
			if (timeRanking[s] > timeRanking[t])
			{
				double tmp = timeRanking[t];
				timeRanking[t] = timeRanking[s];
				timeRanking[s] = tmp;
			}
		}
	}

	WriteFile(timeFileName, timeRankingNum, timeRanking);

	delete[] timeFileRead;
	delete[] timeRanking;
}

void OutputResult::EditScoreFile(string gamemode, int score) // score �t�@�C���Ɍ��ʂ�ǉ����ă\�[�g�A�㏑������֐�
{
	string scoreFileName = gamemode + "ModeScoreFile.txt";

	int scoreRankingNum;
	string * scoreFileRead;

	ReadFile(scoreFileName, scoreRankingNum, scoreFileRead);

	// string ���� int �ɔz���ϊ�
	int* scoreRanking;
	scoreRankingNum++;
	scoreRanking = new int[scoreRankingNum];

	for (int i = 0; i < (scoreRankingNum - 1); i++)
	{
		scoreRanking[i] = (stoi)(scoreFileRead[i]);
	}

	// �z��̍Ō���ɍ���̌��ʂ��i�[
	scoreRanking[scoreRankingNum - 1] = score;

	// ���ʂ��\�[�g (score �͍~�� (�l���傫�����̂��珇��))
	for (int s = 0; s < (scoreRankingNum - 1); s++)
	{
		for (int t = s + 1; t < scoreRankingNum; t++)
		{
			//���̔��ɓ����Ă��鐔���̕����傫���Ƃ�
			if (scoreRanking[s] < scoreRanking[t])
			{
				int tmp = scoreRanking[t];
				scoreRanking[t] = scoreRanking[s];
				scoreRanking[s] = tmp;
			}
		}
	}

	WriteFile(scoreFileName, scoreRankingNum, scoreRanking);

	delete[] scoreFileRead;
	delete[] scoreRanking;
}

void OutputResult::ReadFile(string fileName, int& fileContentsNum, string*& RankingSort) // �t�@�C���ɋL�ڂ���Ă���f�[�^�� string �^�̔z��Ɋi�[����֐�
{
	// �t�@�C�����J��
	ifstream ifs;
	ifs.open(fileName, std::ios::in);

	// �t�@�C�����J���Ȃ������Ƃ�
	if (!ifs)
	{
		cout << "�t�@�C���u" << fileName << "�v���I�[�v���ł��܂���ł����B\n\n";
	}

	// �t�@�C�����J�����Ƃ�
	else
	{
		cout << "�t�@�C���u" << fileName << "�v���I�[�v�����܂����B\n\n";
	}

	string line;

	// �t�@�C���̍s���𐔂���
	fileContentsNum = 0;

	while (!ifs.eof())
	{
		getline(ifs, line);
		fileContentsNum = fileContentsNum + 1;
	}

	// eof �t���O���N���A
	ifs.clear();

	// �t�@�C���|�C���^��擪�Ɉړ�
	ifs.ifstream::seekg(0, ios_base::beg);

	// �K�v�ȗv�f�����̔z����쐬
	RankingSort = new string[fileContentsNum];

	// �e�L�X�g�� 1 �s���ǂݎ���Ĕz��Ɋi�[
	while (!ifs.eof())
	{
		for (int j = 0; j < fileContentsNum; j++)
		{
			getline(ifs, line);
			RankingSort[j] = line;
		}
	}

	// �t�@�C�������
	ifs.close();
}

template void OutputResult::WriteFile<int>(string, int, int*);
template void OutputResult::WriteFile<double>(string, int, double*);

template <typename X>
void OutputResult::WriteFile(string fileName, int fileContentsNum, X* RankingSort) // �����L���O�t�@�C���֏������ފ֐�
{
	ofstream ofs;
	ofs.open(fileName, std::ios::out);

	for (int a = 0; a < fileContentsNum; a++)
	{
		ofs << RankingSort[a];
		// �z��̍Ō�łȂ���� (�Ō�̔z��� 1 �O�܂ł�) ���s��}��
		if (a != (fileContentsNum - 1))
		{
			ofs << '\n';
		}
	}

	// �����L���O�t�@�C�������
	ofs.close();
}

void OutputResult::ShowResult(int score, int questionNum, double totalTime) // ���ʂ�\������֐�
{
	// ����̌��ʂ�\��
	cout << "����̂��Ȃ��̐��т́c\n";
	cout << "������ " << score << " / " << questionNum << " �ł����I" << '\n';
	cout << "���v���� " << totalTime << " �b�ł����I" << '\n';
	cout << '\n';
}