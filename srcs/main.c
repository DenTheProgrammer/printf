/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashari <ashari@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 03:12:09 by ashari            #+#    #+#             */
/*   Updated: 2019/05/21 03:12:15 by ashari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>
#include <float.h>
#define SRC "%.350f|%.350f|%.350f|%.350f|%.350f", 1.e-1, 1.e-2, 1.e-18, 1.e-57, 1.e-201

int		main(void)
{
	ft_printf(SRC);
	printf(SRC);
	return (0);
}
