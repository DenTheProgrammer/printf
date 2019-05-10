//
// Created by den on 05.05.19.
//


#include "printf.h"

void apply_width(t_flist *flist)
{
	int width;
	char *output = ft_strdup(flist->output);
	int outlen = ft_strlen(output);
	int i = 0;

	if (ft_strchr(flist->flags, '-'))
		return ;
	width = flist->width;
	if (width > outlen)
	{
		free(flist->output);
		flist->output = ft_strnew(width);
		while (width - outlen++)
			flist->output[i++] = (ft_strchr(flist->flags, '0')) ? '0' : ' ';
		ft_strcpy(flist->output + i, output);
	}
	free(output);
}
