#pragma once
#include "PlayMusic.h"
using namespace std;
class Conductor
{
public:
	Conductor();
	~Conductor();
	void SetAndPlay();
private:
	void CreatePlayer(int, PlayMusic*&);
};

