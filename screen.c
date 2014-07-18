#include "screen.h"

void screen_init(void)
{
	initscr();
	keypad(stdscr, TRUE);

	start_color();
	
	init_pair(1, COLOR_BLACK, COLOR_GREEN);
}

void render(void)
{
	char* str = malloc(30);
	int i;
	for (i = 0; i < ITEM_COUNT; i++)
	{
		printi(str, item_list[i]);

		if (selected == i)
			attron(COLOR_PAIR(1));
		
		mvprintw(i, 0, "%s\n", str);
		attroff(COLOR_PAIR(1));
	}

	free(str);
}
