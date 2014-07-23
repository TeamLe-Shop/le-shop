#include "user.h"

long int user_money;
Vector* user_inventory;

void user_init(void)
{
	user_money = 5000;
	user_inventory = Vector_new();
}

void user_destroy(void)
{
	Vector_free(user_inventory);
}

void user_add_item(item_t item)
{

	mvprintw(25, 7, "FRAGGOT");
	int i;
	invitem_t new_item = {item, 1};
	if (Vector_len(user_inventory) == 0)
	{
		Vector_add(user_inventory, invitem_t, new_item);
		return;
	}
	for (i = 0; i < Vector_len(user_inventory); i++)
	{
		mvprintw(20, 6, "FRAGGOT");
		invitem_t citem = Vector_at(user_inventory, invitem_t, i);
		if (item.name == citem.item.name)
		{
			citem.count++;
			return;
		}
	}
	
	Vector_add(user_inventory, invitem_t, new_item);
}
