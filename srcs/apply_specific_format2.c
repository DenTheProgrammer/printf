/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_specific_format2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 17:22:36 by mdebbi            #+#    #+#             */
/*   Updated: 2019/05/20 17:22:37 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	apply_format_char(t_flist *flist, va_list *valist)
{
	char *c;

	flist->precision = -1;
	c = ft_strnew(2);
	c[0] = va_arg(*valist, int);
	flist->flags = ft_str_removechar(flist->flags, ' ');
	if (c[0] == 0)
	{
		c[0] = -1;
		flist->flags = ft_str_removechar(flist->flags, '+');
	}
	flist->output = c;
}

void	apply_format_oct(t_flist *flist, va_list *valist)
{
	unsigned long long arg;

	arg = apply_length_uns(flist, valist);
	flist->output = ft_itoa_base(arg, 8);
}

void	apply_format_hex(t_flist *flist, va_list *valist)
{
	unsigned long long arg;

	arg = apply_length_uns(flist, valist);
	flist->output = (flist->type == 'x') ? ft_itoa_base(arg, 16)
			: ft_itoa_Ubase(arg, 16);
}

void	apply_format_ptr(t_flist *flist, va_list *valist)
{
	long int arg;

	arg = va_arg(*valist, long int);
	if (arg == 0)
		flist->output = ft_strdup("0x");
	else
		flist->output = ft_strjoin_free("0x", ft_itoa_base(arg, 16), 2);
}
