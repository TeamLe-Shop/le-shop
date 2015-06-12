#ifndef ITEM_H
#define ITEM_H

#include "usd.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ITEM_MAX_NAME_LEN 13

typedef struct
{
	char name[ITEM_MAX_NAME_LEN];
	usd_cent price;
	char desc[86];
} item_t ;


/* Outputs information about an item in the
 * following format:
 *	 name | $price
 * into a string.
 */
void print_item(char*, item_t);

/*
 * Outputs _price_ in the format of:
 *   [price / 100].[price % 100]
 * Into a string.
 *
 * It will insert an extra '0' before
 * the second value if it is less than 10.
 */
void print_money(char*, long int price);

/* Bear with me through this preprocessor macro stuff
 */

#define getDigits(num) (1                                   /* 1 for sign */ \
                      + sizeof (num) * CHAR_BIT / 3         /* ... for digits */ \
                      + (sizeof (num) * CHAR_BIT % 3 > 0)   /* ... for remaining digit */ \
                      + 1)                                  /* 1 for NUL terminator */

#define MONEY_FMT    "$%*li.%2li"
#define MONEY_ARG(p) getDigits((p) / 100), (p) / 100, (p) % 100

/* Now you can use MONEY_FMT and MONEY_ARG in any *printf function
 */

#endif /* ITEM_H */
