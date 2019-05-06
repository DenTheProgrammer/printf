//
// Created by den on 05.05.19.
//


#include "printf.h"

static char get_flag(t_flist *flist)
{
	if (flist->format[1] == '#' || flist->format[1] == '0' || flist->format[1] == '-' ||
									flist->format[1] == '+' || flist->format[1] == ' ')
		return (flist->format[1]);
	return (0);
}

void apply_width(t_flist *flist)
{
	int width;
	char *output = ft_strdup(flist->output);
	int outlen = ft_strlen(output);
	int i = 0;
	char flag = get_flag(flist);

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
