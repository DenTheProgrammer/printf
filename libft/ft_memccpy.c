/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <mdebbi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 15:29:52 by mdebbi            #+#    #+#             */
/*   Updated: 2019/04/05 15:52:31 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	c = (unsigned char)c;
	while (n--)
	{
		*(unsigned char *)dest++ = *(unsigned char *)src++;
		if (*((unsigned char *)dest - 1) == c)
			return (dest);
	}
	return (NULL);
}
