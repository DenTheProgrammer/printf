/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 20:24:51 by ashari            #+#    #+#             */
/*   Updated: 2019/05/20 18:42:23 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		count_fract(int sign, int exp, int *pow_five, t_wholenumb *n)
{
	int		iter;
	int		i;

	i = 0;
	if (sign)
		iter = 64 - exp - 1;
	else
	{
		iter = 64;
		while (i++ < exp - 1)
			n->fract = mult(n->fract, 10);
		pow_five = power(5, exp - 1, pow_five);
	}
	return (iter);
}

int				*work_fract(int exp, t_wholenumb *n, t_flist *flist, int sign)
{
	int				*pow_five;
	int				iter;
	unsigned long	mask;

	pow_five = ft_memalloc(sizeof(int) * (ARR_SIZE + 1));
	pow_five[0] = 1;
	n->fract[0] = 1;
	iter = count_fract(sign, exp, pow_five, n);
	mask = FIRST_BIT_M;
	while (iter-- >= 0)
	{
		pow_five = mult(pow_five, 5);
		n->fract = mult(n->fract, 10);
		if (n->fr_b & mask)
			n->fract = addit(n->fract, pow_five);
		mask >>= 1u;
	}
	ft_memdel((void **)&pow_five);
	apply_pres_f(flist->precision, n->fract, n->whole);
	return (n->fract);
}
