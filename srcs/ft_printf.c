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
//todo multiple flags handling!//in progress//done?
//todo 0x and negative fix!

int		main() {
//	ft_printf("test |%x| ing\n", 0);
//	printf("test |%x| ing\n", 0);

	printf("%s\n", ft_strinsert(ft_strdup("     0x25"), ft_str_generate(3, '0'), 7));
	return 0;
}