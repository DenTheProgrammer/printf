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
//
long long apply_length(char *format, va_list *valist);
unsigned long long apply_length_uns(char *format, va_list *valist);
void	apply_precision(char *str, char *format);
//format handlers:
char	*apply_format_int(char *format, va_list *valist);
char	*apply_format_str(char *format, va_list *valist);
char	*apply_format_char(char *format, va_list *valist);//todo other formats
char	*apply_format_oct(char *format, va_list *valist);
char	*apply_format_hex(char *format, va_list *valist);
char	*apply_format_ptr(char *format, va_list *valist);
char	*apply_format_uns(char *format, va_list *valist);

//error
int		throw_error(char *msg);
#endif