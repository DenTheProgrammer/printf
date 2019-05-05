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
//	printf("%w\n");
//	ft_printf("%w\n");
//	ft_printf("ft = %o, ptr = %p, perc = %%\n", a, &a);
//	printf("ft = %o, ptr = %p, perc = %%\n", a, &a);
//	printf("42 = %d, %s = %c\n", 42, "star", '*');
//	ft_printf("42 = %d, %s = %c\n", 42, "star", '*');
//	printf("%lu\n%lu",sizeof(long int), sizeof(long long int));
//	printf("%hhu %hhx %hhX %hho %hhd\n", a, b, a, b, a);
//	ft_printf("%hhu %hhx %hhX %hho %hhd\n", a, b, a, b, a);
	printf("%10.5s\n", "testing");
	ft_printf("%10.5s\n", "testing");
	return 0;
}