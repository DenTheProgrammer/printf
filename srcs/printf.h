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
//	void				*argument;//useless
	char				*output;
	struct s_flist		*next;
} t_flist;

t_flist *parse_input(const char *str);
//void	fill_formats_list(t_flist *flist, va_list *valist);
void	apply_formats(t_flist *flist, va_list *valist);
int		printf_output(t_flist *flist);
t_flist	*flist_create(char *format, char *output);
//void	flist_push(t_flist *node);
void	flist_push(t_flist **head, t_flist *node);

//format handlers:
char	*apply_format_int(char *format, int arg);
char	*apply_format_str(char *format, char *arg);
char	*apply_format_char(char *format, char arg);//todo other formats
#endif
