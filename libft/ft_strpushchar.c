//
// Created by den on 10.05.19.
//


#include "libft.h"

void	ft_strpushchar(char **str, int chr)
{
	char *new;
	size_t strlen;

	if (!*str)
		*str = ft_strnew(0);
	strlen = ft_strlen_safe(*str);
	new = ft_strnew(strlen + 1);
	ft_strcpy(new, *str);
	new[strlen] = chr;
	free(*str);
	*str = new;
}