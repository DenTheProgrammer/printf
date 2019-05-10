//
// Created by Maybell Debbi on 2019-05-04.
//

#include "printf.h"

//void validate_format(t_flist *flist)
//{
//	//todo?
//}

void	apply_formats(t_flist *flist, va_list *valist)
{
	while (flist)
	{
		if (flist->format)
		{
//			validate_format(flist);
			if (flist->type == 'd' || flist->type == 'i')
				flist->output = apply_format_int(flist->format, valist);//todo: refactor flist->format ----> flist
			else if (flist->type == 's')
				flist->output = apply_format_str(flist->format, valist);
			else if (flist->type == 'c')
				flist->output = apply_format_char(flist->format, valist);
			else if (flist->type == 'o')
				flist->output = apply_format_oct(flist->format, valist);
			else if (flist->type == 'x')
				flist->output = apply_format_hex(flist->format, valist);
			else if (flist->type == 'X')
				flist->output = apply_format_hex(flist->format, valist);
			else if (flist->type == 'f')
				flist->output = apply_format_float(flist->format, valist);
			else if (flist->type == 'p')
				flist->output = apply_format_ptr(flist->format, valist);
			else if (flist->type == 'u')
				flist->output = apply_format_uns(flist->format, valist);
			else if (flist->type == '%')
				flist->output = ft_strdup("%");
			apply_width(flist);
			apply_flags(flist);
		}
		flist = flist->next;
	}
}

long long apply_length(char *format, va_list *valist)//todo: refactor for use new parsed length
{
	long long arg;

	arg = va_arg(*valist, long long);
	if (ft_strstr(format, "ll"))
		arg = (long long)arg;
	else if (ft_strstr(format, "l"))
		arg = (long)arg;
	else if (ft_strstr(format, "hh"))
		arg = (char)arg;
	else if (ft_strstr(format, "h"))
		arg = (short)arg;
	else
		arg = (int)arg;
	return (arg);
}
unsigned long long apply_length_uns(char *format, va_list *valist)
{
	unsigned long long arg;

	arg = va_arg(*valist, long long);
	if (ft_strstr(format, "ll"))
		arg = (unsigned long long)arg;
	else if (ft_strstr(format, "l"))
		arg = (unsigned long)arg;
	else if (ft_strstr(format, "hh"))
		arg = (unsigned char)arg;
	else if (ft_strstr(format, "h"))
		arg = (unsigned short)arg;
	else
		arg = (unsigned int)arg;
	return (arg);
}
