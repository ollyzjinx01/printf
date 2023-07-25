#include "main.h"
#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
/**
 * is_valid_format_specifier - to check if char is a valid one
 * @specifier: char to check
 * Return: boolean true or false
 */
bool is_valid_format_specifier(char specifier)
{
	return (specifier == 'c' || specifier == 's' || specifier == '%');
}

/**
 * handle_format_specifier - function to decide specifier and putchar
 * @format: format specifier string
 * @args: list of args passed in
 * @charCount: current count of printed characters
 *
 * Return: void
 */
void handle_format_specifier(const char **format, va_list args, int *charCount)
{
	const char *str;

	switch (**format)
	{
	case 'c':
		putchar(va_arg(args, int));
		(*charCount)++;
		break;
	case 's':
		str = va_arg(args, const char*);

		while (*str != '\0')
		{
			putchar(*str);
			str++;
			(*charCount)++;
		}
		break;
	default:
		break;
	}
}


/**
 * _printf - Function that produces output according to a format.
 * write output to stdout, the standard output stream
 *
 * @format: is a character string.
 * The format string is composed of zero or more directives.
 * character strings tp be handled (c,s,%)
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;

	int charCount = 0;
	const char *ptr = format;

	va_start(args, format);
	while (*ptr != '\0')
	{
		if (*ptr == '%' && (is_valid_format_specifier(*(ptr + 1))))
		{
			ptr++;
			handle_format_specifier(&ptr, args, &charCount);
		} else
		{
			putchar(*ptr);
			charCount++;
		}
		ptr++;
	}

	va_end(args);
	return (charCount);
}

