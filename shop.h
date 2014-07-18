#ifndef SHOP_H
#define SHOP_H

#include <stdlib.h>
#include "item.h"

const int ITEM_COUNT = 2;
item_t coat;
item_t shoes;
item_t* item_list;

void shop_init(void);

#endif /* SHOP_H */
