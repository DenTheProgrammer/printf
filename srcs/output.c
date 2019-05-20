/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdebbi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 17:26:41 by mdebbi            #+#    #+#             */
/*   Updated: 2019/05/20 17:26:43 by mdebbi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	free_flist(t_flist *flist)
{
	free(flist->format);
	free(flist->output);
	free(flist->length);
	free(flist->flags);
	free(flist);
}

int		printf_output(t_flist *flist)
{
	size_t	res_len;
	t_flist	*tmp;
	char	*output;

	output = ft_strnew(0);
	res_len = 0;
	while (flist)
	{
		res_len += ft_strlen(flist->output);
		output = ft_strjoin_free(output, flist->output, 1);
		tmp = flist;
		flist = flist->next;
		free_flist(tmp);
	}
	ft_stupid_putstr(output);
	free(output);
	return (res_len);
}
