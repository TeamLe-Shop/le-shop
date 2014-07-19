#include "screen.h"

int selected;
int last_key;

void screen_init(void)
{
	initscr();
	keypad(stdscr, TRUE);

	start_color();
	
	init_pair(1, COLOR_BLACK, COLOR_GREEN);
}

void render(void)
{
	int y, x;
	getmaxyx(stdscr, y, x);

	char* str = malloc(x);
	int i;

	for (i = 0; i < item_count; i++)
	{
		print_item(str, item_list[i]);

		if (selected == i)
			attron(COLOR_PAIR(1));
		
		mvprintw(i, 0, "%s\n", str);
		attroff(COLOR_PAIR(1));
	}

	memset(str, '-', x);
	mvprintw(5, 0, str);

	free(str);
}

void input(void)
{
	if (last_key == KEY_DOWN)
	{
		if (selected < item_count - 1)
			selected++;
	}
	else if (last_key == KEY_UP)
	{
		if (selected > 0)
			selected--;
	}
}
