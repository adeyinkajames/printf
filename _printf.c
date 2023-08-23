#include <stdarg.h>
#include <unistd.h>
#include "main.h"

int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format != '%')
        {
            // If not a '%', simply print the character
            write(1, format, 1);
            printed_chars++;
        }
        else
        {
            // Handle conversion specifiers
            format++; // Move past '%'
            if (*format == 'c')
            {
                // Handle %c specifier
                char c = va_arg(args, int);
                write(1, &c, 1);
                printed_chars++;
            }
            else if (*format == 's')
            {
                // Handle %s specifier
                char *s = va_arg(args, char *);
                while (*s)
                {
                    write(1, s, 1);
                    s++;
                    printed_chars++;
                }
            }
            else if (*format == '%')
            {
                // Handle %% specifier (print '%')
                write(1, format, 1);
                printed_chars++;
            }
        }
        format++; // Move to the next character in the format string
    }

    va_end(args);
    return printed_chars;
}
