#include "main.h"

void cnp_hex(unsigned int n, const char *hc, char *hd, int *cc);
/**
 * print_hexadecimal - Helper function to print
 * an unsigned integer in hexadecimal format
 * @num: The unsigned integer to be printed
 * @uppercase: If true, use uppercase letters (A-F), else lowercase (a-f)
 * @charCount: Pointer to the current count of printed characters
 */
void print_hexadecimal(unsigned int num, bool uppercase, int *charCount)
{
	char *hexDigits = NULL;
	char *hexChars = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
	int numDigits = 0;
	unsigned int temp = num;

	if (num == 0)
	{
		putchar('0');
		(*charCount)++;
		return;
	}
	do {
		temp >>= 4;
		numDigits++;
	} while (temp != 0);

	hexDigits = (char *)malloc((numDigits + 1) * sizeof(char));

	if (hexDigits != NULL)
	{
		cnp_hex(num, hexChars, hexDigits, charCount);
		free(hexDigits);
	}
	else
	{
		exit(1);
	}
}

/**
 * cnp_hex - Helper function to convert and print
 * an unsigned integer in hexadecimal format
 * @n: The unsigned integer to be converted and printed
 * @hc: The set of hexadecimal characters to use (uppercase or lowercase)
 * @hd: Pointer to the buffer to store the hexadecimal digits
 * @cc: Pointer to the current count of printed characters
 */
void cnp_hex(unsigned int n, const char *hc, char *hd, int *cc)
{
	int i;

	int numDigits = 0;
	unsigned int temp = n;

	hd[numDigits] = '\0';

	do {
		temp >>= 4;
		numDigits++;
	} while (temp != 0);

	for (i = numDigits - 1; i >= 0; i--)
	{
		hd[i] = hc[n & 0xF];
		n >>= 4;
	}
	for (i = 0; i < numDigits; i++)
	{
		putchar(hd[i]);
		(*cc)++;
	}
}
