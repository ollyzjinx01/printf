#include "main.h"
/**
 * print_binary - Helper function to print an integer in binary format
 * @num: The unsigned integer to be printed
 * @charCount: Pointer to the current count of printed characters
 */
void print_binary(unsigned int num, int *charCount)
{
	int numBits;
	unsigned int mask;

	if (num == 0)
	{
		putchar('0');
		(*charCount)++;
		return;
	}

	numBits = sizeof(num) * 8;
	mask = 1 << (numBits - 1);

	while ((mask & num) == 0)
	{
		mask >>= 1;
	}

	for (; mask > 0; mask >>= 1)
	{
		putchar((num & mask) ? '1' : '0');
		(*charCount)++;
	}
}
