#include "main.h"

/**
 * print_min_int - Helper function to print INT_MIN
 * @charCount: Pointer to the current count of printed characters
 */
void print_min_int(int *charCount)
{
	const int minIntDigits[] = {2, 1, 4, 7, 4, 8, 3, 6, 4, 8};
	int i;

	putchar('-');
	(*charCount)++;

	for (i = 0; i < 10; i++)
	{
		putchar('0' + minIntDigits[i]);
		(*charCount)++;
	}
}
