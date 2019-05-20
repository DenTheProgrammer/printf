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

int				add_one_whole(int *whole, int i)
{
	whole[0] += 1;
	while (whole[i] >= BASE && i < (ARR_SIZE - 1))
	{
		whole[i + 1] += whole[i] / BASE;
		whole[i] %= BASE;
		i++;
	}
	return (i);
}

int				add_one_fract(int *fract, int i, int pres)
{
	fract[++i] += 1;
	while (fract[i] >= BASE && --pres > 0)
	{
		fract[i + 1] += fract[i] / BASE;
		fract[i] %= BASE;
		i++;
	}
	return (i);
}

int				five_and_numbs(const int *fract, int i)
{
	if (fract[i] != 5)
		return (0);
	i--;
	while (i > 0)
	{
		if (fract[i] == 0)
			i--;
		else
			return (1);
	}
	return (0);
}

static int		count_fract(int sign, int exp, int *pow_five, t_wholenumb *n)
{
	int		iter;
	int		i;

	iter = 64;
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
