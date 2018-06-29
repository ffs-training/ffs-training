#pragma once
#include <Windows.h>
#include <stdio.h>
class Sound
{
public:
	Sound();
	~Sound();

	void MakeBeepSound(int F, int D);
};
