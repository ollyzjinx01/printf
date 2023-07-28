#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");

    printf("%d\n", 65176);
    _printf("%d\n", 65176);
    printf("%d\n", -777765176);
    _printf("%d\n", -777765176);
    printf("%d\n", 00002);
    _printf("%d\n", 00002);
    printf("%d\n", 0);
    _printf("%d\n", 0);
    printf("%d\n", 7);
    _printf("%d\n", 7);
    printf("%d\n", -2255445);
    _printf("%d\n", -2255445);
    printf("Maximum value of int: %d\n", INT_MAX);
    _printf("Maximum value of int: %d\n", INT_MAX);
    printf("Minimum value of int: %d\n", INT_MIN);
    _printf("Minimum value of int: %d\n", INT_MIN);
    printf("--------------------------------\n");
    printf("%i\n", 65176);
    _printf("%i\n", 65176);
    printf("%i\n", 0);
    _printf("%i\n", 0);
    printf("%i\n", -2255445);
    _printf("%i\n", -2255445);
    printf("Maximum value of int: %i\n", INT_MAX);
    _printf("Maximum value of int: %i\n", INT_MAX);
    printf("Minimum value of int: %i\n", INT_MIN);
    _printf("Minimum value of int: %i\n", INT_MIN);
   _printf("Can you print an address?\n%p\nNice!\n", (void *)0x7fff5100b6f8);
   printf("Can you print an address?\n%p\nNice!\n", (void *)0x7fff5100b6f8);
  
  _printf("Can you print several addresses?\n%p,%p,%p,%p\nNice!\n", (void *)0x7fff5100b6f8, (void *)0x7faf51f0f608, (void *)0x6ff42510b6f8, (void *)0x7fff510236f8);
printf("Can you print several addresses?\n%p,%p,%p,%p\nNice!\n", (void *)0x7fff5100b6f8, (void *)0x7faf51f0f608, (void *)0x6ff42510b6f8, (void *)0x7fff510236f8); 
    
	_printf("%p", NULL);
	printf("%p", NULL);

	return (0);
}
