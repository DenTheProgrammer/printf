/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:53:26 by mdebbi            #+#    #+#             */
/*   Updated: 2019/03/05 23:07:38 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpynoendl(char *dest, const char *src)
{
	int i;

	i = -1;
	while (src[++i])
		dest[i] = src[i];
	return (dest);
}