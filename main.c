#include <ncurses.h>
#include <stdlib.h>
#include "item.h"

const int ITEM_COUNT = 2;

int main()
{
	initscr();
	keypad(stdscr, TRUE);

    item_t coat  = {"Coat", 10.00f};
	item_t shoes = {"Shoes", 7.00f};
	item_t* item_list = malloc(sizeof(item_t) * ITEM_COUNT);
	item_list[0] = coat;
	item_list[1] = shoes;


	char* str = malloc(30);
	int i;
	for (i = 0; i < ITEM_COUNT; i++)
	{
		printi(str, item_list[i]);
		printw("%s\n", str);
	}
	free(str);
	free(item_list);
	
	getch();
	endwin();
    return 0;
}
