#include "printf.h"

/*int		get_format_count(const char *str)//not counting %% as format
{
	int count;
	int i = 0;

	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] == '%')
				i++;
			else
				count++;
		}
		i++;
	}
	return (count);
}*/

int		ft_printf(const char *str, ...)
{
	va_list valist;

//	int fcount = get_format_count(str);useless?

	va_start(valist, str);

	t_flist *format_list = parse_input(str);
	apply_formats(format_list, &valist);

	va_end(valist);
	return (printf_output(format_list));
}


int		main() {
	int a = 42;
	ft_printf("ft = %o, ptr = %p, perc = %%\n", a, &a);
	printf("ft = %o, ptr = %p, perc = %%\n", a, &a);
//	printf("%ul\n%ul",sizeof(&a), sizeof(long int));
	return 0;
}