#include "main.h"
/**
 * print_char - Helper function to print a single character
 * @ch: The character to be printed
 * @charCount: Pointer to the current count of printed characters
 */
void print_char(char ch, int *charCount)
{
	putchar(ch);
	(*charCount)++;
}
/**
 * print_string - Helper function to print a string
 * @args: The va_list containing the arguments
 * @charCount: Pointer to the current count of printed characters
 */
void print_string(va_list args, int *charCount)
{
	const char *str = va_arg(args, const char*);

	if (str == NULL)
	{
		const char *nullStr = "(null)";

		while (*nullStr != '\0')
		{
			putchar(*nullStr);
			nullStr++;
			(*charCount)++;
		}
	} else
	{
		while (*str != '\0')
		{
			putchar(*str);
			str++;
			(*charCount)++;
		}
	}
}
/**
 * print_integer - Helper function to print an integer
 * @num: The integer to be printed
 * @charCount: Pointer to the current count of printed characters
 */
void print_integer(int num, int *charCount)
{
	char *digits;
	int i;
	int numDigits = 0;
	int temp = num;

	if (num == INT_MIN)
	{
		print_min_int(charCount);
		return;
	}
	if (num < 0)
	{
		putchar('-');
		(*charCount)++;
		num = -num;
	}
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
		free(digits);
	} else
		exit(1);
}
