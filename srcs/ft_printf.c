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
//todo float, rounding, Lflag?, Makefile for testing
//todo better format parcing
//todo parcing for all flags in structure fields

//int		main() {
//	int a = -544353756;
//	int b = 424242424;
//
////	printf("%c\n", NULL);//???
//
////	printf("%s\n", NULL);
////	printf("%+20d test %#20x\n", 0, 285);
////	ft_printf("%+20d test %#20x\n", 0, 285);
//	printf("%s\n", "success");
//	ft_printf("%s\n", "success");
//	return 0;
//}