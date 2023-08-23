#include <stdarg.h>
#include <unistd.h>
#include "main.h"

int _printf(const char *format, ...)
{
    int count = 0;
    va_list args;
    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++; // Move past '%'
            if (*format == '\0')
                break; // End of format string

            // Process format specifiers
            switch (*format)
            {
                case 'c':
                {
                    char c = va_arg(args, int);
                    write(1, &c, 1);
                    count++;
                    break;
                }
                case 's':
                {
                    char *s = va_arg(args, char *);
                    while (*s)
                    {
                        write(1, s, 1);
                        s++;
                        count++;
                    }
                    break;
                }
                case 'd': case 'i':
                {
                    int num = va_arg(args, int);
                    if (num < 0)
                    {
                        char minus = '-';
                        write(1, &minus, 1);
                        count++;
                        num = -num;
                    }
                    char buffer[20]; // Assuming the number won't be longer than 20 digits
                    int len = 0;
                    do
                    {
                        buffer[len++] = num % 10 + '0';
                        num /= 10;
                    } while (num);
                    while (len > 0)
                    {
                        len--;
                        write(1, &buffer[len], 1);
                        count++;
                    }
                    break;
                }
                case '%':
                {
                    write(1, "%", 1);
                    count++;
                    break;
                }
                // Add more cases for other format specifiers if needed
                default:
                    write(1, format, 1);
                    count++;
            }
        }
        else
        {
            write(1, format, 1);
            count++;
        }
        format++;
    }

    va_end(args);
    return count;
}
