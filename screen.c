#include "screen.h"

size_t selected_item;
size_t selected_option;
int last_key;

const int SHOP_LIST = 0,
		       MENU = 1;
int status = 0;
int statuses = 2;

float money = 50.00f;

void screen_init(void)
{
	initscr();
	keypad(stdscr, TRUE);

	start_color();
	
	init_pair(1, COLOR_BLACK, COLOR_GREEN);
	init_pair(2, COLOR_BLACK, COLOR_WHITE);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
}

void render(void)
{
	size_t y, x;
	getmaxyx(stdscr, y, x);

	char* str = malloc(x + 1);
	size_t i;

	for (i = 0; i < item_count; i++)
	{
		print_item(str, item_list[i]);

		if (selected_item == i)
		{
			if (status == SHOP_LIST)
			{
				attron(COLOR_PAIR(1));
			}
			else attron(COLOR_PAIR(2));
		}
		
		mvprintw(i, 0, "%s\n", str);

		attroff(COLOR_PAIR(1));
		attroff(COLOR_PAIR(2));
	}


	memset(str, '-', x);
	mvprintw(5, 0, "%*s", x, str);
	
	decimal_places(str, money, 2);
	mvprintw(6, 0, "Balance: ");
	attron(COLOR_PAIR(3));
	printw("$%s", str);	
	attroff(COLOR_PAIR(3));

	mvprintw(7, 0, "Description:");
	attron(COLOR_PAIR(3));
	mvprintw(8, 2, "%s", item_list[selected_item].desc);
	attroff(COLOR_PAIR(3));

	memset(str, '-', x);
	mvprintw(12, 0, "%*s", x, str);

	mvprintw(13, 0, "Press Q to quit");

	free(str);
}

void input(void)
{
	if (last_key == KEY_DOWN)
	{
		if (status == SHOP_LIST)
		{
			if (selected_item < item_count - 1)
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
	else if (last_key == 'p')
	{
		status++;
		if (status == statuses) status = 0;
	}
}
