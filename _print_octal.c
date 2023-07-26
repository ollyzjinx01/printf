#include "main.h"

void to_oct(char *octalDigits, unsigned int num, int numDigits, int *charCount);

/**
 * print_octal - Helper function to print an unsigned integer in octal format
 * @num: The unsigned integer to be printed
 * @charCount: Pointer to the current count of printed characters
 */
void print_octal(unsigned int num, int *charCount)
{
	unsigned int temp = num;
	int numDigits = 0;
	char *octalDigits = (char *)malloc((numDigits + 1) * sizeof(char));

	if (num == 0)
	{
		putchar('0');
		(*charCount)++;
		return;
	}
	do {
		temp >>= 3;
		numDigits++;
	} while (temp != 0);

	if (octalDigits != NULL)
	{
		to_oct(octalDigits, num, numDigits, charCount);
		free(octalDigits);
	}
	else
	{
		exit(1);
	}
}

/**
 * to_oct - Helper function to convert an
 * unsigned integer to octal representation
 * @octalDigits: Pointer to a character array
 * to store the octal representation
 * @num: The unsigned integer to be converted
 * @numDigits: The number of digits in the octal representation
 * @charCount: Pointer to the current count of printed characters
 */
void to_oct(char *octalDigits, unsigned int num, int numDigits, int *charCount)
{
	int i;

	octalDigits[numDigits] = '\0';

	for (i = numDigits - 1; i >= 0; i--)
	{
		octalDigits[i] = '0' + (num & 7);
		num >>= 3;
	}

	for (i = 0; i < numDigits; i++)
	{
		putchar(octalDigits[i]);
		(*charCount)++;
	}
}
