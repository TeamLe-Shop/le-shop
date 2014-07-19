#include "shop.h"

int item_count = 4;

item_t coat  = {"Coat", 10.00f};
item_t shoes = {"Shoes", 7.50f};
item_t bread = {"Bread", 9.25f};
item_t wine  = {"Wine", 16.79f};

void shop_init(void)
{
	item_list = malloc(sizeof(item_t) * item_count);
	item_list[0] = coat;
	item_list[1] = shoes;
	item_list[2] = bread;
	item_list[3] = wine;
}

void shop_destroy(void)
{
	free(item_list);
}
