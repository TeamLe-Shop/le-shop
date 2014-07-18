all:
	cc main.c item.h item.c screen.h screen.c shop.h shop.c stringutil.h stringutil.c -lncurses -o shop
