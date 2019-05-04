//
// Created by Maybell Debbi on 2019-05-03.
//

#include "printf.h"

//void flist_push(t_flist *node)
//{
//	static t_flist *last_node = NULL;
//
//	if (last_node)
//		last_node->next = node;
//	last_node = node;
//}

void flist_push(t_flist **head, t_flist *node)
{
	t_flist *tmp;

	if (!*head)
		*head = node;
	else
	{
		tmp = *head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
	}
}

t_flist *flist_create(char *format, char *output)
{
	t_flist *new;

	new = (t_flist*)malloc(sizeof(t_flist));
	new->format = format;
	new->output = output;
	new->next = NULL;
	return (new);
}