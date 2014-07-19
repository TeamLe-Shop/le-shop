#include "item.h"

void print_item(char* str, item_t item)
{
	char* floatstr = malloc(sizeof(char) * 20);
	sprintf(floatstr, "%f", item.price);

	int chars;
	chars = indexof(floatstr, '.') + 4;
	snprintf(floatstr, chars, "%f", item.price);

	char* spaces = malloc(11);
	memset(spaces, 0, 11);
	memset(spaces, ' ',	MAX_NAME_LEN - strlen(item.name));

	sprintf(str, "%s%s| $%s", item.name, spaces, floatstr);
	free(floatstr);
	free(spaces);
}
