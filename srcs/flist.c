//
// Created by Maybell Debbi on 2019-05-03.
//

#include "printf.h"

void flist_push(t_flist *node)
{
	static t_flist *last_node = NULL;

	if (last_node)
		last_node->next = node;
	last_node = node;
}

t_flist *flist_create(char *format, void *argument)
{
	t_flist *new;

	new = (t_flist*)malloc(sizeof(t_flist));
	new->format = format;
	new->argument = argument;
	new->output = NULL;//?
	new->next = NULL;
	return (new);
}