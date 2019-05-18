//
// Created by Maybell Debbi on 2019-05-05.
//

#include "printf.h"

int get_precision_float(t_flist *flist)
{
	return (flist->precision < 0) ? 0 : flist->precision;//?
}

void	apply_precision_str(t_flist *flist)
{
	int prec;

	prec = (flist->precision < 0) ? ft_strlen(flist->output) : flist->precision;
	if (prec < ft_strlen(flist->output))
		flist->output[prec] = 0;
}

void	apply_precision(t_flist *flist)//normal??
{
	int is_signed;

	if (ft_strequ(flist->output, "0"))
		flist->flags = ft_str_removechar(flist->flags, '#');
	if (flist->precision >= 0)
		flist->flags = ft_str_removechar(flist->flags, '0');
	if (flist->precision == 0 && ft_strequ(flist->output, "0"))
	{
		free(flist->output);
		flist->output = ft_strdup("");
		if (flist->type != 'o')
			flist->flags = ft_str_removechar(flist->flags, '#');
		return ;
	}
	if (flist->type == 'd' || flist->type == 'i'  || flist->type == 'u')
	{
		is_signed = flist->output[0] == '-' ? 1 : 0;
		flist->output = ft_strinsert(flist->output, ft_str_generate(flist->precision - ft_strlen(flist->output) + is_signed, '0'), is_signed);
	} else if (flist->type == 's')
		apply_precision_str(flist);
	else if (flist->type == 'x' || flist->type == 'o' || flist->type == 'X')
		flist->output = ft_strinsert(flist->output, ft_str_generate(flist->precision - ft_strlen(flist->output), '0'), 0);
}