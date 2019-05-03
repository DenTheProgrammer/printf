#include <stdio.h>
#include <stdarg.h>
#include "libft.h"
#include "printf.h"

int  get_arguments_count(const char *str)
{
	int count;

	count = 0;
	while (*str)
	{
		if (*str == '%')
			count++;
		str++;
	}
	return (count);
}

int ft_printf(const char *str, ...)//format in prototype?? return int??
{
	va_list list;
	int argc = get_arguments_count(str);
	va_start(list, argc);
	while (argc--)
	{
		printf("%d\n", va_arg(list, int));
	}
	va_end(list);
	return (0); //TODO return?
}


int main() {
//	ft_printf("%%%%", 42, 21, 314, 5);
	ft_putstr("test");
	t_flist *flist = malloc(sizeof(t_flist));
	flist->next = NULL;
	flist->format = "s";
	flist->argument = "success";
	flist->output = "success";
	return 0;
}