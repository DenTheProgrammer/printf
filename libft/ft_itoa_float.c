//
// Created by Maybell Debbi on 2019-05-06.
//
#include "libft.h"

char *ft_itoa_float(double nbr, int prec)
{
	long long int mod;
	double div;
	char *res;


	mod = (long long int)nbr;
	div = ft_abs(nbr - mod);
	res = ft_itoa(mod);

	prec = (!prec) ? 6 : prec;
	res = ft_strjoin_free(res, ".", 1);
	while (prec--)
		div *= 10;
	res = ft_strjoin_free(res, ft_itoa_long((long long int)div), 3);
	return (res);
}