#ifndef USER_H
#define USER_H

#include <curses.h>
#include "util/vector.h"
#include "item.h"


extern Vector* user_inventory;
extern long int user_money;

/* Pretty much the same as item_t,
 * except there can be stacks of it.
 */
typedef struct
{
	item_t item;
	size_t count;
} invitem_t;

/* Initialize all the user variables. */
void user_init(void);

/* Destroy the user variables */
void user_destroy(void);

/* Add an item to the player's inventory.
 * if one of the same type is already present,
 * it will be "stacked on" to the existing one.
 */
void user_add_item(item_t);

#endif /* USER_H */
