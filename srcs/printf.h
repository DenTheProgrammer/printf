//
// Created by den on 03.05.19.
//

#ifndef PRINTF_PRINTF_H
# define PRINTF_PRINTF_H
# include "libft.h"
# include <stdio.h>
# include <stdarg.h>

typedef struct s_flist
{
	char				*format;
	void				*argument;
	char				*output;
	struct s_flist		*next;
} t_flist;

char	**parse_input(const char *str);
void	fill_formats_list(t_flist *flist, char **parsed, size_t fcount, va_list *valist);
void	apply_formats(t_flist *flist);
int		printf_output(t_flist *flist);
t_flist	*flist_create(char *format, void *argument);
void	flist_push(t_flist *node);
#endif
