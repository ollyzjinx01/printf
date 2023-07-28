#include "main.h"

/**
 * print_pointer - function to print a pointer in hexadecimal format
 * @ptr: The pointer to be printed
 * @charCount: Pointer to the current count of printed characters
 */
void print_pointer(const void *ptr, int *charCount)
{
	int i;

	unsigned long int address = (unsigned long int)ptr;
	char *hexChars = "0123456789abcdef";
	char hexDigits[16];
	int numDigits = 0;

	if (ptr == NULL)
	{
		const char *nilStr = "(nil)";
		while (*nilStr != '\0')
		{
			putchar(*nilStr);
			(*charCount)++;
			nilStr++;
		}
	} else
	{
		putchar('0');
		putchar('x');
		(*charCount) += 2;

		if (address == 0)
		{
			putchar('0');
			(*charCount)++;
		}
		else
		{
			while (address > 0)
			{
				hexDigits[numDigits] = hexChars[address & 0xF];
				address >>= 4;
				numDigits++;
			}

			for (i = numDigits - 1; i >= 0; i--)
			{
				putchar(hexDigits[i]);
				(*charCount)++;
			}
		}
	}
}
