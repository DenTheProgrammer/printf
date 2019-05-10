//
// Created by Maybell Debbi on 2019-05-06.
//

#include "printf.h"

//char get_flag(t_flist *flist)
//{
//	if (flist->format[1] == '#' || flist->format[1] == '0' || flist->format[1] == '-' ||
//		flist->format[1] == '+' || flist->format[1] == ' ')
//		return (flist->format[1]);
//	return (0);
//}

void apply_flag_minus(t_flist *flist)
{
	int width = ft_atoi(flist->format + 2);
	int outlen = ft_strlen(flist->output);
	char *output = ft_strdup(flist->output);

	if (width > outlen)
	{
		free(flist->output);
		flist->output = ft_strnew(width);
		ft_strcpy(flist->output, output);
		while (width - outlen)
			flist->output[outlen++] = ' ';
	}
}

void apply_flag_hash(t_flist *flist)
{
//	char *tmp_out;

//	tmp_out = ft_strdup(flist->output);
//	free(flist->output);
	if (ft_strchr(flist->format, 'o'))
		ft_strcpynoendl(flist->output, "0");
	else if (ft_strchr(flist->format, 'x'))
		ft_strcpynoendl(flist->output, "0x");
	else if (ft_strchr(flist->format, 'X'))
		ft_strcpynoendl(flist->output, "0X");
//	else
//		flist->output = ft_strdup(tmp_out);
//	free(tmp_out);
}

void apply_flags(t_flist *flist)
{
	if (ft_strchr(flist->flags, '+') && flist->output[0] != '-')
		ft_strcpynoendl(flist->output, "+");
	if (ft_strchr(flist->flags, ' ') && flist->output[0] != '-')
		flist->output = ft_strjoin(" ", flist->output);
	if (ft_strchr(flist->flags, '-'))
		apply_flag_minus(flist);
	if (ft_strchr(flist->flags, '#'))
		apply_flag_hash(flist);
}