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
			if (flist->type == 'd' || flist->type == 'i')
				flist->output = apply_format_int(flist, valist);
			else if (flist->type == 's')
				flist->output = apply_format_str(flist, valist);
			else if (flist->type == 'c')
				flist->output = apply_format_char(flist, valist);
			else if (flist->type == 'o')
				flist->output = apply_format_oct(flist, valist);
			else if (flist->type == 'x')
				flist->output = apply_format_hex(flist, valist);
			else if (flist->type == 'X')
				flist->output = apply_format_hex(flist, valist);
			else if (flist->type == 'f')
				flist->output = apply_format_float(flist, valist);
			else if (flist->type == 'p')
				flist->output = apply_format_ptr(flist, valist);
			else if (flist->type == 'u')
				flist->output = apply_format_uns(flist, valist);
			else if (flist->type == '%')
				flist->output = ft_strdup("%");
			apply_flags(flist);
			apply_width(flist);
		}
		flist = flist->next;
	}
}

long long apply_length(t_flist *flist, va_list *valist)
{
	long long arg;

	arg = va_arg(*valist, long long);
	if (ft_strstr(flist->length, "ll"))
		arg = (long long)arg;
	else if (ft_strstr(flist->length, "l"))
		arg = (long)arg;
	else if (ft_strstr(flist->length, "hh"))
		arg = (char)arg;
	else if (ft_strstr(flist->length, "h"))
		arg = (short)arg;
	else
		arg = (int)arg;
	return (arg);
}
unsigned long long apply_length_uns(t_flist *flist, va_list *valist)
{
	unsigned long long arg;

	arg = va_arg(*valist, long long);
	if (ft_strstr(flist->length, "ll"))
		arg = (unsigned long long)arg;
	else if (ft_strstr(flist->length, "l"))
		arg = (unsigned long)arg;
	else if (ft_strstr(flist->length, "hh"))
		arg = (unsigned char)arg;
	else if (ft_strstr(flist->length, "h"))
		arg = (unsigned short)arg;
	else
		arg = (unsigned int)arg;
	return (arg);
}
