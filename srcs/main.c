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
#define SRC1 "%.2147483f\n", 1.0

int		main(void)
{
	ft_printf(SRC1);
	printf(SRC1);
	return (0);
}
