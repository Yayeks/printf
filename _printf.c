#include "main.h"
#include <stdio.h>
/**
 * _printf - main function to print in console
 * @format: array to print and check type
 * Return: count of character printed
 */
int _printf(const char *format, ...)
{
	int start = -1;

	if (format != NULL)
	{
		int i;
		va_list arg;
		int (*o)(va_list);

		va_start(arg, start);

		if (format[0] == '%' && format[1] == '\0')
			return (-1);
		start = 0;

		for (i = 0; format[i] != '\0'; i++)
		{
			if (format[i] == '%')
			{
				if (format[i + 1] == '%')
				{
					start += putchar(format[i]);
					i++;
				}
				else if (format[i + 1] != '\0')
				{
					o = get_func(format[i + 1]);
					start += (o ? o(arg) : putchar(format[i]) + putchar(format[i + 1]));
					i++;
				}
			}
			else
				start += putchar(format[i]);
		}
		va_end(arg);
	}
	return (start);
}
