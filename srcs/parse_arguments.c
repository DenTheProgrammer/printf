//
// Created by Maybell Debbi on 2019-05-02.
//

#include "printf.h"

t_flist *parse_input(const char *str)
{
	int w_start;
	int w_end;
	char *flags = "dscixpo";
	t_flist *flist;

	flist = NULL;
	int i = 0;
	while (str[i])
	{
		w_start = i;
		if (str[i] == '%')
		{
			while (!ft_strchr(flags, str[i]))//todo ll, hh, etc..
				i++;
			w_end = i;
			flist_push(&flist, flist_create(ft_strsub(str, w_start, w_end - w_start + 1), NULL));
		}
		else
		{
			while (str[i + 1] != '%' && str[i + 1] != 0)
				i++;
			w_end = i;
			flist_push(&flist, flist_create(NULL, ft_strsub(str, w_start, w_end - w_start + 1)));
		}
		i++;
	}
	return (flist);
}
