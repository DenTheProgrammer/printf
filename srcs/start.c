/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 20:26:45 by ashari            #+#    #+#             */
/*   Updated: 2019/05/17 21:16:25 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		ft_reslen(int *numb)
{
	int i;

	i = ARR_SIZE - 1;
	if (!numb)
		return (1);
	while (numb[i] == 0 && i > 0)
		i--;
	return (i);
}

char 		*check_inf_nan(t_wholenumb *n, char *flags)
{
	n->res = ft_strnew(5);
	if (n->wh_b == -4611686018427387904)
		ft_strcpy(n->res, "nan");
	else if (n->sign == '-')
		ft_strcpy(n->res, "-inf");
	else if (n->sign == '0')
		ft_strcpy(n->res, "inf");
	ft_memdel((void **)&(n->whole));
	ft_memdel((void **)&(n->fract));
	return (n->res);
}

char		*print_float(long double var, t_flist *flist)
{
	t_form_lf	bit;
	t_wholenumb	n;
	int			exp;

	bit.f = var;
	n.whole = ft_memalloc(sizeof(int) * ARR_SIZE);
	n.fract = ft_memalloc(sizeof(int) * ARR_SIZE);
	exp = bit.bytes.exponent - 16383;
	n.sign = (bit.bytes.sign) ? '-' : '0';
	n.fr_b = bit.bytes.mantisa;
	n.wh_b = bit.bytes.mantisa;
	if (exp == 16384)
		return (check_inf_nan(&n, flist->flags));
	if (flist->precision == -1)
		flist->precision = 6;
	if (exp >= 0 && exp < 63)
	{
		n.wh_b = bit.bytes.mantisa >> (64u - (exp + 1u));
		n.fr_b = bit.bytes.mantisa << (exp + 1u);
	}
	else if (exp >= 63)
		n.fr_b = 0;
	else
		n.wh_b = 0;
	n.whole = work_whole(exp, n.wh_b, n.whole);
	n.fract = work_fract((exp >= 0 ? exp : exp * (-1)), &n, flist, (exp >= 0));
	parse_result(&n, flist);
	return (n.res);
}
