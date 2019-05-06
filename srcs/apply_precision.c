//
// Created by Maybell Debbi on 2019-05-05.
//

#include "printf.h"

int get_precision_float(char *format)
{
	char *dotptr;

	if ((dotptr = ft_strchr(format, '.')))
		return (ft_atoi(dotptr + 1));
	else
		return (0);
}

int get_precision_str(char *str, char *format)
{
	char *dotptr;

	if ((dotptr = ft_strchr(format, '.')))
		return (ft_atoi(dotptr + 1));
	else
		return ft_strlen(str);
}

void	apply_precision_str(char *str, char *format)
{
	int prec;

	prec = get_precision_str(str, format);
	if (prec < ft_strlen(str))
		str[prec] = 0;
}
