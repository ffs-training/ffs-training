#include <iostream>
#include <fstream>
#include <string>
#include "ReadFile.h"
using namespace std;

template void ReadFile<int>(string, int, int&, int*&);
template void ReadFile<double>(string, double, int&, double*&);

template <typename T>
void ReadFile(string fileName, T result, int& fileContentsNum, T*& RankingSort)
// �t�@�C���ɋL�ڂ���Ă���f�[�^��z��Ɋi�[���A�z��̍Ō�ɍ���̌��ʂ�ǉ�����֐�
{
	// �t�@�C�����J��
	ifstream ifs;
	ifs.open(fileName, std::ios::in);
	 
	// �t�@�C�����J���Ȃ������Ƃ� (�J���Ȃ����Ƃ�����̂��H)
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

	// �Ō�ɍ���̌��ʂ�ǉ�����̂ŁA�z��v�f���� 1 �v���X
	fileContentsNum++;

	// eof �t���O���N���A
	ifs.clear();

	// �t�@�C���|�C���^��擪�Ɉړ�
	ifs.ifstream::seekg(0, ios_base::beg);

	// �K�v�ȗv�f�����̔z����쐬
	RankingSort = new T[fileContentsNum];

	// �e�L�X�g�� 1 �s���ǂݎ���Ĕz��Ɋi�[
	while (!ifs.eof())
	{
		for (int j = 0; j < fileContentsNum - 1; j++)
		{
			getline(ifs, line);
			RankingSort[j] = stod(line);
		}
	}

	// �z��̍Ō���ɍ���̌��ʂ��i�[
	RankingSort[fileContentsNum - 1] = result;

	// �t�@�C�������
	ifs.close();
}