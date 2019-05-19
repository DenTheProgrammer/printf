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
#define TMP_SIZE 100

static char		*parse_fract(char *res, int pres, int *src)
{
	int		i;
	int 	j;
	char 	tmp[TMP_SIZE];

	i = ARR_SIZE - 1;
	j = 0;
	tmp[j++] = '.';
	while (!src[i] && i)
		i--;
	i--;
	while (i >= 0 && pres--)
	{
		tmp[j] = src[i--] + '0';
		j++;
	}
	while (pres-- > 0)
	{
		if (j >= (TMP_SIZE - 2))
		{
			tmp[j] = '\0';
			res = ft_strjoin_free(res, tmp, 0);
			ft_bzero(&tmp, TMP_SIZE);
			j = 0;
		}
		tmp[j++] = '0';
	}
	tmp[j] = '\0';
	res = ft_strjoin_free(res, tmp, 0);
	ft_memdel((void **)&src);
	return (res);
}

static char		*parse_whole(char *res, int *src, char sign)
{
	int		i;
	int 	j;
	char 	tmp[TMP_SIZE];

	i = ARR_SIZE - 1;
	j = 0;
	while (!src[i] && i)
		i--;
	if (sign == '-')
		tmp[j++] = '-';
	while (i >= 0)
	{
		if (j >= (TMP_SIZE - 2))
		{
			tmp[j] = '\0';
			res = ft_strjoin_free(res, tmp, 0);
			ft_bzero(&tmp, TMP_SIZE);
			j = 0;
		}
		tmp[j] = src[i--] + '0';
		j++;
	}
	tmp[j] = '\0';
	res = ft_strdup(tmp);
	ft_memdel((void **)&src);
	return (res);
}

char		*parse_result(t_wholenumb *n, t_flist *flist)
{
	if (n->wh_b == 0)
	{
		n->res = (n->sign == '-') ? ft_strdup("-0") : ft_strdup("0");
		ft_memdel((void **)&(n->whole));
	}
	else
		n->res = parse_whole(n->res, n->whole, n->sign);
	if (flist->precision != 0)
		n->res = parse_fract(n->res, flist->precision, n->fract);
	else
		{
		ft_memdel((void **) n->fract);
		if (ft_strchr(flist->flags, '#'))
			n->res = ft_strjoin(n->res, ".");
	}
	return (n->res);
}
