#include "main.h"

/**
 * print_custom_string - to print a custom string
 * (handling non-printable characters)
 * @str: The string to be printed
 * @charCount: Pointer to the current count of printed characters
 */
void print_custom_string(const char *str, int *charCount)
{
	int i;
	const char *nullStr;

	if (str == NULL)
	{
		nullStr = "(null)";
		while (*nullStr != '\0')
		{
			putchar(*nullStr);
			(*charCount)++;
			nullStr++;
		}
	}
	else
	{
		for (i = 0; str[i] != '\0'; i++)
		{
			if (str[i] < ' ' || str[i] >= 127)
			{
				putchar('\\');
				putchar('x');
				printf("%02X", (unsigned char)str[i]);
				(*charCount) += 4;
			}
			else
			{
				putchar(str[i]);
				(*charCount)++;
			}
		}
	}
}

