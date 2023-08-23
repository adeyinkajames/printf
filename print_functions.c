#include "main.h"
#include <stdio.h>

/**
 * print_char - Print a character
 * @args: Arguments list containing the character to print
 *
 * Return: Number of characters printed
 */
int print_char(va_list args)
{
    char c = va_arg(args, int);
    putchar(c);
    return (1);
}

/**
 * print_string - Print a string
 * @args: Arguments list containing the string to print
 *
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
    char *s = va_arg(args, char *);
    int count = 0;

    while (*s != '\0')
    {
        putchar(*s);
        s++;
        count++;
    }

    return (count);
}

/**
 * print_percent - Print a percent character
 * @args: Unused
 *
 * Return: Number of characters printed (always 1)
 */
int print_percent(__attribute__((unused)) va_list args)
{
    putchar('%');
    return (1);
}
