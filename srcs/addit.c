/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 20:18:59 by ashari            #+#    #+#             */
/*   Updated: 2019/05/17 20:22:36 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		ft_numblen(int *n)
{
	int				i;

	i = 0;
	while (i < ARR_SIZE && !n[i])
		i++;
	return (ARR_SIZE - i);
}

int				*addit(int *a, int *b)
{
	int		i;
	int		len;

	i = 0;
	len = (ft_numblen(a) > ft_numblen(b)) ?
	ft_numblen(a) : ft_numblen(b);
	while (i < len)
	{
		a[i] = a[i] + b[i];
		if (a[i] >= BASE)
		{
			a[i + 1] = a[i + 1] + a[i] / BASE;
			a[i] = a[i] % BASE;
		}
		i++;
	}
	return (a);
}
