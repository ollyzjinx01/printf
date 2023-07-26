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
