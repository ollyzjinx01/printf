#include "main.h"
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
	char *string;
	int printed_chars = 0;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == 'c')
			{
				putchar(va_arg(args, int));
				printed_chars++;
			} else if (*format == 's')
			{
				string = va_arg(args, char*);
				while (*string)
				{
					putchar(*string);
					string++;
					printed_chars++;
				}
			} else if (*format == '%')
			{
				putchar('%');
				printed_chars++;
			}
		} else
		{
			putchar(*format);
			printed_chars++;
		}
		format++;
	}
	va_end(args);
	return (printed_chars);
}
