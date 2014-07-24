#include "screen.h"
#include "usd.h"

#include <curses.h>
#include <string.h>

/* What the user is currently focused on. */
typedef enum
{
	SHOP_LIST,
	NAVIGATION
} Mode;

typedef struct
{
	/* The selected options for
	 * menus and such. */
	size_t selected_item;
	/* A string that gets updated after buying
	 * something. */
	char money_status[26];
	/* What the user is currently focused on. */
	Mode mode;
} ui_state_t;

static ui_state_t new_ui_state()
{
	ui_state_t ui_state;
	ui_state.mode = SHOP_LIST;
	memset(ui_state.money_status, 0, sizeof(ui_state.money_status));
	ui_state.selected_item = 0;
	return ui_state;
}

/* Destroys the curses window and frees
 * some variables.
 */
static void destroy(void)
{
	endwin();
}

/* Initializes the window for curses. */
static void init(ui_state_t* ui_state)
{
	initscr();
	keypad(stdscr, TRUE);

	/* Check if the user's terminal supports color. */
	if (has_colors() == FALSE)
	{
		/* Get rid of the window, print a message
		 * and then exit eith error code (1). */
		destroy();
		printf("Whoopsies. Your terminal doesn't support color.\n");
		exit(1);
	}

	/* .. otherwise start color and initialize
	 * our color pairs. */
	start_color();
	
	init_pair(1, COLOR_BLACK, COLOR_GREEN);
	init_pair(2, COLOR_BLACK, COLOR_WHITE);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);

	/* Zero out money_status. */
	memset(ui_state->money_status, 0, 26);
}

/* Outputs information about an item in the
 * following format:
 *	 name | $price
 * into a string.
 */
static void writestr_item(char* str, item_t item)
{
	char istr[3];

	int cents = item.price % 100;
	long int dollars = item.price / 100;

	if (cents < 10) sprintf(istr, "0%i", cents);
	else sprintf(istr, "%i", cents);
	sprintf(str, "%-*s| $%li.%s", ITEM_MAX_NAME_LEN, item.name, dollars, istr);
}

/* Renders all the information on the screen. */
static void render(shop_t* shop, user_t* user, ui_state_t* ui_state)
{
	/* The height (y) and width (x) of the window. */
	size_t y, x;
	getmaxyx(stdscr, y, x);

	/* A string that will be used to temporarily
	 * hold data. */
	char str[x + 1];
	/* Counter variable. */
	size_t i;

	/* Print a nice heading. */
	mvprintw(0, 0, "SHOP ITEMS");
	mvprintw(0, 31, "INVENTORY");
	memset(str, '_', x);
	mvprintw(1, 0,"%.*s\n", x, str);

	/* -= Render the Shop List =- */
	for (i = 0; i < shop_item_count(shop); i++)
	{

		if (ui_state->selected_item == i)
		{
			if (ui_state->mode == SHOP_LIST)
				attron(COLOR_PAIR(1));
			else
				attron(COLOR_PAIR(2));
		}
		
		writestr_item(str, shop_item_at(shop, i));
		mvprintw(2 + i, 0, "%s\n", str);

		attroff(COLOR_PAIR(1));
		attroff(COLOR_PAIR(2));
	}

	/* -= End Rendering Shop List -= */


	/* -= Render The Inventory -= */
	for (i = 0; i < Vector_len(user->inventory); i++)
	{
		invitem_t citem = Vector_at(user->inventory, invitem_t, i);
		mvprintw(2 + i, 31, "%s  x%i", citem.item.name, citem.count);
	}
	/* -= End Rendering Inventory -= */


	/* Dashes to seperate parts of the screen. */
	memset(str, '-', x);
	mvprintw(7, 0, "%.*s", x, str);
	
	/* Output formatted money string to str. */
	usd_write_into_str(str, user->money);

	/* Print the money out in yellow! */
	mvprintw(8, 0, "Balance: ");
	attron(COLOR_PAIR(3));
 	printw("$%s", str);	
	attroff(COLOR_PAIR(3));

	/* Print the money status string. */
	mvprintw(8, 20, "(%s)", ui_state->money_status);

	/* The description of the item. This will be
	 * shifted over 2 spaces and printed in yellow. */

	mvprintw(9, 0, "Description:");
	attron(COLOR_PAIR(3));
	mvprintw(10, 2, "%s", shop_item_at(shop, ui_state->selected_item).desc);
	attroff(COLOR_PAIR(3));

	memset(str, '-', x);
	mvprintw(14, 0, "%.*s", x, str);

	/* Some nice instructions for the user. */
	mvprintw(15, 0, "B - buy, Q - quit");

	/* The navigation menu. */
	if (ui_state->mode == NAVIGATION)
	{
		mvprintw(17, 0, "Navigation: >");
		mvprintw(19, 2, "TOILETS\n  OUTSIDE");
	}
}

/* Called when a key is pressed. */
static void input(shop_t* shop, user_t* user, ui_state_t* ui_state, int ch)
{
	if (ch == KEY_DOWN)	/* MOVE SELECTION DOWN */
	{
		if (ui_state->mode == SHOP_LIST)
		{
			if (ui_state->selected_item < shop_item_count(shop) - 1)
				ui_state->selected_item++;
		}
	}
	else if (ch == KEY_UP) /* MOVE SELECTION UP */
	{
		if (ui_state->mode == SHOP_LIST)
		{
			if (ui_state->selected_item > 0)
				ui_state->selected_item--;
		}
	}
	else if (ch == 'b')	/* BUY ITEM */
	{
		ui_state->mode = SHOP_LIST;
		if (user->money < shop_item_at(shop, ui_state->selected_item).price)
		{
			sprintf(ui_state->money_status, "Not enough money.");
		}
		else
		{
			user->money -= shop_item_at(shop, ui_state->selected_item).price;
			char money_str[20];
			usd_write_into_str(money_str, shop_item_at(shop, ui_state->selected_item).price);
			user_add_item(user, shop_item_at(shop, ui_state->selected_item));
			sprintf(ui_state->money_status, "-$%s", money_str);
		}
	}
	else if (ch == 'n')	/* GO TO NAVIGATION MENU */
	{
		if (ui_state->mode == SHOP_LIST) ui_state->mode = NAVIGATION;
		else ui_state->mode = SHOP_LIST;
	}
}

void screen_exec(shop_t* shop, user_t* user)
{
	ui_state_t ui_state = new_ui_state();

	init(&ui_state);

	for (;;)
	{
		render(shop, user, &ui_state);
		refresh();
		int ch = getch();

		if (ch == 'q')
		{
			break;
		}

		input(shop, user, &ui_state, ch);
		erase();
	}

	destroy();
}
