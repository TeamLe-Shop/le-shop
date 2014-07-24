#ifndef ITEM_H
#define ITEM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util/stringutil.h"

#define ITEM_MAX_NAME_LEN 13

typedef struct
{
	char name[ITEM_MAX_NAME_LEN];
	long int price;
	char desc[86];
} item_t ;

#endif /* ITEM_H */
