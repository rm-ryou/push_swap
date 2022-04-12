#include "../../include/push_swap.h"

t_info	*pa(t_info *info)
{
	t_dlist *a;
	t_dlist *b;
	t_dlist *node;

	a = info->a;
	b = info->b;
	if (b->next == b)
		return (info);
	node = b->next;
	b->next = node->next;
	node->next->prev = b;
	node_insert(a, node);
	info->log[info->turn] = 'p';
	return (info);
}

t_info	*pb(t_info *info)
{
	t_dlist *a;
	t_dlist *b;
	t_dlist *node;

	a = info->a;
	b = info->b;
	if (a->next == a)
		return (info);
	node = a->next;
	a->next = node->next;
	node->next->prev = a;
	node_insert(b, node);
	info->log[info->turn] = 'P';
	return (info);
}
