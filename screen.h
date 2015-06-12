#ifndef SCREEN_H
#define SCREEN_H

#include "shop.h"
#include "user.h"

/* Execute the draw-input loop */
void screen_exec(shop_t* shop, user_t* user);

#define SCREEN_MENU_HEIGHT 5
#define SCREEN_MENU_CENTER 3

#endif /* SCREEN_H */
