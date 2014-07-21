#include "screen.h"

size_t selected_item;
size_t selected_option;
int last_key;

const int SHOP_LIST = 0,
		       MENU = 1;
int status = 0;
int statuses = 2;

long int money = 5000;

char* money_status;

void screen_init(void)
{
	initscr();
	keypad(stdscr, TRUE);

	start_color();
	
	init_pair(1, COLOR_BLACK, COLOR_GREEN);
	init_pair(2, COLOR_BLACK, COLOR_WHITE);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);

	money_status = malloc(sizeof(char) * 26);
	memset(money_status, 0, 26);
}

void screen_destroy(void)
{
	endwin();
	free(money_status);
}

void render(void)
{
	size_t y, x;
	getmaxyx(stdscr, y, x);

	char str[x + 1];
	size_t i;

	for (i = 0; i < item_count; i++)
	{
		print_item(str, item_list[i]);

		if (selected_item == i)
		{
			if (status == SHOP_LIST)
				attron(COLOR_PAIR(1));
			else
				attron(COLOR_PAIR(2));
		}
		
		mvprintw(i, 0, "%s\n", str);

		attroff(COLOR_PAIR(1));
		attroff(COLOR_PAIR(2));
	}

	if (status == MENU)
	{
		if (last_key == KEY_ENTER)
		{
			status = SHOP_LIST;
		}
		else
		{
			attron(COLOR_PAIR(1));
			mvprintw(selected_item, 25, " BUY? (y/n) ");
			attroff(COLOR_PAIR(1));
		}
	}


	memset(str, '-', x);
	mvprintw(5, 0, "%.*s", x, str);
	
	print_money(str, money);

	mvprintw(6, 0, "Balance: ");
	attron(COLOR_PAIR(3));
	printw("$%s", str);	
	attroff(COLOR_PAIR(3));

	mvprintw(6, 20, "(%s)", money_status);	

	mvprintw(7, 0, "Description:");
	attron(COLOR_PAIR(3));
	mvprintw(8, 2, "%s", item_list[selected_item].desc);
	attroff(COLOR_PAIR(3));

	memset(str, '-', x);
	mvprintw(12, 0, "%.*s", x, str);

	mvprintw(13, 0, "Press Q to quit");
}

void input(void)
{
	if (status == MENU)
	{
		if (last_key == 'y')
		{
			status = SHOP_LIST;
			if (money < item_list[selected_item].price)
			{
				sprintf(money_status, "Not enough money.");
			} else
			{
				money -= item_list[selected_item].price;
				char money_str[20];
				print_money(money_str, item_list[selected_item].price);
				sprintf(money_status, "-$%s", money_str);
			}
		} else status = SHOP_LIST;
	}
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
	else if (last_key == 'b')
	{
		if (status == SHOP_LIST) status = MENU;
		else if (status == MENU)	status = SHOP_LIST;
	}
}

