#pragma once
#include <string>
using namespace std;
class Conductor
{
public:
	Conductor();
	~Conductor();
	void SetAndPlay();

private:
	void selectScore();
	static string fileName;
};

