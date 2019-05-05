//
// Created by Maybell Debbi on 2019-05-04.
//

#include "printf.h"

void validate_format(t_flist *flist)
{
	//todo
}

void apply_width(t_flist *flist)
{
	int width;
	char *output = ft_strdup(flist->output);
	int outlen = ft_strlen(output);
	int i = 0;

	width = ft_atoi(flist->format + 1);
	if (width > outlen)
	{
		free(flist->output);
		flist->output = ft_strnew(width);
		while (width - outlen++)
			flist->output[i++] = (flist->format[1] == '0') ? '0' : ' ';
		ft_strcpy(flist->output + i, output);
	}
	free(output);
}

void	apply_formats(t_flist *flist, va_list *valist)
{
	while (flist)
	{
		if (flist->format)
		{
			validate_format(flist);
			if (ft_strchr(flist->format, 'd') || ft_strchr(flist->format, 'i'))
				flist->output = apply_format_int(flist->format, valist);
			else if (ft_strchr(flist->format, 's'))
				flist->output = apply_format_str(flist->format, valist);
			else if (ft_strchr(flist->format, 'c'))
				flist->output = apply_format_char(flist->format, valist);
			else if (ft_strchr(flist->format, 'o'))
				flist->output = apply_format_oct(flist->format, valist);//?type?
			else if (ft_strchr(flist->format, 'x'))
				flist->output = apply_format_hex(flist->format, valist);
			else if (ft_strchr(flist->format, 'X'))
				flist->output = apply_format_hex(flist->format, valist);
			else if (ft_strchr(flist->format, 'p'))
				flist->output = apply_format_ptr(flist->format, valist);
			else if (ft_strchr(flist->format, 'u'))
				flist->output = apply_format_uns(flist->format, valist);
			else if (ft_strchr(flist->format, '%'))
				flist->output = ft_strdup("%");
			apply_width(flist);
		}
		flist = flist->next;
	}
}

long long apply_length(char *format, va_list *valist)
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
