#ifndef USD_H
#define USD_H

typedef long int usd_cent;

/*
 * Outputs _price_ in the format of:
 *   [price / 100].[price % 100]
 * Into a string.
 *
 * It will insert an extra '0' before
 * the second value if it is less than 10.
 */
void usd_write_into_str(char* str, usd_cent cents);

#endif /* USD_H */
