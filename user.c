#include "user.h"

#include <string.h>

user_t* user_new(usd_cent money)
{
	user_t* user = malloc(sizeof(user_t));
	user->money = money;
	user->inventory = Vector_new();
	return user;
}

void user_destroy(user_t *user)
{
	Vector_free(user->inventory);
	free(user);
}

size_t user_total_items(user_t* user)
{
	size_t count = 0;
	for (int i = 0; i < Vector_len(user->inventory); i++)
	{
		invitem_t* citem = &Vector_at(user->inventory, invitem_t, i);
		count += citem->count;
	}
	return count;
}

void user_add_item(user_t* user, item_t item)
{
	for (int i = 0; i < Vector_len(user->inventory); i++)
	{
		invitem_t* citem = &Vector_at(user->inventory, invitem_t, i);
		if (strcmp(item.name, citem->item.name) == 0)
		{
			citem->count++;
			return;
		}
	}
	
	invitem_t new_item = {item, 1};
	Vector_add(user->inventory, invitem_t, new_item);
}
