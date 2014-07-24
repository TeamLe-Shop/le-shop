#ifndef USER_H
#define USER_H

#include <curses.h>
#include "util/vector.h"
#include "item.h"
#include "usd.h"

typedef struct
{
	Vector* inventory;
	usd_cent money;
} user_t;

/* Pretty much the same as item_t,
 * except there can be stacks of it.
 */
typedef struct
{
	item_t item;
	size_t count;
} invitem_t;

/* Create a new shop user */
user_t* user_new(usd_cent money);

/* Destroy the user variables */
void user_destroy(user_t* user);

/* Add an item to the player's inventory.
 * if one of the same type is already present,
 * it will be "stacked on" to the existing one.
 */
void user_add_item(user_t* user, item_t item);

#endif /* USER_H */
