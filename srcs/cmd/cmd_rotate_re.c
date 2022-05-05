#include "../../includes/push_swap.h"

void	rra(t_info *info)
{
	t_dlist	*node;

	node = info->a->prev;
	node_erase(info->a->prev);
	node_insert(info->a, node);
	if (info->log->prev->value == RRB)
	{
		info->log->prev->value = RRR;
		return ;
	}
	else
		node_insert(info->log->prev, list_new(RRA));
//	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_info *info)
{
	t_dlist	*node;

	node = info->b->prev;
	node_erase(info->b->prev);
	node_insert(info->b, node);
	if (info->log->prev->value == RRA)
	{
		info->log->prev->value = RRR;
		return ;
	}
	else
		node_insert(info->log->prev, list_new(RRB));
//	ft_putstr_fd("rrb\n", 1);
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
	node_insert(info->log->prev, list_new(RRR));
//	ft_putstr_fd("rrr\n", 1);
}
