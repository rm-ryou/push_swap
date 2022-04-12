#include "../include/push_swap.h"

bool	sorted(t_dlist *list)
{
	t_dlist	*node_cur;
	t_dlist	*node_next;
	int		i;

	node_cur = list->next;
	node_next = list->next->next;
	i = 1;
	while (node_next != list)
	{
		if (node_cur->value > node_next->value)
			return (false);
		node_cur = node_cur->next;
		node_next = node_next->next;
	}
	return (true);
}