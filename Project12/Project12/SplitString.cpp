#include "SplitString.h"
#include <string>
using namespace std;



SplitString::SplitString()
{
}


SplitString::~SplitString()
{
}

//  ‚à‚ç‚Á‚½•¶š—ñ‚ğ•¶š‚Æ”š‚ÉØ‚è—£‚µ‚Ä”š‚¾‚¯•Ô‚·
int SplitString::devideNum(string element, string targetstring)
{
	char* p;
	char* copy = _strdup(element.c_str());
	const char* delim = (targetstring.c_str());
	char* ctx;

	p = strtok_s(copy, delim, &ctx);
	splitNum = (atoi)(p);
	delete[] copy;
	return splitNum;
}