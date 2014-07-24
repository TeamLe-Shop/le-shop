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
void render(void);

/* Called when a key is pressed. */
void input(int ch);

#endif /* SCREEN_H */
