//
// Created by Maybell Debbi on 2019-05-05.
//
#include "printf.h"

int	throw_error(char *msg)
{
	write(2, msg, ft_strlen(msg));
	exit(0);
}