//
// Created by Maybell Debbi on 2019-05-02.
//

#include "printf.h"

t_flist *parse_input(const char *str)
{
	int w_start;
	char *types = "cspdiouxX%f";
	t_flist *flist;

	size_t len = ft_strlen(str);
	flist = NULL;
	size_t i = 0;
	while (i < len)
	{
		w_start = i;
		if (str[i] == '%')
		{
			i++;
			while (str[i] != 0 && !ft_strchr(types, str[i]))
				i++;
			flist_push(&flist, flist_create(ft_strsub(str, w_start, i - w_start + 1), NULL));
		}
		else
		{
			while (str[i + 1] != '%' && str[i + 1] != 0)
				i++;
			flist_push(&flist, flist_create(NULL, ft_strsub(str, w_start, i - w_start + 1)));
		}
		i++;
	}
	return (flist);
}

static int 	get_width(char *str)
{
	int res;

	res = -1;
	if (ft_isdigit(*str))
		res = 0;
	while (ft_isdigit(*str))
		res = (res * 10) + (*str++ - '0');
	return (res);
}

static int get_precision(char *format)
{
	char *dotptr;

	if (!(dotptr = ft_strchr(format, '.')))
		return (-1);
	return (ft_atoi(dotptr + 1));

}

static char *get_length(char *format)
{
	if (ft_strstr(format, "ll"))
		return (ft_strdup("ll"));
	else if(ft_strstr(format, "l"))
		return (ft_strdup("l"));
	else if(ft_strstr(format, "hh"))
		return (ft_strdup("hh"));
	else if(ft_strstr(format, "h"))
		return (ft_strdup("h"));
	else return (NULL);
}


void	parse_formats(t_flist *flist)
{
	int i;

	static char *flags = "0+- #";

	while (flist)
	{
		i = 1;
		if (flist->format)
		{
			while (ft_strchr(flags, flist->format[i]))
				ft_strpushchar(&flist->flags, flist->format[i++]);
			flist->width = get_width(flist->format + i);
			flist->precision = get_precision(flist->format);
			flist->length = get_length(flist->format);
			while (flist->format[i])
				i++;
			flist->type = flist->format[i - 1];
		}
		flist = flist->next;
	}
}