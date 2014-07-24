#include <stdlib.h>
#include "screen.h"
#include "shop.h"
#include "user.h"

int main(void)
{
	shop_t* shop = shop_new();
	user_t* user = user_new(5000);

	screen_exec(shop, user);

	shop_destroy(shop);
	user_destroy(user);
    return 0;
}
