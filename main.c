#include <curses.h>
#include <stdlib.h>
#include "screen.h"
#include "shop.h"
#include "user.h"

int main(void)
{
	/* Initialize all the variables needed
	 * needed for various things... */

	shop_t* shop = shop_new();
	user_init();
	screen_init();

	for (;;)
	{
		render(shop);
		refresh();
		int ch = getch();

		if (ch == 'q')
		{
			break;
		}

		input(shop, ch);
		erase();
	}

	/* ... Destroy them when we're done. */
	shop_destroy(shop);
	user_destroy();
	screen_destroy();
    return 0;
}
