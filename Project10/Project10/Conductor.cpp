#include "Conductor.h"
#include "UserInput.h"
#include "Note.h"
#include <iostream>
#include <string>
#include <Windows.h>
#include <stdio.h>
using namespace std;

Conductor::Conductor()
{
}


Conductor::~Conductor()
{
}

void Conductor::Play()
{
	tempo = 100;
	UserInput userinput;
	int input = userinput.InputData();

	Note note;
	note.ReturnNoteInfo(input, scale, divisionNum); // “ü—Í‚µ‚½’l‚É‘Î‰ž‚·‚é scale ‚Æ divisionNum ‚ð•Ô‚·
	note.SetFrequency(scale);
	note.SetDuration(tempo, divisionNum);

	Beep(note.GetFrequency(), note.GetDuration());

	system("PAUSE");
}