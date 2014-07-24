#include "usd.h"
#include <stdio.h>

void usd_write_into_str(char* str, usd_cent cents)
{
	int remainder = cents % 100;
	long int dollars = cents / 100;

	/* '1000' should look like '10.00'. */
	if (remainder < 10)
		sprintf(str, "%li.0%i", dollars, remainder);
	else
		sprintf(str, "%li.%i", dollars, remainder);
}
