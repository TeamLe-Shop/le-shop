#ifndef SCREEN_H
#define SCREEN_H

#include <ncurses.h>
#include <stdlib.h>
#include "shop.h"
#include "item.h"

/* The last key pressed. Each time a key is
 * pressed, render() is called. */
int LAST_KEY;

void screen_init(void);

/* Renders all the information on the screen. */
void render(void);

#endif /* SCREEN_H */
