#pragma once
class Note
{
public:
	Note();
	~Note();

	int ReturnFrequency(int);
	int ReturnDuration(int);

private:
	int frequency;
	int duration;
};

