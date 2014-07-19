#include "stringutil.h"

int indexof(char* string, int ch)
{
	char* ptr = strchr(string, ch);
	if (ptr)
	{
		int ind = ptr - string;
		return ind;
	} else return -1;
}

void decimal_places(char* floatstr, float f, int p)
{
	sprintf(floatstr, "%f", f);

	int chars;
	chars = indexof(floatstr, '.') + 4;
	snprintf(floatstr, chars, "%f", f);
}
