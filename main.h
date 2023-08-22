#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>

/* _printf - Print formatted output to stdout
 * @format: The format string
 *
 * Return: Number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...);

/* main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void);

#endif /* MAIN_H */
