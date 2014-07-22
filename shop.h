#ifndef SHOP_H
#define SHOP_H

#include <stdlib.h>
#include "item.h"

extern int item_count;

/* Gets item at index i */
item_t shop_item_at(size_t index);

/* Initializes the items and the item list. */
void shop_init(void);

/* Destroys the items and the item list. */
void shop_destroy(void);

#endif /* SHOP_H */
