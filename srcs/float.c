/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 11:39:04 by ashari            #+#    #+#             */
/*   Updated: 2019/05/17 21:20:04 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int		parse_fract(int j, char *res, int pres, int *src)
{
	int		i;

	i = ARR_SIZE - 1;
	while (!src[i])
		i--;
	i--;
	while (i >= 0 && pres--)
	{
		res[j] = src[i--] + '0';
		j++;
	}
	while (pres--)
		res[j++] = '0';
	ft_memdel((void **)&src);
	return (j);
}

static int		parse_whole(int j, char *res, int *src)
{
	int		i;

	i = ARR_SIZE - 1;
	while (!src[i])
		i--;
	while (i >= 0)
	{
		res[j] = src[i--] + '0';
		j++;
	}
	ft_memdel((void **)&src);
	return (j);
}

char		*parse_result(t_wholenumb *n, t_flist *flist)
{
	int		j;

	j = 0;
	if (n->sign == '-')
		n->res[j++] = '-';
	if (n->wh_b == 0)
		n->res[j++] = '0';
	else
		j = parse_whole(j, n->res, n->whole);
	if (flist->precision != 0)
	{
		n->res[j++] = '.';
		j = parse_fract(j, n->res, flist->precision, n->fract);
	}
	else
		ft_memdel((void **)n->fract);
	n->res[j] = '\0';
	return (n->res);
}
