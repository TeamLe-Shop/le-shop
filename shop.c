#include "shop.h"

shop_t* shop_new(void)
{
	shop_t* shop = malloc(sizeof(shop_t));
	item_t coat  = {"Coat", 1000, "A brown coat, used by Prince Plebscale."};
	item_t shoes = {"Shoes", 750, "Black elegant shoes, fit for any gentleman."};
	item_t bread = {"Bread", 925, "The finest bread baked in France by Sir Deux.\n"
									"  He's famous for having yellow hair."};
	item_t wine  = {"Wine", 1679, "Crystal red wine, fit for any occasion."};
	shop->items = Vector_new();
	Vector_add(shop->items, item_t, coat);
	Vector_add(shop->items, item_t, shoes);
	Vector_add(shop->items, item_t, bread);
	Vector_add(shop->items, item_t, wine);
	return shop;
}

void shop_destroy(shop_t* shop)
{
	Vector_free(shop->items);
	free(shop);
}

item_t shop_item_at(shop_t *shop, size_t index)
{
	return Vector_at(shop->items, item_t, index);
}

size_t shop_item_count(shop_t *shop)
{
	return Vector_len(shop->items);
}
