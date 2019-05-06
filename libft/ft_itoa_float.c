//
// Created by Maybell Debbi on 2019-05-06.
//
#include "printf.h"

char *ft_itoa_float(double nbr, int prec)
{
	long long int mod;
	double div;
	char *res;


	mod = (long long int)nbr;
	div = ft_abs(nbr - mod);
	res = ft_itoa(mod);

	prec = (!prec) ? 6 : prec;
	res = ft_strjoin_free(res, ".");
	while (prec--)
		div *= 10;
	res = ft_strjoin_free(res, ft_itoa((int)div));
	return (res);
}