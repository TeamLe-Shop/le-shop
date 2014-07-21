#ifndef STRINGUTIL_H
#define STRINGUTIL_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/* Returns the index of a character in
 * a string. Returns -1 if not found.
 */
int indexof(char*, int);

/* -= CURRENTLY UNUSED =-
 * Stores a string containing a _f_ to
 * _p_ decimal places.
 */
void decimal_places(char* str, float f, int p);

#endif /* STRINGUTIL_H */
