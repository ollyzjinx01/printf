#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int _printf(const char *format, ...);
void print_char(char ch, int *charCount);
void print_string(va_list args, int *charCount);
void print_integer(int num, int *charCount);
#endif /* MAIN_H */
