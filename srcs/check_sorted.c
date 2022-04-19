#include "../include/push_swap.h"

bool	sorted(t_dlist *list)
{
	t_dlist	*node_cur;
	int		i;

	node_cur = list->next;
	i = 1;
	while (node_cur != list)
	{
		if (node_cur->index != i)
			return (false);
		node_cur = node_cur->next;
		i += 1;
	}
	return (true);
}
