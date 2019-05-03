#include "printf.h"

int		get_format_count(const char *str)//not counting %% as format
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
}

//int		ft_printf(const char *str, ...)//format in prototype??
//{
//	va_list valist;
//	t_flist *flist = NULL;
//	char **parsed;
//
//	parsed = parse_input(str);
//	size_t fcount = get_format_count(str);
//	fill_formats_list(flist, parsed, fcount, &valist);
//	apply_formats(flist);
////	va_start(valist, argc);//usage
////	while (argc--)
////	{
////		printf("%s\n", va_arg(valist, char*));
////	}
//	va_end(valist);
//	return (printf_output(flist));
//}

void	apply_formats(t_flist *flist)//simple version
{
	while (flist)
	{
		flist->output = flist->argument;
		flist = flist->next;
	}
}

int		main() {
//	ft_printf("parse %s", "testing...");
	t_flist *flist = flist_create("%s", "test");
	t_flist *flist2 = flist_create("%s", " is ");
	t_flist *flist3 = flist_create("%s", "success");

	flist_push(flist);
	flist_push(flist2);
	flist_push(flist3);
	apply_formats(flist);
	printf_output(flist);
	return 0;
}