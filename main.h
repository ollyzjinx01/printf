#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <limits.h>

int _printf(const char *format, ...);
void print_char(char ch, int *charCount);
void print_string(va_list args, int *charCount);
void print_integer(int num, int *charCount);
void print_min_int(int *charCount);
void print_max_int(int *charCount);
void print_min_int(int *charCount);
void print_digits(char *digits, int numDigits, int *charCount);
void print_binary(unsigned int num, int *charCount);
void print_unsigned_integer(unsigned int num, int *charCount);
void d_and_c(char *digits, int numDigits, unsigned int num, int *charCount);
void print_octal(unsigned int num, int *charCount);
#endif /* MAIN_H */
