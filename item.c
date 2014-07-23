#include "item.h"

void print_item(char* str, item_t item)
{
	char istr[3];

	int cents   = item.price % 100;
	long int dollars = item.price / 100;

	if (cents < 10) sprintf(istr, "0%i", cents);
	else sprintf(istr, "%i", cents);
	sprintf(str, "%-*s| $%li.%s", MAX_NAME_LEN, item.name, dollars, istr);
}

void print_money(char* str, long int price)
{
	int cents = price % 100;
	long int dollars = price / 100;
	
	if (cents < 10)
	{
		sprintf(str, "%li.0%i", dollars, cents);
	} else sprintf(str, "%li.%i", dollars, cents);
}
