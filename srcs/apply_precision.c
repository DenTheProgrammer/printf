//
// Created by Maybell Debbi on 2019-05-05.
//

#include "printf.h"

int get_precision(char *format)
{
	char *dotptr;

	if ((dotptr = ft_strchr(format, '.')))
		return (ft_atoi(dotptr + 1));
	else
		return 0;
}

void	apply_precision(char *str, char *format)
{
	int prec;

	prec = get_precision(format);
	if (prec < ft_strlen(str))
		str[prec] = 0;
}

