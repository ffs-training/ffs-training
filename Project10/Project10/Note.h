#pragma once
class Note
{
public:
	Note();
	~Note();

	int SetFrequency(int);
	int SetDuration(int, int);

private:
	int frequency;
	int duration;
};

