#include "main.h"
#include <stdio.h>
/**
 * _printf - main function to print in console
 * @mar: array to print and check type
 * Return: count of character printed
 */
int _printf(const char *mar, ...)
{
	int start = -1;

	if (mar != NULL)
	{
		int i;
		va_list arg;
		int (*o)(va_list);

		va_start(arg, start);

		if (mar[0] == '%' && mar[1] == '\0')
			return (-1);
		start = 0;

		for (i = 0; mar[i] != '\0'; i++)
		{
			if (mar[i] == '%')
			{
				if (mar[i + 1] == '%')
				{
					start += putchar(mar[i]);
					i++;
				}
				else if (mar[i + 1] != '\0')
				{
					o = get_func(mar[i + 1]);
					start += (o ? o(arg) : _putchar(mar[i]) + putchar(mar[i + 1]));
					i++;
				}
			}
			else
				start += putchar(mar[i]);
		}
		va_end(arg);
	}
	return (start);
}
