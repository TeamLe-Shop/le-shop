#ifndef ITEM_H
#define ITEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stringutil.h"

#define MAX_NAME_LEN 11

typedef struct
{
    char name[MAX_NAME_LEN];
    float price;
	char desc[86];
} item_t ;


/* Outputs information about an item in the
 * following format:
 *	 name | price
 * into a string.
 */
void print_item(char*, item_t);

#endif /* ITEM_H */
