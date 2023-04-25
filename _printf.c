#include "main.h"

void printer_buffer(char buffer[], int *buff_index);

/**
 * printer_buffer - Prints buffer content
 * @buffer: char Array
 * @buff_index: Index for adding next char, represents the length.
 */
void printer_buffer(char buffer[], int *buff_index)
{
	if (*buff_index > 0)
		write(1, &buffer[0], *buff_index);

	*buff_index = 0;
}

/**
 * _printf - Printf function
 * @format: format pointer.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int x, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_index = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (x = 0; format && format[x] != '\0'; x++)
	{
		if (format[i] != '%')
		{
			buffer[buff_index++] = format[x];
			if (buff_index == BUFF_SIZE)
				printer_buffer(buffer, &buff_index);
			printed_chars++;
		}
		else
		{
			printer_buffer(buffer, &buff_index);
			flags = get_flags(format, &x);
			width = get_width(format, &x, list);
			precision = get_precision(format, &x, list);
			size = get_size(format, &x);
			++x;
			printed = handle_print(format, &x, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	printer_buffer(buffer, &buff_index);

	va_end(list);

	return (printed_chars);
}
