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
