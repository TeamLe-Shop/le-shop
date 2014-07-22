#include "shop.h"
#include "util/vector.h"

Vector* items;

item_t coat  = {"Coat", 1000, "A brown coat, used by Prince Plebscale."};
item_t shoes = {"Shoes", 750, "Black elegant shoes, fit for any gentleman."};
item_t bread = {"Bread", 925, "The finest bread baked in France by Sir Deux.\n"
								"  He's famous for having yellow hair."};
item_t wine  = {"Wine", 1679, "Crystal red wine, fit for any occasion."};

void shop_init(void)
{
	items = Vector_new();
	Vector_add(items, item_t, coat);
	Vector_add(items, item_t, shoes);
	Vector_add(items, item_t, bread);
	Vector_add(items, item_t, wine);
}

void shop_destroy(void)
{
	Vector_free(items);
}

item_t shop_item_at(size_t index)
{
	return Vector_at(items, item_t, index);
}

size_t shop_item_count()
{
	return Vector_len(items);
}
