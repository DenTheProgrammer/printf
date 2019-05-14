//
// Created by Maybell Debbi on 2019-05-05.
//

#include "printf.h"

void	apply_format_int(t_flist *flist, va_list *valist)
{
	long long arg;

	arg = apply_length(flist, valist);
	flist->output = ft_itoa_long(arg);
}

void	apply_format_uns(t_flist *flist, va_list *valist)
{
	unsigned long int arg;

	flist->flags = ft_str_removechar(flist->flags, '+');
	flist->flags = ft_str_removechar(flist->flags, ' ');
	arg = apply_length_uns(flist, valist);
	flist->output = ft_itoa_uns(arg);
}

void	apply_format_str(t_flist *flist, va_list *valist)
{
	char *tmp;

	tmp = va_arg(*valist, char*);
	flist->output = ft_strdup(tmp ? tmp : "(null)");
	apply_precision_str(flist);
}

void	apply_format_char(t_flist *flist, va_list *valist)
{

	char *c;

	flist->precision = -1;
	c = ft_strnew(2);
	c[0] = va_arg(*valist, int);
	if (c[0] == 0)
	{
		c[0] = -1;
		free(flist->flags);
		flist->flags = ft_strdup("");
	}
	flist->output = c;
}

void	apply_format_oct(t_flist *flist, va_list *valist)
{
	unsigned long long arg;

	arg = apply_length_uns(flist, valist);
	flist->output = ft_itoa_base(arg, 8);
}
void	apply_format_hex(t_flist *flist, va_list *valist)
{
	unsigned long long arg;

	arg = apply_length_uns(flist, valist);

	flist->output = (flist->type == 'x') ? ft_itoa_base(arg, 16) : ft_itoa_Ubase(arg, 16);
}
void	apply_format_ptr(t_flist *flist, va_list *valist)
{
	long int arg;

	arg = va_arg(*valist, long int);
	flist->output = ft_strjoin("0x", ft_itoa_base(arg, 16));
}
void	apply_format_float(t_flist *flist, va_list *valist)
{
	double arg;

	arg = va_arg(*valist, double);
	flist->output = ft_itoa_float(arg, get_precision_float(flist));
}

void	apply_format_percent(t_flist *flist, va_list *valist)
{
	flist->output = ft_strdup("%");
	flist->flags = ft_str_removechar(flist->flags, ' ');
}