#include "item.h"

void print_item(char* str, item_t item)
{
	sprintf(str, "%-*s| " MONEY_FMT, MAX_NAME_LEN, item.name, MONEY_ARG(item.price));
}

void print_money(char* str, long int price)
{
	sprintf(str, MONEY_FMT, MONEY_ARG(price));
}
