//
// Created by Maybell Debbi on 2019-05-13.
//

#include "libft.h"

char	*ft_str_generate(int len, char chr)
{
	char *new;

	if (len < 1)
		return (ft_strnew(0));
	new = (char *)malloc(len + 1);
	new[len] = 0;
	while (len)
		new[len-- - 1] = chr;
	return (new);
}