#ifndef SCREEN_H
#define SCREEN_H

#include <ncurses.h>
#include <stdlib.h>
#include "shop.h"
#include "item.h"

/* The last key pressed. Each time a key is
 * pressed, input() is called. */
extern int last_key;

void screen_init(void);

/* Renders all the information on the screen. */
void render(void);

/* Called when a key is pressed. */
void input(void);

#endif /* SCREEN_H */
