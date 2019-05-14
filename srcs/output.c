//
// Created by Maybell Debbi on 2019-05-03.
//

#include "printf.h"

void	free_flist(t_flist *flist)
{
	//todo
	free(flist);
}

int		printf_output(t_flist *flist)
{
	size_t res_len;

	res_len = 0;
	while (flist)
	{
		res_len += ft_strlen(flist->output);
		ft_stupid_putstr(flist->output);
		flist = flist->next;
	}
	free_flist(flist);
	return (res_len);
}