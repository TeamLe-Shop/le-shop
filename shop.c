#include "shop.h"

int item_count = 4;

item_t coat  = {"Coat", 1000, "A brown coat, used by Prince Plebscale."};
item_t shoes = {"Shoes", 750, "Black elegant shoes, fit for any gentleman."};
item_t bread = {"Bread", 925, "The finest bread baked in France by Sir Deux.\n"
								"  He's famous for having yellow hair."};
item_t wine  = {"Wine", 1679, "Crystal red wine, fit for any occasion."};

item_t* item_list;

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


item_t shop_item_at(size_t index)
{
	return item_list[index];
}


size_t shop_item_count()
{
	return item_count;
}
