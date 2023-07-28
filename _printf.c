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
	return (specifier == 'c' ||
		specifier == 's' ||
		specifier == 'S' ||
		specifier == '%' ||
		specifier == 'd' ||
		specifier == 'i' ||
		specifier == 'b' ||
		specifier == 'u' ||
		specifier == 'o' ||
		specifier == 'x' ||
		specifier == 'X' ||
		specifier == 'P');
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
	switch (**format)
	{
	case 'c':
		print_char(va_arg(args, int), charCount);
		break;
	case 's':
		print_string(args, charCount);
		break;
	case 'S':
		print_custom_string(va_arg(args, char*), charCount);
		break;
	case '%':
		print_char('%', charCount);
		break;
	case 'i':
	case 'd':
		print_integer(va_arg(args, int), charCount);
		break;
	case 'b':
		print_binary(va_arg(args, int), charCount);
		break;
	case 'u':
		print_unsigned_integer(va_arg(args, unsigned int), charCount);
		break;
	case 'o':
		print_octal(va_arg(args, unsigned int), charCount);
		break;
	case 'x':
		print_hexadecimal(va_arg(args, unsigned int), false, charCount);
		break;
	case 'X':
		print_hexadecimal(va_arg(args, unsigned int), true, charCount);
		break;
	case 'p':
		print_pointer(va_arg(args, const void*), charCount);
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

	if (format == NULL)
		return (-1);

	va_start(args, format);
	while (*ptr != '\0')
	{
		if (*ptr == '%')
		{
			if (is_valid_format_specifier(*(ptr + 1)))
			{
				ptr++;
				handle_format_specifier(&ptr, args, &charCount);
			} else if ((ptr[1] == ' ') || (ptr[1] == '\0'))
			{
				continue;
			} else
			{
				putchar(*ptr);
				charCount++;
			}
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
