/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 16:41:40 by mdebbi            #+#    #+#             */
/*   Updated: 2019/05/20 16:41:42 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

#define PUSH flist_push
#define CREATE flist_create
#define SUB ft_strsub

t_flist		*parse_input(const char *str)
{
	int				w_start;
	static char		*types = "cspdiouxX%f";
	static t_flist	*flist = NULL;
	size_t			len;
	static size_t	i = -1;

	len = ft_strlen(str);
	while (++i < len)
	{
		w_start = i;
		if (str[i] == '%')
		{
			i++;
			while (str[i] != 0 && !ft_strchr(types, str[i]))
				i++;
			PUSH(&flist, CREATE(SUB(str, w_start, i - w_start + 1), NULL));
		}
		else
		{
			while (str[i + 1] != '%' && str[i + 1] != 0)
				i++;
			PUSH(&flist, CREATE(NULL, SUB(str, w_start, i - w_start + 1)));
		}
	}
	return (flist);
}

static int	get_width(char *str)
{
	int res;

	res = -1;
	if (ft_isdigit(*str))
		res = 0;
	while (ft_isdigit(*str))
		res = (res * 10) + (*str++ - '0');
	return (res);
}

static int	get_precision(char *format)
{
	char *dotptr;

	if (!(dotptr = ft_strchr(format, '.')))
		return (-1);
	return (ft_atoi(dotptr + 1));
}

static char	*get_length(char *format)
{
	if (ft_strstr(format, "ll"))
		return (ft_strdup("ll"));
	else if (ft_strstr(format, "l"))
		return (ft_strdup("l"));
	else if (ft_strstr(format, "L"))
		return (ft_strdup("L"));
	else if (ft_strstr(format, "hh"))
		return (ft_strdup("hh"));
	else if (ft_strstr(format, "h"))
		return (ft_strdup("h"));
	else
		return (NULL);
}

void		parse_formats(t_flist *flist)
{
	int			i;
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
