//
// Created by Maybell Debbi on 2019-05-05.
//

#include "printf.h"

int get_precision_float(t_flist *flist)
{
	return (flist->precision < 0) ? 0 : flist->precision;//?
}

void	apply_precision_str(char *str, t_flist *flist)
{
	int prec;

	prec = (flist->precision < 0) ? ft_strlen(str) : flist->precision;
	if (prec < ft_strlen(str))
		str[prec] = 0;
}
