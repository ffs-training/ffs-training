#include <iostream>
#include <fstream>
#include <string>
#include "WriteFile.h"
using namespace std;

template void WriteFile<int>(string fileName, int fileContentsNum, int* RankingSort);
template void WriteFile<double>(string fileName, int fileContentsNum, double* RankingSort);

template <typename X>
void WriteFile(string fileName, int fileContentsNum, X* RankingSort) // �����L���O�t�@�C���ւ̏�������
{
	ofstream ofs;
	ofs.open(fileName, std::ios::out);

	for (int a = 0; a < fileContentsNum; a++)
	{
		ofs << RankingSort[a];
		// �z��̍Ō�łȂ���� (�z��I���� 1 �O�܂ł�) ���s��}��
		if (a != (fileContentsNum - 1))
		{
			ofs << '\n';
		}
	}

	// �����L���O�t�@�C�������
	ofs.close();
}