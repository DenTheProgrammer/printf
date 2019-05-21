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

static int		ft_numblen(char *n)
{
	int				i;

	i = 0;
	while (i < ARR_SIZE && !n[i])
		i++;
	return (ARR_SIZE - i);
}

char		*power(int nb, int power, char *res, int *size)
{
	int		i;
	int		j;

	i = 0;
	while (i++ < power)
	{
		j = 0;
		while (j < ARR_SIZE && j <= (*size))
			res[j++] *= nb;
		j = 0;
		while (j < ARR_SIZE && j <= (*size))
		{
			if (res[j] >= BASE)
			{
				res[j + 1] += res[j] / BASE;
				res[j] %= BASE;
				(*size)++;
			}
			j++;
		}
	}
	(*size) = j;
	return (res);
}
