/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whole.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 20:25:56 by ashari            #+#    #+#             */
/*   Updated: 2019/05/21 05:16:43 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char			*work_whole(int exp, unsigned long wh_b, char *whole)
{
	char			*pow_two;
	int				iter;
	unsigned long	mask;

	mask = 1;
	if (wh_b == 0)
	{
		whole = mult(whole, 0);
		return (whole);
	}
	pow_two = ft_strnew(sizeof(char) * (ARR_SIZE + 1));
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
