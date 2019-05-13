//
// Created by Maybell Debbi on 2019-05-13.
//

#include "libft.h"

char 	*ft_str_removechar(char *str, char chr)
{
	char *new;
	int i;

	if (!str)
		return (0);
	new = ft_strnew(0);
	i = 0;
	while (str[i])
	{
		if (str[i] != chr)
			ft_strpushchar(&new, str[i]);
		i++;
	}
	free(str);
	return (new);
}