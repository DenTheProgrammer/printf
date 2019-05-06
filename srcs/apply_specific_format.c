//
// Created by Maybell Debbi on 2019-05-05.
//

#include "printf.h"

char	*apply_format_int(char *format, va_list *valist)
{
	long long arg;

	arg = apply_length(format, valist);
	return (ft_itoa_long(arg));
}

char	*apply_format_uns(char *format, va_list *valist)
{
	unsigned long int arg;

	arg = apply_length_uns(format, valist);
	return (ft_itoa_uns(arg));
}

char	*apply_format_str(char *format, va_list *valist)
{
	char *arg;
	char *tmp;

	tmp = va_arg(*valist, char*);
	arg = ft_strdup(tmp ? tmp : "(null)");
	apply_precision_str(arg, format);
	return (arg);
}

char	*apply_format_char(char *format, va_list *valist)
{

	char *c;

	c = ft_strnew(2);
	c[0] = va_arg(*valist, int);
	return (c);
}

char	*apply_format_oct(char *format, va_list *valist)
{
	unsigned long long arg;

	arg = apply_length_uns(format, valist);
	return (ft_itoa_base(arg, 8));
}
char	*apply_format_hex(char *format, va_list *valist)
{
	unsigned long long arg;

	arg = apply_length_uns(format, valist);

	return (ft_strchr(format, 'x') ? ft_itoa_base(arg, 16) : ft_itoa_Ubase(arg, 16));
}
char	*apply_format_ptr(char *format, va_list *valist)
{
	long int arg;

	arg = va_arg(*valist, long int);
	return (ft_strjoin("0x", ft_itoa_base(arg, 16)));
}
char	*apply_format_float(char *format, va_list *valist)
{
	double arg;

	arg = va_arg(*valist, double);
	return (ft_itoa_float(arg, get_precision_float(format)));
}