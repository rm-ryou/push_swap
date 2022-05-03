#include "../../includes/push_swap.h"

void	rra(t_info *info)
{
	t_dlist	*node;

	node = info->a->prev;
	node_erase(info->a->prev);
	node_insert(info->a, node);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_info *info)
{
	t_dlist	*node;

	node = info->b->prev;
	node_erase(info->b->prev);
	node_insert(info->b, node);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_info *info)
{
	t_dlist	*node_a;
	t_dlist	*node_b;

	node_a = info->a->prev;
	node_b = info->b->prev;
	node_erase(info->a->prev);
	node_erase(info->b->prev);
	node_insert(info->a, node_a);
	node_insert(info->b, node_b);
	ft_putstr_fd("rrr\n", 1);
}
