#ifndef SHOP_H
#define SHOP_H

#include <stdlib.h>
#include "item.h"

/* Gets item at index i */
item_t shop_item_at(size_t index);

/* Returns number of items the shop has */
size_t shop_item_count();

/* Initializes the items and the item list. */
void shop_init(void);

/* Destroys the items and the item list. */
void shop_destroy(void);

#endif /* SHOP_H */
