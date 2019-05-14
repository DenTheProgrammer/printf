//
// Created by den on 05.05.19.
//


#include "printf.h"

void	apply_width(t_flist *flist)
{
	int shift;
	char chr;

	if (ft_strchr(flist->flags, '-'))
		return ;//leak
	if (ft_strchr(flist->flags, '0'))
	{
		if (ft_strchr(flist->flags, '#') && (flist->type == 'x' || flist->type == 'X'))
			shift = 2;
		else shift = flist->output[0] == '-' ? 1 : 0;
	} else shift = 0;

	chr = ft_strchr(flist->flags, '0') ? '0' : ' ';
	flist->output = ft_strinsert(flist->output, ft_str_generate(flist->width - ft_strlen(flist->output), chr), shift);
}