#ifndef SCREEN_H
#define SCREEN_H

#include <curses.h>
#include <stdlib.h>
#include "shop.h"
#include "item.h"
#include "user.h"

/* The last key pressed. Each time a key is
 * pressed, input() is called. */
extern int last_key;

/* Initializes the window for curses. */
void screen_init(void);

/* Destroys the curses window and frees
 * some variables.
 */
void screen_destroy(void);

/* Renders all the information on the screen. */
void render(void);

/* Called when a key is pressed. */
void input(void);

#endif /* SCREEN_H */
