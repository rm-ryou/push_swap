#include "../include/push_swap.h"

bool	sorted(t_dlist *list)
{
	t_dlist	*node_cur;

	node_cur = list->next;
	while (node_cur->next != list)
	{
		if (node_cur->index > node_cur->next->index)
			return (false);
		node_cur = node_cur->next;
	}
	return (true);
}

bool	sorted_re(t_dlist *list)
{
	t_dlist	*node_cur;

	node_cur = list->next;
	while (node_cur != list)
	{
		if (node_cur->index < node_cur->next->index)
			return (false);
		node_cur = node_cur->next;
	}
	return (true);
}