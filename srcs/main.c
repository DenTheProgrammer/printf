#include "printf.h"

//    %[parameter][flags][width][.precision][length]type

int		ft_printf(const char *str, ...)
{
	va_list valist;

	va_start(valist, str);
	t_flist *format_list = parse_input(str);
	apply_formats(format_list, &valist);
	va_end(valist);
	return (printf_output(format_list));
}


int		main() {
	int a = -544353756;
	int b = 424242424;

//	printf("%c\n", NULL);//???
	ft_printf("%s\n", NULL);
	return 0;
}