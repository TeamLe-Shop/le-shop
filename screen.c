#include "screen.h"

size_t selected_item;
size_t selected_option;
int last_key;

typedef enum
{
	SHOP_LIST,
	MENU
} Status;

Status status = SHOP_LIST;

char money_status[26];

void screen_init(void)
{
	initscr();
	keypad(stdscr, TRUE);

	start_color();
	
	init_pair(1, COLOR_BLACK, COLOR_GREEN);
	init_pair(2, COLOR_BLACK, COLOR_WHITE);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);

	memset(money_status, 0, 26);
}

void screen_destroy(void)
{
	endwin();
}

void render(void)
{
	size_t y, x;
	getmaxyx(stdscr, y, x);

	char str[x + 1];
	size_t i;

	mvprintw(0, 0, "SHOP ITEMS");
	mvprintw(0, 31, "INVENTORY");
	memset(str, '_', x);
	mvprintw(1, 0, str);

	/* -= Render the Shop List =- */
	for (i = 0; i < shop_item_count(); i++)
	{
		writestr_item(str, shop_item_at(i));

		if (selected_item == i)
		{
			if (status == SHOP_LIST)
				attron(COLOR_PAIR(1));
			else
				attron(COLOR_PAIR(2));
		}
		
		mvprintw(2 + i, 0, "%s\n", str);

		attroff(COLOR_PAIR(1));
		attroff(COLOR_PAIR(2));
	}

	if (status == MENU)
	{
		if (last_key == KEY_ENTER)
		{
			status = SHOP_LIST;
		}
	}
	/* -= End Rendering Shop List -= */


	/* -= Render The Inventory -= */
	for (i = 0; i < Vector_len(user_inventory); i++)
	{
		invitem_t citem = Vector_at(user_inventory, invitem_t, i);
		mvprintw(2 + i, 31, "%s  x%i", citem.item.name, citem.count);
	}
	/* -= End Rendering Inventory -= */

	memset(str, '-', x);
	mvprintw(7, 0, "%.*s", x, str);
	
	writestr_money(str, user_money);

	mvprintw(8, 0, "Balance: ");
	attron(COLOR_PAIR(3));
	printw("$%s", str);	
	attroff(COLOR_PAIR(3));

	mvprintw(8, 20, "(%s)", money_status);	

	mvprintw(9, 0, "Description:");
	attron(COLOR_PAIR(3));
	mvprintw(10, 2, "%s", shop_item_at(selected_item).desc);
	attroff(COLOR_PAIR(3));

	memset(str, '-', x);
	mvprintw(14, 0, "%.*s", x, str);

	mvprintw(15, 0, "B - buy, Q - quit");
}

void input(void)
{
	if (status == MENU)
	{
		
	}
	if (last_key == KEY_DOWN)
	{
		if (status == SHOP_LIST)
		{
			if (selected_item < shop_item_count() - 1)
				selected_item++;
		}
	}
	else if (last_key == KEY_UP)
	{
		if (status == SHOP_LIST)
		{
			if (selected_item > 0)
				selected_item--;
		}
	}
	else if (last_key == 'b')
	{
		status = SHOP_LIST;
		if (user_money < shop_item_at(selected_item).price)
		{
			sprintf(money_status, "Not enough money.");
		} else
		{
			user_money -= shop_item_at(selected_item).price;
			char money_str[20];
			writestr_money(money_str, shop_item_at(selected_item).price);
			user_add_item(shop_item_at(selected_item));
			sprintf(money_status, "-$%s", money_str);
		}
	}
}

