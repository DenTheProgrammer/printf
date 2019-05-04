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
//		else if (ft_strchr(flist->format, 's'))
//			flist->output = apply_format_str(flist->format, va_arg(*valist, char*));
//		else if (ft_strchr(flist->format, 'c'))
//			flist->output = apply_format_char(flist->format, va_arg(*valist, int));
		flist = flist->next;
	}
}

char	*apply_format_int(char *format, int arg)
{
	return (ft_itoa(arg));
}