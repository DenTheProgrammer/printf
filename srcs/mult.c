/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mult.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 20:21:23 by ashari            #+#    #+#             */
/*   Updated: 2019/05/17 20:21:43 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		*mult(int *a, int b)
{
	int			carry;
	long long	cur;
	size_t		i;

	i = 0;
	while (i < ARR_SIZE)
		a[i++] *= b;
	i = 0;
	while (i < ARR_SIZE - 1)
	{
		if (a[i] >= BASE)
		{
			a[i + 1] += a[i] / BASE;
			a[i] %= BASE;
		}
		i++;
	}
	return (a);
}
