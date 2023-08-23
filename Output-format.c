#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Print formatted output to stdout
 * @format: The format string
 *
 * Return: Number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
va_list args;
va_start(args, format);
int count = 0;  // To keep track of the number of characters printed
while (*format != '\0')
{
if (*format == '%')
{
format++;  // Move past '%'
// Handle conversion specifiers
switch (*format)
{
case 'c':
{
char c = (char) va_arg(args, int);
putchar(c);
count++;
break;
}
case 's':
{
char *s = va_arg(args, char *);
while (*s != '\0')
{
putchar(*s);
s++;
count++;
}
break;
}
case '%':
{
putchar('%');
count++;
break;
}
default:
{
// Invalid conversion specifier, just print the character
putchar('%');
putchar(*format);
count += 2;
break;
}
}
}
else
{
// Regular character, print as is
putchar(*format);
count++;
}
format++;  // Move to the next character
}
va_end(args);
return count;
}
/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
_printf("I'm not going anywhere. You can print that wherever you want to. I'm here and I'm a Spur for life\n");
_printf("Character: %c\n", 'A');
_printf("String: %s\n", "Hello, World!");
_printf("Percentage sign: %%\n");
return 0;
)
