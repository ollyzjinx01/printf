#include "main.h"
/**
 * print_unsigned_integer - Helper function to print an unsigned integer
 * @num: The unsigned integer to be printed
 * @charCount: Pointer to the current count of printed characters
 */
void print_unsigned_integer(unsigned int num, int *charCount)
{
	char *digits;

	unsigned int temp = num;
	int numDigits = 0;

	if (num == 0)
	{
		putchar('0');
		(*charCount)++;
		return;
	}

	do {
		temp /= 10;
		numDigits++;
	} while (temp != 0);

	digits = (char *)malloc((numDigits + 1) * sizeof(char));

	if (digits != NULL)
	{
		d_and_c(digits, numDigits, num, charCount);
		free(digits);
	} else
	{
		exit(1);
	}
}

/**
 * d_and_c - function to print digits and count
 * @digits: A character array (string) that will be used to store
 * the digits of the given number `num`.
 * The size of this array should be at least `numDigits + 1`
 * to accommodate the digits and a null-terminator.
 * @numDigits: An int representing the number of digits
 * in the given number `num`.
 * @num: The unsigned integer to be printed
 * @charCount: A pointer to an integer that will be used
 * to store the count of characters printed by the function.
 * Return: void
*/

void d_and_c(char *digits, int numDigits, unsigned int num, int *charCount)
{
	int i;

	digits[numDigits] = '\0';

	for (i = numDigits - 1; i >= 0; i--)
	{
		digits[i] = '0' + (num % 10);
		num /= 10;
	}

	for (i = 0; i < numDigits; i++)
	{
		putchar(digits[i]);
		(*charCount)++;
	}
}
