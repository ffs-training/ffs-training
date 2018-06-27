#pragma once
#include <string>
using namespace std;

class OutputResult
{
public:
	OutputResult();
	~OutputResult();

	void EditFile(string, double, int);
	void ShowResult(int, int, double);

private:
	void EditTimeFile(string, double);
	void EditScoreFile(string, int);
	void ReadFile(string, int&, string*&);
	
	template <typename X>
	void WriteFile(string, int, X*);
};

