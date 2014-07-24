#ifndef ITEM_H
#define ITEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util/stringutil.h"

#define MAX_NAME_LEN 13

typedef struct
{
    char name[MAX_NAME_LEN];
    long int price;
	char desc[86];
} item_t ;


/* Outputs information about an item in the
 * following format:
 *	 name | $price
 * into a string.
 */
void writestr_item(char*, item_t);

/*
 * Outputs _price_ in the format of:
 *   [price / 100].[price % 100]
 * Into a string.
 *
 * It will insert an extra '0' before
 * the second value if it is less than 10.
 */
void writestr_money(char*, long int price);

#endif /* ITEM_H */
