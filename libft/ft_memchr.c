/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:30:18 by mdebbi            #+#    #+#             */
/*   Updated: 2019/05/21 21:52:43 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*get_chrm(size_t n, unsigned char chr, const unsigned char *cp)
{
	while (n)
	{
		if (*cp++ == chr)
			return ((void *)(cp - 1));
		n--;
	}
	return (0);
}

void			*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned long	*lp;
	const unsigned char	*cp;
	unsigned long		l[2];
	unsigned char		chr;

	chr = (unsigned char)c;
	cp = (unsigned char *)s;
	l[0] = 0x0101010101010101 * (unsigned long)chr;
	while (((unsigned long)cp & (sizeof(l[0]) - 1)) != 0 && n)
	{
		if (*cp++ == chr)
			return ((void *)(cp - 1));
		n--;
	}
	lp = (const unsigned long *)cp;
	while (n >= sizeof(unsigned long))
	{
		l[1] = l[0] ^ *lp;
		if (((l[1] - 0x0101010101010101) & ~l[1] & 0x8080808080808080) != 0)
			break ;
		lp++;
		n -= sizeof(unsigned long);
	}
	cp = (const unsigned char *)lp;
	return (get_chrm(n, chr, cp));
}
