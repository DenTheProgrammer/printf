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
long long apply_length(char *format, va_list *valist);
unsigned long long apply_length_uns(char *format, va_list *valist);
//void	apply_precision(char *str, char *format);
int get_precision_float(char *format);
void apply_width(t_flist *flist);
//char get_flag(t_flist *flist);
void	apply_precision_str(char *str, char *format);
void apply_flags(t_flist *flist);
//format handlers:
char	*apply_format_int(char *format, va_list *valist);
char	*apply_format_str(char *format, va_list *valist);
char	*apply_format_char(char *format, va_list *valist);
char	*apply_format_oct(char *format, va_list *valist);
char	*apply_format_hex(char *format, va_list *valist);
char	*apply_format_ptr(char *format, va_list *valist);
char	*apply_format_uns(char *format, va_list *valist);
char	*apply_format_float(char *format, va_list *valist);

//error
int		throw_error(char *msg);
#endif
