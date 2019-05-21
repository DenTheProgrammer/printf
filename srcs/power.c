/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   power.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 20:20:26 by ashari            #+#    #+#             */
/*   Updated: 2019/05/21 05:08:53 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*power(int nb, int power, char *res)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	size = 1;
	while (i++ < power)
	{
		j = 0;
		while (j < ARR_SIZE && j < size)
			res[j++] *= nb;
		j = 0;
		while (j < ARR_SIZE && j < size)
		{
			if (res[j] >= BASE)
			{
				res[j + 1] += res[j] / BASE;
				res[j] %= BASE;
				size++;
			}
			j++;
		}
	}
	return (res);
}
