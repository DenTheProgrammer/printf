/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_pres_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 17:40:01 by ashari            #+#    #+#             */
/*   Updated: 2019/05/20 17:40:17 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		apply_pres_f(int pres, int *fract, int *whole)
{
	int		i;
	int		tmp_i;
	int		tmp_pres;

	i = ARR_SIZE - 1;
	tmp_pres = pres;
	while (fract[i] == 0 && i > 0)
		i--;
	i--;
	tmp_i = i;
	while (tmp_pres-- && i >= -1)
		i--;
	if (((whole[0] % 2 != 0 && fract[i] == 5) || fract[i] > 5
	|| five_and_numbs(fract, tmp_i)) && pres == 0 && i >= 0)
		add_one_whole(whole, 0);
	else if ((fract[i] > 5 || (fract[i + 1] % 2 != 0
	&& fract[i] == 5)) && i >= 0)
	{
		add_one_fract(fract, i, pres);
		if (fract[tmp_i] >= BASE)
		{
			fract[tmp_i] %= BASE;
			add_one_whole(whole, 0);
		}
	}
}
