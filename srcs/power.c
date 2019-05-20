/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 20:20:26 by ashari            #+#    #+#             */
/*   Updated: 2019/05/17 20:21:13 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		*power(int nb, int power, int *res)
{
	int		i;
	int		j;

	i = 0;
	while (i++ < power)
	{
		j = 0;
		while (j < ARR_SIZE)
			res[j++] *= nb;
		j = 0;
		while (j < ARR_SIZE)
		{
			if (res[j] >= BASE)
			{
				res[j + 1] += res[j] / BASE;
				res[j] %= BASE;
			}
			j++;
		}
	}
	return (res);
}
