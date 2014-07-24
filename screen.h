#ifndef SCREEN_H
#define SCREEN_H

#include <curses.h>
#include <stdlib.h>
#include "shop.h"
#include "item.h"
#include "user.h"

/* Initializes the window for curses. */
void screen_init(void);

/* Destroys the curses window and frees
 * some variables.
 */
void screen_destroy(void);

/* Renders all the information on the screen. */
void render(shop_t *shop, user_t *user);

/* Called when a key is pressed. */
void input(shop_t *shop, user_t *user, int ch);

#endif /* SCREEN_H */
