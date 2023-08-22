#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * _printf - Print formatted output to stdout
 * @format: The format string
 *
 * Return: Number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    print_handler_t handlers[] = {
        {'c', print_char},
        {'s', print_string},
        {'%', print_percent},
        {'\0', NULL}
    };

    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;

            int i = 0;
            while (handlers[i].specifier != '\0')
            {
                if (*format == handlers[i].specifier)
                {
                    count += handlers[i].func(args);
                    break;
                }
                i++;
            }
        }
        else
        {
            putchar(*format);
            count++;
        }

        format++;
    }

    va_end(args);
    return (count);
}
