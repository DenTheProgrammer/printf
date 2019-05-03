//
// Created by den on 03.05.19.
//

#ifndef PRINTF_PRINTF_H
# define PRINTF_PRINTF_H

typedef struct s_flist
{
	char				*format;
	void				*argument;
	char				*output;
	struct s_flist		*next;
} t_flist;

#endif //PRINTF_PRINTF_H
