#ifndef ITEM_H
#define ITEM_H

#include "usd.h"

#define ITEM_MAX_NAME_LEN 13

typedef struct
{
	char name[ITEM_MAX_NAME_LEN];
	usd_cent price;
	char desc[86];
} item_t ;

#endif /* ITEM_H */
