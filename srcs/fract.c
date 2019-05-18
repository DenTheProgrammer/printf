/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 20:24:51 by ashari            #+#    #+#             */
/*   Updated: 2019/05/17 21:19:24 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		apply_pres_f(int pres, int *fract, int *whole)
{
	int 	i;
	int 	tmp_pres;

	i = ARR_SIZE - 1;
	tmp_pres = pres;
	while (fract[i] == 0)
		i--;
	i--;
	while (tmp_pres--)
		i--;
	if (fract[i] > 5 || (fract[i + 1] % 2 != 0 && fract[i] == 5))
	{
		fract[++i] += 1;
		while (fract[i] >= BASE && --pres > 0)
		{
			fract[i + 1] += fract[i] / BASE;
			fract[i] %= BASE;
			i++;
		}
	}
	else if (pres == 0)
	{
		if (whole[0] % 2 != 0 && fract[i] == 5)
		{
			whole[0] += 1;
			i = 0;
			while (whole[i] >= BASE && i < (ARR_SIZE - 1))
			{
				whole[i + 1] += whole[i] / BASE;
				whole[i] %= BASE;
				i++;
			}
		}
	}
}

int			*work_fract(int exp, t_wholenumb *n, t_flist *flist, int sign)
{
	int		*pow_five;
	int		iter;
	int		i;
	unsigned long	mask;

	pow_five = ft_memalloc(sizeof(int) * ARR_SIZE);
	pow_five[0] = 1;
	n->fract[0] = 1;
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
	mask = FIRST_BIT_M;
	while (iter--)
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
