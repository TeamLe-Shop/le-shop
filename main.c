#include <stdlib.h>
#include <curses.h>
#include "screen.h"
#include "shop.h"
#include "user.h"

int main(void)
{
	/* Initialize all the variables needed
	 * needed for various things... */

	shop_t* shop = shop_new();
	user_t* user = user_new(5000);
	screen_init();

	for (;;)
	{
		render(shop, user);
		refresh();
		int ch = getch();

		if (ch == 'q')
		{
			break;
		}

		input(shop, user, ch);
		erase();
	}

	/* ... Destroy them when we're done. */
	shop_destroy(shop);
	user_destroy(user);
	screen_destroy();
    return 0;
}
