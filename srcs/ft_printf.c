#include "printf.h"

//    %[parameter][flags][width][.precision][length]type

int		ft_printf(const char *str, ...)
{
	va_list valist;

	va_start(valist, str);
	t_flist *format_list = parse_input(str);
	parse_formats(format_list);
	apply_formats(format_list, &valist);
	va_end(valist);
	return (printf_output(format_list));
}
//todo float, rounding//in progress
// Makefile for testing//done
//todo better format parcing//done
//todo parcing for all flags in structure fields//done
//todo multiple flags handling!//in progress

int		main() {
	printf("test %3.4d\n", 42);
	ft_printf("test %3.4d\n", 42);
	return 0;
}