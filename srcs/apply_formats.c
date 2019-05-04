//
// Created by Maybell Debbi on 2019-05-04.
//

#include "printf.h"

//void	fill_formats_list(t_flist *flist, va_list *valist)
//{
//	while (flist)
//	{
//		if (ft_strchr(flist->format, 'd') || ft_strchr(flist->format, 'i'))
//			flist->argument = va_arg(*valist, int*);
//		else if (ft_strchr(flist->format, 's'))
//			flist->argument = va_arg(*valist, char**);
//		else if (ft_strchr(flist->format, 'c'))
//			flist->argument = va_arg(*valist, char*);
//		flist = flist->next;
//	}
//}

void	apply_formats(t_flist *flist, va_list *valist)
{
	while (flist)
	{
		if (ft_strchr(flist->format, 'd') || ft_strchr(flist->format, 'i'))
			flist->output = apply_format_int(flist->format, va_arg(*valist, int));
		else if (ft_strchr(flist->format, 's'))
			flist->output = apply_format_str(flist->format, va_arg(*valist, char*));
		else if (ft_strchr(flist->format, 'c'))
			flist->output = apply_format_char(flist->format, va_arg(*valist, int));
		else if (ft_strchr(flist->format, 'o'))
			flist->output = apply_format_oct(flist->format, va_arg(*valist, int));//?type?
		else if (ft_strchr(flist->format, 'x'))
			flist->output = apply_format_hex(flist->format, va_arg(*valist, int));
		else if (ft_strchr(flist->format, 'p'))
			flist->output = apply_format_ptr(flist->format, va_arg(*valist, long int));
		else if (ft_strchr(flist->format, '%'))
			flist->output = ft_strdup("%");
		flist = flist->next;
	}
}

char	*apply_format_int(char *format, int arg)
{
	return (ft_itoa(arg));
}

char	*apply_format_str(char *format, char *arg)
{
	return (arg);
}

char	*apply_format_char(char *format, char arg)
{
	char *c;
	c = ft_strnew(2);
	c[0] = arg;
	return (c);
}

char	*apply_format_oct(char *format, int arg)
{
	return (ft_itoa_base(arg, 8));
}
char	*apply_format_hex(char *format, int arg)
{
	return (ft_itoa_base(arg, 16));
}
char	*apply_format_ptr(char *format, long int arg)
{
	return (ft_strjoin("0x", ft_itoa_base(arg, 16)));
}