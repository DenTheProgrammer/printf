//
// Created by Maybell Debbi on 2019-05-02.
//

#include "printf.h"

t_flist *parse_input(const char *str)
{
	int w_start;
	char *types = "cspdiouxX%f";//todo f
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
			while (str[i] != 0 && !ft_strchr(types, str[i]))//todo ll, hh, etc..
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
