//
// Created by Maybell Debbi on 2019-05-05.
//

#include "printf.h"

void	apply_precision(char *str, char *format)
{
	char *dotptr;
	int prec;

	if ((dotptr = ft_strchr(format, '.')))
		prec = ft_atoi(dotptr + 1);
	else
		return ;
	if (prec < ft_strlen(str))
		str[prec] = 0;
}

