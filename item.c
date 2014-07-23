#include "item.h"

void print_item(char* str, item_t item)
{
	char spaces[11];
	memset(spaces, 0, 11);
	memset(spaces, ' ',	MAX_NAME_LEN - strlen(item.name));

	char istr[3];

	int cents   = item.price % 100;
	long int dollars = item.price / 100;

	if (cents < 10) sprintf(istr, "0%i", cents);
	else sprintf(istr, "%i", cents);
	sprintf(str, "%s%s| $%li.%s", item.name, spaces, dollars, istr);
}

void print_money(char* str, long int price)
{
	int cents = price % 100;
	long int dollars = price / 100;
	
	if (cents < 10)
	{
		sprintf(str, "%li.0%i", dollars, cents);
	}
	else
	{
		sprintf(str, "%li.%i", dollars, cents);
	}
}
