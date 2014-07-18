#include "shop.h"

void shop_init(void)
{
	coat  = {"Coat", 10.00f};
	shoes = {"Shoes", 7.00f};

	item_list = malloc(sizeof(item_t) * ITEM_COUNT);
	item_list[0] = coat;
	item_list[1] = shoes;
}

void shop_destroy(void)
{
	free(item_list);
}
