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

int			*work_whole(int exp, long wh_b, int *whole)
{
	int		*pow_two;
	int		iter;

	pow_two = ft_memalloc(sizeof(int) * ARR_SIZE);
	pow_two[0] = 1;
	iter = (exp < 63) ? exp + 1 : 64;
	if (exp >= 63)
		pow_two = power(2, exp - 63, pow_two);
	while (iter-- && wh_b)
	{
		if (wh_b & 1)
			whole = addit(whole, pow_two);
		pow_two = mult(pow_two, 2);
		wh_b >>= 1;
	}
	ft_memdel((void **)&pow_two);
	return (whole);
}
