/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 11:39:04 by ashari            #+#    #+#             */
/*   Updated: 2019/05/21 05:15:11 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#define TMP_SIZE 100

static int		skip_chars(char *src)
{
	int		i;

	i = ARR_SIZE - 1;
	while (!src[i] && i >= 0)
		i--;
	i--;
	return (i);
}

static char		*parse_fract(char *res, int pres, char *src)
{
	int		i;
	int		j;
	char	tmp[TMP_SIZE];

	j = 0;
	tmp[j++] = '.';
	i = skip_chars(src);
	while (i >= 0 && pres--)
		tmp[j++] = src[i--] + '0';
	while (pres-- > 0)
	{
		if (j >= (TMP_SIZE - 2))
		{
			tmp[j] = '\0';
			res = ft_strjoin_free(res, tmp, 1);
			ft_bzero(&tmp, TMP_SIZE);
			j = 0;
		}
		tmp[j++] = '0';
	}
	tmp[j] = '\0';
	return (ft_strjoin_free(res, tmp, 1));
}

static char		*parse_whole(char *res, char *src, char sign, int wh_size)
{
	int		i;
	int		j;
	char	tmp[TMP_SIZE];

	i = wh_size - 1;
	j = 0;
	while (!src[i] && i)
		i--;
	res = ft_strnew(wh_size);
	if (sign == '-')
		tmp[j++] = '-';
	while (i >= 0)
	{
		if (j >= (TMP_SIZE - 2))
		{
			tmp[j] = '\0';
			res = ft_strjoin_free(res, tmp, 1);
			ft_bzero(&tmp, TMP_SIZE);
			j = 0;
		}
		tmp[j++] = src[i--] + '0';
	}
	tmp[j] = '\0';
	return (ft_strjoin_free(res, tmp, 1));
}

char			*parse_result(t_wholenumb *n, t_flist *flist)
{
	if (n->wh_b == 0)
		n->res = (n->sign == '-') ? ft_strdup("-0") : ft_strdup("0");
	else
		n->res = parse_whole(n->res, n->whole, n->sign, n->wh_size);
	if (flist->precision != 0)
		n->res = parse_fract(n->res, flist->precision, n->fract);
	else
	{
		if (ft_strchr(flist->flags, '#'))
			n->res = ft_strjoin(n->res, ".");
	}
	return (n->res);
}
