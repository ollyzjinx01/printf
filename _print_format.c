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
