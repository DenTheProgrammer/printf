//
// Created by Maybell Debbi on 2019-05-06.
//

#include "printf.h"

static void apply_flag_plus(t_flist *flist)
{
	size_t nbrlen;
	char *tmp;

	nbrlen = ft_strlen(flist->output);
	if (ft_strchr(flist->flags, '0'))
	{
		tmp = ft_strjoin("+", ft_str_generate(flist->width - nbrlen - 1, '0'));
		flist->output = ft_strjoin(tmp, flist->output);//leak
	}
	else {
		tmp = ft_strjoin("+", flist->output);
		free(flist->output);
		flist->output = tmp;
	}
}

static void apply_flag_minus(t_flist *flist)
{
	int outlen = ft_strlen(flist->output);
	char *output = ft_strdup(flist->output);

	if (flist->width > outlen)
	{
		free(flist->output);
		flist->output = ft_strnew(flist->width);
		ft_strcpy(flist->output, output);
		while (flist->width - outlen)
			flist->output[outlen++] = ' ';
	}
}

void apply_flag_hash(t_flist *flist)
{
	char *tmp_out;

	tmp_out = ft_strdup(flist->output);
	free(flist->output);
	if (flist->type == 'o')
		flist->output = ft_strjoin("0", tmp_out);
	else if (flist->type == 'x')
		flist->output = ft_strjoin("0x", tmp_out);
	else if (flist->type == 'X')
		flist->output = ft_strjoin("0X", tmp_out);
	else
		flist->output = ft_strdup(tmp_out);
	free(tmp_out);
}

void apply_flags(t_flist *flist)
{
	if (flist->precision >= flist->width && flist->type != 's')//precision > width fix
	{
		flist->width = flist->precision;
		flist->flags = ft_str_removechar(flist->flags, '-');
		ft_strpushchar(&flist->flags, '0');
	}
	if (ft_strchr(flist->flags, '+') && flist->output[0] != '-')
		 apply_flag_plus(flist);
	if (ft_strchr(flist->flags, ' ') && flist->output[0] != '-')
		flist->output = ft_strjoin(" ", flist->output);
	if (ft_strchr(flist->flags, '-'))
		apply_flag_minus(flist);
	if (ft_strchr(flist->flags, '#'))
		apply_flag_hash(flist);
}