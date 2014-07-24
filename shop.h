#ifndef SHOP_H
#define SHOP_H

#include <stdlib.h>
#include "item.h"
#include "util/vector.h"

typedef struct
{
	Vector* items;
}shop_t;

/* Gets item at index i */
item_t shop_item_at(shop_t* shop, size_t index);

/* Returns number of items the shop has */
size_t shop_item_count(shop_t* shop);

/* Initializes the items and the item list. */
shop_t *shop_new(void);

/* Destroys the items and the item list. */
void shop_destroy(shop_t* shop);

#endif /* SHOP_H */
