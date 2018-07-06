#pragma once
#include <vector>
#include <string>
using namespace std;
class PlayMusic
{
public:
	PlayMusic();
	~PlayMusic();
	virtual void Play(vector<string>*);
};

