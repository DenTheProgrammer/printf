//
// Created by den on 03.05.19.
//

#ifndef PRINTF_PRINTF_H
# define PRINTF_PRINTF_H
# include "../libft/libft.h"
# include <stdio.h>//
# include <stdarg.h>

int		ft_printf(const char *str, ...);
typedef struct s_flist
{
	char				*format;
	int					parameter;
	char 				*flags;
	int					width;
	int 				precision;
	char 				*length;
	char 				type;
	char				*output;
	struct s_flist		*next;
} t_flist;

t_flist *parse_input(const char *str);
void	parse_formats(t_flist *flist);
void	apply_formats(t_flist *flist, va_list *valist);
int		printf_output(t_flist *flist);
t_flist	*flist_create(char *format, char *output);
//void	flist_push(t_flist *node);
void	flist_push(t_flist **head, t_flist *node);
//
long long apply_length(t_flist *flist, va_list *valist);
unsigned long long apply_length_uns(t_flist *flist, va_list *valist);

int get_precision_float(t_flist *flist);
void	apply_precision(t_flist *flist);
void apply_width(t_flist *flist);
//char get_flag(t_flist *flist);
void	apply_precision_str(t_flist *flist);
void apply_flags(t_flist *flist);
//format handlers:
void	apply_format_uns(t_flist *flist, va_list *valist);
void	apply_format_int(t_flist *flist, va_list *valist);
void	apply_format_str(t_flist *flist, va_list *valist);
void	apply_format_char(t_flist *flist, va_list *valist);
void	apply_format_oct(t_flist *flist, va_list *valist);
void	apply_format_hex(t_flist *flist, va_list *valist);
void	apply_format_ptr(t_flist *flist, va_list *valist);
void	apply_format_float(t_flist *flist, va_list *valist);

//error
int		throw_error(char *msg);
#endif
