#pragma once
class Note
{
public:
	Note();
	~Note();

	void ReturnNoteInfo(int, int&, int&);

	void SetFrequency(int);
	int SetDuration(int, int);

	int GetFrequency();
	int GetDuration();

private:
	int frequency;
	int duration;
};

