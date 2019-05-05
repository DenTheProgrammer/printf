/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <mdebbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 21:27:10 by mdebbi            #+#    #+#             */
/*   Updated: 2019/04/07 17:33:48 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	intlen(long long n, int base)
{
	size_t len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		len++;
		n /= base;
	}
	return (len);
}

char			*ft_itoa_Ubase(long long n, int base)
{
	char	*res;
	size_t	len;
	int		min;
	char *barr;

	barr = "0123456789ABCDEF";
	min = 1;
	len = intlen(n, base);
	res = ft_strnew(len);
	if (!res)
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		min = -1;
	}
	while (len)
	{
		if (min == -1 && len == 1)
			break ;
		res[--len] = barr[min * (n % base)];
		n /= base;
	}
	return (res);
}
