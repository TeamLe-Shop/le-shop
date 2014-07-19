#include <ncurses.h>
#include <stdlib.h>
#include "screen.h"
#include "shop.h"

int main(void)
{
	shop_init();
	screen_init();

	while (last_key != 'q')
	{
		render();
		refresh();
		last_key = getch();
		input();
		erase();
	}

	shop_destroy();	
	endwin();
    return 0;
}
