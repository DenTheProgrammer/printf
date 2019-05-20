/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whole.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 20:25:56 by ashari            #+#    #+#             */
/*   Updated: 2019/05/17 20:26:05 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		print_int_arr(int *n)
{
	int i = ARR_SIZE - 1;

	printf("\n");
	while (i >= 0)
		printf("%d", n[i--]);
	printf("\n");
}

int			*work_whole(int exp, unsigned long wh_b, int *whole)
{
	int				*pow_two;
	int				iter;
	unsigned long 	mask;

	mask = 1;
	if (wh_b == 0)
	{
		whole = mult(whole, 0);
		return (whole);
	}
	pow_two = ft_memalloc(sizeof(int) * ARR_SIZE);
	pow_two[0] = 1;
	iter = (exp < 63) ? exp + 1 : 64;
	if (exp >= 63)
		pow_two = power(2, exp - 63, pow_two);
	while (iter-- >= 0)
	{
		if (wh_b & mask)
			whole = addit(whole, pow_two);
		pow_two = mult(pow_two, 2);
		mask <<= 1u;
	}
	ft_memdel((void **)&pow_two);
	return (whole);
}
