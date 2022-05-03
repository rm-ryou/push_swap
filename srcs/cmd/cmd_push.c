#include "../../includes/push_swap.h"

void	pa(t_info *info)
{
	t_dlist	*node;

	if (info->b->next == info->b)
		return ;
	node = info->b->next;
	node_erase(info->b->next);
	node_insert(info->a, node);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_info *info)
{
	t_dlist	*node;

	if (info->a->next == info->a)
		return ;
	node = info->a->next;
	node_erase(info->a->next);
	node_insert(info->b, node);
	ft_putstr_fd("pb\n", 1);
}
