#ifndef SHOP_H
#define SHOP_H

#include <stdlib.h>
#include "item.h"

extern int item_count;

/* ITEM LIST */
extern item_t cat;
extern item_t shoes;
extern item_t bread;
extern item_t wine;

item_t* item_list;

/* Initializes the items and the item list. */
void shop_init(void);

#endif /* SHOP_H */
