#include "main.h"
#include <stdarg.h>
#include <stddef.h>

/**
 * _printf - print a formated string
 * @format: A string containing all the desired characters
 * Return: sucess 1 and error -1.
 */
int _printf(const char *format, ...)
{
	int printed_chars;
	conver_t f_list[] = {

		{"c", print_char},

		{"s", print_string},

		{"%", print_percent},

		{"d", print_integer},

		{"i", print_integer},
		{NULL, NULL}
	};
	va_list arg_list;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);
	/*Calling parser function*/
	printed_chars = parser(format, f_list, arg_list);
	va_end(arg_list);
	return (printed_chars);
}
