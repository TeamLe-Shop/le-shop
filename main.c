#include <ncurses.h>
#include <stdlib.h>
#include "screen.h"

int main(void)
{
	shop_init();
	screen_init();

	shop_destroy();	
	getch();
	endwin();
    return 0;
}
