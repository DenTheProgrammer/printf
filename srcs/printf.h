//
// Created by den on 03.05.19.
//

#ifndef PRINTF_PRINTF_H
# define PRINTF_PRINTF_H
# define ARR_SIZE 100
# define BASE 10
# define FIRST_BIT_M (unsigned long)1 << 63u
# include "libft.h"
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

typedef	struct	s_formlfb
{
	unsigned long int mantisa : 64;
	unsigned long int exponent : 15;
	unsigned long int sign : 1;
}				t_formlfb;

typedef	union	s_form_lf
{
	long double	f;
	t_formlfb	bytes;
}				t_form_lf;

typedef	struct	s_wholenumb
{
	int			*whole;
	int			*fract;
	char		sign;
	long		wh_b;
	long		fr_b;
	char		*res;
}				t_wholenumb;

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
void	apply_format_percent(t_flist *flist, va_list *valist);//kek
int				*addit(int *a, int *b);
int				*power(int nb, int power, int *res);
int				*mult(int *a, int b);
char			*print_f(long double var, t_flist *flist);
int				*work_fract(int exp, t_wholenumb *n, t_flist *flist, int sign);
int				*work_whole(int exp, long wh_b, int *whole);
char			*print_float(long double var, t_flist *flist);
char			*parse_result(t_wholenumb *n, t_flist *flist);

//error
int		throw_error(char *msg);
#endif
