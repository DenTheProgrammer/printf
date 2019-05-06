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

//	printf("%s\n", NULL);
//	printf("%+20d test %#20x\n", 0, 285);
//	ft_printf("%+20d test %#20x\n", 0, 285);
	printf("%f\n", 3.1);
	ft_printf("%f\n", 3.141592);
	return 0;
}