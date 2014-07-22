#ifndef SHOP_H
#define SHOP_H

#include <stdlib.h>
#include "item.h"

extern int item_count;

item_t* item_list;

/* Initializes the items and the item list. */
void shop_init(void);

/* Destroys the items and the item list. */
void shop_destroy(void);

#endif /* SHOP_H */
