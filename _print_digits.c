#include "main.h"
/**
 * print_digits - Helper function to print an array of digits as characters
 * @digits: The array of digits to be printed
 * @numDigits: The number of digits in the arraiy
 * @num: num passed in
 * @charCount: Pointer to the current count of printed characters
 */
void print_digits(char *digits, int numDigits, int num, int *charCount)
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
