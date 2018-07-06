#pragma once

enum SelectSound { A4 = 1, G5 = 2};

class Conductor
{
public:
	Conductor();
	~Conductor();

	void Play();

private:
	int tempo;
	int scale;
	int divisionNum;
};

