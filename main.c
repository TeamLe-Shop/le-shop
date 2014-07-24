#include <curses.h>
#include <stdlib.h>
#include "screen.h"
#include "shop.h"
#include "user.h"

int main(void)
{
	/* Initialize all the variables needed
	 * needed for various things... */

	shop_init();
	user_init();
	screen_init();

	while (last_key != 'q')
	{
		render();
		refresh();
		last_key = getch();
		input();
		erase();
	}

	/* ... Destroy them when we're done. */
	shop_destroy();	
	user_destroy();
	screen_destroy();
    return 0;
}
