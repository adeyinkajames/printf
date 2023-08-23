#include "main.h"
/**
 * _printf -  function that produces output according to a format
 * @format: format.
 * Return: the number of characters printed
 */
int _printf(const char *format, ...);
{
	int i, str_chara, chara = 0;
	va_list args;

	va_start(args, format);

	for (i = 0; format[i] != NULL; i++)
	{
	if (format[i] != '%')
	{
		putcharj(format[i]);
	}
	if (format[1] == '%' && format[i + 1] == 'c')
	{
		putcharj(va_arg(args, int));
		i++
	}
	if (format[1] == '%' && format[i + 1] == 's')
	{
		str_chara = putsj(va_arg(args, char *));
		i++
			chara += (str_chara - 1);
	}
	if (format[1] == '%' && format[i + 1] == 's')
	{
		putcharj('%');
	}
	chara++;
	}
	va_end(args);
	return (chara);
}
